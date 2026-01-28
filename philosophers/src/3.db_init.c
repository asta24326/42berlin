/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.db_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:37:46 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/28 22:56:28 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_philo_init(t_db *db);
static void	ft_set_forks(t_db *db, t_ph *philo, t_fork *fork);

/* 
	psudo:

	what we need to allocate:
	1) round_start time?
	2) round stop flag
	3) array for forks
	4) array for philosophers
*/
void	ft_db_init(t_db *db)
{
	int	i;

	db->round_stop = false;
	db->all_phs_ready = false;
	ft_mutex_handle(&db->host_mutex, INIT);
	db->forks = malloc(sizeof(t_fork) * db->philos_amount);
	db->philos = malloc(sizeof(t_ph) * db->philos_amount);
	if (!db->forks || !db->philos)
		ft_error_exit("Malloc failed"); // TBD to handle cleaning after
		
	// intiialisaion of mutexes
	i = -1;
	while (++i < db->philos_amount)
	{
		ft_mutex_handle(&db->forks[i].fork, INIT);	// init of mutex(fork)
		db->forks[i].fork_id = i;					// setting index to it
	}
	ft_philo_init(db);
}

static void	ft_philo_init(t_db *db)
{
	t_ph	*curr_philo;
	int		i;

	i = -1;
	curr_philo = db->philos;
	while (++i < db->philos_amount)
	{
		curr_philo->ph_indx = i;
		curr_philo->ph_id = i + 1; 	// just for the name, cuz we start from #1
		curr_philo->meal_count = 0;
		curr_philo->is_full = false;
		// special function to assign forks
		ft_set_forks(db, curr_philo, db->forks);
		ft_mutex_handle(&curr_philo->philo_mutex, INIT);
		curr_philo->db = db;
		curr_philo++;				// moving to next pos in array of structs
	}
}

static void	ft_set_forks(t_db *db, t_ph *philo, t_fork *fork)
{
	int	amount;
	int	idx;

	idx = philo->ph_indx;
	amount = db->philos_amount;
	if (idx % 2 == 0) // if philo is even
	{
		philo->first_fork = &fork[(idx + 1) % amount];	// left fork
		philo->second_fork = &fork[idx];				// right fork
	}
	else
	{
		philo->first_fork = &fork[idx];
		philo->second_fork = &fork[(idx + 1) % amount];
	}
}
