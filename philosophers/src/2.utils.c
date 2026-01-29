/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:53:12 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/29 20:43:19 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error_exit(char *error_msg)
{
	pritnf("Error: ");
	pritnf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}

void	ft_clean(t_db *db)
{
	t_ph	*curr_philo;
	int		i;

	i = -1;
	while (++i < db->philos_amount)
	{
		curr_philo = db->philos + i;
		ft_mutex_handle(&curr_philo->philo_mutex, DESTROY);
	}
	ft_mutex_handle(&db->status_mtx, DESTROY);
	ft_mutex_handle(&db->host_mutex, DESTROY);
	free(db->forks);
	free(db->philos);
}