/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.write_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:52:43 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/28 23:13:23 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_wrst_debug(t_status_opc status, t_ph *philo, long time);

/*
	output expected:
	[time_ms] [ph_id] [action]

	it should be thread safe
		status_mutex
*/

void	ft_write_status(t_status_opc status, t_ph *philo, bool debug)
{
	long	timestamp;

	timestamp = ft_get_time(MILLISECONDS);
	if (philo->is_full)
		return ;
	ft_mutex_handle(&philo->db->status_mtx, LOCK);

	if (debug)
		ft_wr_st_debug(status, philo, timestamp);
	else
	{
		if ((status == TAKES_FIRST_FORK || status == TAKES_SECOND_FORK)
				&& !ft_round_finished(philo->db))
			printf("%-6ld %d has taken a fork\n", timestamp, philo->ph_id);
		else if (status == EATING && !ft_round_finished(philo->db))
			printf("%-6ld %d is eating\n", timestamp, philo->ph_id);
		else if (status == SLEEPING && !ft_round_finished(philo->db))
			printf("%-6ld %d is sleeping\n", timestamp, philo->ph_id);
		else if (status == THINKING && !ft_round_finished(philo->db))
			printf("%-6ld %d is thinking\n", timestamp, philo->ph_id);
		else if (status == DIED && !ft_round_finished(philo->db))
			printf("%-6ld %d is died\n", timestamp, philo->ph_id);
	}
	ft_mutex_handle(&philo->db->status_mtx, UNLOCK);

}

// same as write but with additional info about fork index and meals index
static void	ft_wr_st_debug(t_status_opc status, t_ph *philo, long time)
{
	int 	ff_id;
	int 	sf_id;
	long	mls;
	
	ff_id = philo->first_fork->fork_id;
	sf_id = philo->second_fork->fork_id;
	mls = philo->meal_count;

	if (status == TAKES_FIRST_FORK && !ft_round_finished(philo->db))
		printf("%-6ld %d has taken fork[%d]\n", time, philo->ph_id, ff_id);
	else if (status == TAKES_SECOND_FORK && !ft_round_finished(philo->db))
		printf("%-6ld %d has taken fork[%d]\n", time, philo->ph_id, sf_id);
	else if (status == EATING && !ft_round_finished(philo->db))
			printf("%-6ld %d is eating meal[%ld]\n", time, philo->ph_id, mls);
	else if (status == SLEEPING && !ft_round_finished(philo->db))
			printf("%-6ld %d is sleeping\n", time, philo->ph_id);
	else if (status == THINKING && !ft_round_finished(philo->db))
			printf("%-6ld %d is thinking\n", time, philo->ph_id);
	else if (status == DIED && !ft_round_finished(philo->db))
			printf("%-6ld %d is died\n", time, philo->ph_id);
}

