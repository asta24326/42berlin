/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.round.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:34:52 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/29 20:37:54 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

ft_round_monitor;

/*
	./philo 5 800 200 200 [5]

	to chek before:
	1) if meals == 0
	2) if philos > 1
	3) create philos(threads)
	4) synchronisation of philos
	5) join all of them back
*/
void	ft_round_init(t_db *db)
{
	int	i;

	i = -1;
	if (db->meals_limit <= 0)
		ft_error_exit("Min amount of meals is 1");
	else if (db->philos_amount <= 1)
		ft_thread_handle(&db->philos[0].thread_id, ft_solo_philo,
			&db->philos[0], CREATE); // TODO
	else
	{
		while (++i < db->philos_amount)
			ft_thread_handle(&db->philos[i].thread_id, ft_round_run,
							&db->philos[i], CREATE);
	}
	
	// monitor thread creation
	ft_thread_handle(db->monitor_thread, ft_round_monitor(), db, CREATE);

	// prepare start time of the round
	db->round_start = ft_get_time(MILLISECONDS);
	
	// now all threads are ready
	ft_set_bool(&db->host_mutex, &db->all_phs_ready, true);  // safely accessing host_mutex and settting bool as ready
	
	// wait for everyone to be done
	i = -1;
	while (++i < db->philos_amount)
		ft_thread_handle(&db->philos[i].thread_id, NULL, NULL, JOIN);

	// if we passed here, all phills are full
	// so we can set round stop to true
	ft_set_bool(&db->host_mutex, db->round_stop, true);

	// join monitor
	ft_thread_handle(&db->monitor_thread, NULL, NULL, JOIN);

}

/*
	0) wait all philos to be ready
	1) endless loop philos
*/
// from ft_thread_handle(&db->philos[i].thread_id, ft_round_run,
//						&db->philos[i], CREATE);
// 	&db->philos[i] value of exact [i] philo is passed as [void *data]
void	*ft_round_run(void *data)
{
	t_ph	*philo;

	philo = (t_ph *)data;
	
	// spinlock
	ft_wait_all_philos(philo->db);

	// set time last meal time
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time,
			ft_get_time(MILLISECONDS));

	// sync with monitor
	// increase a db var counter with all the threads running
	ft_increase_long(&philo->db->host_mutex, &philo->db->phls_running_amnt);

	//set last_meal_time
	while (!ft_round_finished(philo->db))
	{
		// 1) am i full?
		if (philo->is_full) // TODO thread safe?
			break ;

		// 2) eating
		ft_eating(philo);	// TODO

		// 3) sleeping -> write_status & precise usleep
		ft_write_status(SLEEPING, philo, DEBUG_MODE);
		ft_custom_usleep(philo->db->time_sleep, philo->db);
		
		// 4) thinking
		ft_thinking(philo); // TODO
	}

	return (NULL);
}

bool	ft_round_finished(t_db *db)
{
	if (db->round_stop == true)
		return (true);
	return(false);
}

/*
	solo algorithm

	1) fake to lock the fork
	2) sleep until monitor will bust it
*/
void	ft_solo_philo(void *arg)
{
	t_ph	*philo;

	philo = (t_ph *)arg;
	ft_wait_all_philos(philo->db);
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time,
		ft_get_time(MILLISECONDS));
	ft_increase_long(&philo->db->host_mutex, &philo->db->phls_running_amnt);
	ft_write_status(TAKES_FIRST_FORK, philo, DEBUG_MODE);
	while (!ft_round_finished(philo->db))
		usleep(200);
}