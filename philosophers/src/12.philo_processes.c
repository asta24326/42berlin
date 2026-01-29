/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.philo_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:43:30 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/29 19:34:06 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	eating process:

	1.1) grab forks: first and second 
	1.2) write status about taking forks
	2) eat
		2.1) update last meal time
		2.2) write eat status
		2.3) update meals counter
		2.4) sleep for eating time
		2.5) check if philo is full
	3) release the forks
*/
void	ft_eating(t_ph *philo)
{
	// 1.1) grab first fork
	ft_mutex_handle(&philo->first_fork->fork, LOCK);
	// 1.2) write status
	ft_write_status(TAKES_FIRST_FORK, philo, DEBUG_MODE);
	// 1.1) grab second fork
	ft_mutex_handle(&philo->second_fork->fork, LOCK);
	// 1.2) write status
	ft_write_status(TAKES_SECOND_FORK, philo, DEBUG_MODE);

	// 2.1) update last meal time
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time, ft_get_time(MILLISECONDS));
	// 2.2) write eat status
	ft_write_status(EATING, philo, DEBUG_MODE);
	// 2.3) update meals counter
	philo->meal_count++;
	// 2.4) sleep for eating time
	ft_custom_usleep(philo->db->time_sleep, philo->db);
	// 2.5) check if philo is full
	if (philo->db->meals_limit > 0
		&& philo->meal_count == philo->db->meals_limit)
		ft_set_bool(&philo->philo_mutex, &philo->is_full, true); // setting it as full safely
	
	// 3) unlocking forks back
	ft_mutex_handle(&philo->first_fork->fork, UNLOCK);
	ft_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

/*
	thinking process:
	
*/
void	ft_thinking(t_ph *philo)
{
	ft_write_status(THINKING, philo, DEBUG_MODE);
}