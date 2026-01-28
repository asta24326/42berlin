/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.get_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:57:08 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/25 19:36:07 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	gettimeofday

	time-type -> SECONDS MILLISECONDS MICROSECONDS
	struct timeval 
	{
		time_t			tv_sec;		-> seconds starting from 1st Jan 1970
		suseconds_t		tv_usec;	-> microseconds (0-999'999)
	}
*/
long	ft_get_time(t_timecode time_type)
{
	struct	timeval	time_value;

	if (gettimeofday(&time_value, NULL))
		ft_error_exit("Gettimeofday failed");
	if (SECONDS == time_type)
		return (time_value.tv_sec + (time_value.tv_usec / 1000000));
	else if (MILLISECONDS == time_type)
		return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
	else if (MICROSECONDS == time_type)
		return ((time_value.tv_sec * 1000) + time_value.tv_usec);
	else
		ft_error_exit("Wrong input to gettime");
	return (-42);// just for fun - never het here
}

