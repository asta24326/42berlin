/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.6.pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:46:37 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/12/28 13:31:03 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_shell *shell, t_cmd *cmd)
{
	char	*curr_dir;

	(void)shell;
	(void)cmd;
	curr_dir = getcwd(NULL, 0);
	if (curr_dir)
	{
		ft_putstr_fd(curr_dir, 1);
		ft_putstr_fd("\n", 1);
		free(curr_dir);
		return (SUCCESS);
	}
	else
		return (ft_putstr_fd("pwd", 2), FAILURE);
}
