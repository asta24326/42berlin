/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:05:38 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/29 20:32:35 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static long	ft_atol_philo(const char *nptr);

/* 
	Psudo
	input example:
	./philo 5   800   200   200     2   [ ac = 5(6) in total] 
		   [1]  [2]   [3]   [4]
		   		[time_to_die] milliseconds
					  [time_to_eat] milliseconds
					  		[time_to_sleep] milliseconds
								[number_of_times_each_philosopher_must_eat] - optional
	main points to check:
	1) numbers are not > INT_MAX
	2) timestamps > 60ms(milliseconds) for safety from system lags
*/
void ft_parse(t_db *database, char **av)
{
	database->philos_amount = ft_atol_philo(av[1]);
	if (database->philos_amount <= 1)
		ft_error_exit("Min amount of philos is 2");
	database->time_die = (ft_atol_philo(av[2]) * 1000);// converting MILLIseconds to MICROseconds for usleep later
	database->time_eat = (ft_atol_philol(av[3]) * 1000);
	database->time_sleep = (ft_atol_philo(av[4]) * 1000);
	if (database->time_die < (60 * 1000)
		|| database->time_eat < (60 * 1000)
		|| database->time_sleep < (60 * 1000)
		)
		ft_error_exit("Timestamps is less than 60ms");
	if (av[5] != NULL)
		database->meals_limit = ft_atol_philo(av[5]);
	else
		database->meals_limit = -1;
}

static long	ft_atol_philo(const char *nptr)
{
	int		i;
	long	result;
	int		len;
	
	i = 0;
	len = 0;
	result = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
		if (nptr[i++] == '-')
			ft_error_exit("Positive values only!");
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
		len++;
	}
	if (len > 10)
		ft_error_exit("Value is bigger than INT_MAX");
	return ((result));
}
