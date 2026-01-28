/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.mutex_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:56:38 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/25 19:58:52 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_mutex_handle(t_mutex *mutex, t_mtx_opc opcode)
{
	if (LOCK == opcode)
		if (pthread_mutex_lock(mutex) != 0)
			ft_error_exit("Mutex lock failed");
	else if (UNLOCK == opcode)
		if (pthread_mutex_unlock(mutex) != 0)
			ft_error_exit("Mutex unlock failed");
	else if (INIT == opcode)
		if (pthread_mutex_init(mutex, NULL) != 0)
			ft_error_exit("Mutex init failed");
	else if (DESTROY == opcode)
		if (pthread_mutex_destroy(mutex) != 0)
			ft_error_exit("Mutex destroy failed");
	else
		ft_error_exit("Wrong opcode for mutex handle");
}
