/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.round_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:34:52 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/28 22:42:43 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

	if (db->meals_limit <= 0)
		ft_error_exit("Min amount of meals is 1");
	if (db->philos_amount <= 1)
		; // TODO
	i = -1;
	while (++i < db->philos_amount)
		ft_thread_handle(&db->philos[i].thread_id, ft_round_run,
						&db->philos[i], CREATE);
	
	// prepare start time of the round
	db->round_start = ft_get_time(MILLISECONDS);
	
	// now all threads are ready
	ft_set_bool(&db->host_mutex, &db->all_phs_ready, true);  // safely accessing host_mutex and settting bool as ready
	
	// wait for everyone to be done
	i = -1;
	while (++i < db->philos_amount)
		ft_thread_handle(&db->philos[i].thread_id, NULL, NULL, JOIN);

	// if we passed here, all phills are full

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