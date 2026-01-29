/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:14:27 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/29 20:57:33 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

/* 
	Main psudo code:
	./philo 5 800 200 200 [5 in total] 
*/

int main(int ac, char **av)
{
	t_db	database;
	
	if (ac == 5 || ac == 6) // check for correct input
	{
		ft_parse(&database, av);	// 1) parsing errors
		ft_db_init(&database);			// 2) Data allocation
		ft_round_start(&database);		// 3) Round handling
		ft_clean(&database);			// 4) clean function
	}
	else
		ft_error_exit("Wrong input\n Example: ./philo 5 400 200 200");
	return (0);
}
