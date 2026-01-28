/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.threads_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:56:38 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/25 19:59:00 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*funct(void *arg);

void	ft_thread_handle(pthread_t *thread, void *(* func)(void *),
				void *data, t_thred_opc opcode)
{
	if (CREATE == opcode)
		if (pthread_create(thread, NULL, &funct, data) != 0)
			ft_error_exit("Thread create failed");
	else if (JOIN == opcode)
		if (pthread_join(thread, NULL) != 0)
			ft_error_exit("Thread join failed");
	else if (DETACH == opcode)
		if (pthread_detach(thread) != 0)
			ft_error_exit("Thread detach failed");
	else
		ft_error_exit("Wrong opcode for thread handle");
}
