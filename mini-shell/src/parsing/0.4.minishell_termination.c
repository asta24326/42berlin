/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.4.minishell_termination.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:28:14 by kschmitt          #+#    #+#             */
/*   Updated: 2025/12/28 12:34:05 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	end_minishell(t_shell *minishell)
{
	ft_cleanup_and_exit(minishell, minishell->exit_status);
}
