/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.get_set_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:07:28 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/25 19:27:31 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_set_bool(t_mutex *mutex, bool *curr_value, bool new_value);
bool	ft_get_bool(t_mutex *mutex, bool *curr_value);
void	ft_set_long(t_mutex *mutex, long *curr_value, long new_value);
long	ft_get_long(t_mutex *mutex, long *curr_value);

/*
	Module contatinign setters_getters
	to avoid writitng LOCK UNLOCK everywhere
*/
bool	ft_round_finished(t_db *db)
{
	return (ft_get_bool(&db->host_mutex, &db->round_stop));
}

// BOOL
void	ft_set_bool(t_mutex *mutex, bool *curr_value, bool new_value)
{
	ft_mutex_handle(mutex, LOCK); 
	*curr_value = new_value;
	ft_mutex_handle(mutex, UNLOCK);
}

bool	ft_get_bool(t_mutex *mutex, bool *curr_value)
{
	bool	result;
	
	ft_mutex_handle(mutex, LOCK);
	// READING thread
	result = *curr_value;
	ft_mutex_handle(mutex, UNLOCK);
	return (result);
}

// LONG
void	ft_set_long(t_mutex *mutex, long *curr_value, long new_value)
{
	ft_mutex_handle(mutex, LOCK); 
	*curr_value = new_value;
	ft_mutex_handle(mutex, UNLOCK);
}

// GET BOOL
long	ft_get_long(t_mutex *mutex, long *curr_value)
{
	bool	result;
	
	ft_mutex_handle(mutex, LOCK);
	// READING thread
	result = *curr_value;
	ft_mutex_handle(mutex, UNLOCK);
	return (result);
}




