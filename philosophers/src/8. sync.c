/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8. sync.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:45:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/25 18:54:48 by aidarsharaf      ###   ########.fr       */
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