/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.custom_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:32:10 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/29 20:45:57 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	custom usleep
	1) is round is still going?
*/
void	ft_custom_usleep(long given_time, t_db *db)
{
	long	start_time;
	long	passed_time;
	long	left_time;

	start_time = ft_get_time(MICROSECONDS); // get start time
	while ((ft_get_time(MICROSECONDS) - start_time) < given_time) // check if already slep amount provided
	{
		// 1) if round is finished
		if (ft_round_finished(db) == true)
			break ;
		passed_time = ft_get_time(MICROSECONDS) - start_time;
		left_time = given_time - passed_time;

		// to get a spinlock limit
		if (left_time > 1000)
			usleep(left_time / 2);
		else
		{
			// Spinlock
			while ((ft_get_time(MICROSECONDS) - start_time) < given_time)
				;
		}
	}
}

