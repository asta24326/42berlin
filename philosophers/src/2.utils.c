/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:53:12 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/25 17:33:48 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error_exit(char *error_msg)
{
	pritnf("Error: ");
	pritnf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}

void	ft_full_clean(t_db *db)
{
	while (db->forks)
}

void	ft_clean_forks(t_db *db, t_fork *forks)
{
	int	i;

	i = -1;
	while (++i < (db->philos_amount - 1))
	{
		if (forks[i]->fork)
	}
}