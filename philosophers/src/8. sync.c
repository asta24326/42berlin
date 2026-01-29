/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8. sync.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:45:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/29 20:05:31 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// basically we'll set all the philos in infinate loop
// till the flag db->allphs_ready is true
void	ft_wait_all_philos(t_db *db)
{
	// spin lock - buys while waiting
	while(!ft_get_bool(&db->host_mutex, &db->all_phs_ready))
		; // we're reading continuesly while all_phs_ready != true
}

/*
	Monitor in busy wait until all thread are running
*/
bool	ft_all_philos_running(t_mutex *mutex, long *threads, long philo_amount)
{
	bool	res;

	res = false;
	ft_mutex_handle(mutex, LOCK);
	if (*threads == philo_amount)
		res = true;
	ft_mutex_handle(mutex, UNLOCK);
	return (res);
}

void	ft_increase_long(t_mutex *mutex, long *value)
{
	ft_mutex_handle(mutex, LOCK);
	(*value)++;
	ft_mutex_handle(mutex, UNLOCK);
}
