/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.4.exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:15:04 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/02 23:24:26 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	ft_is_valid_exit_arg(t_cmd *cmd);
static bool	ft_is_numeric_str(char *arg);
static long	ft_get_exit_code(char *arg);

int	ft_exit(t_shell *shell, t_cmd *cmd)
{
	long	exit_code;

	ft_putstr_fd("exit\n", 1);
	if (!cmd->args[1])
		ft_cleanup_and_exit(shell, 0);
	if (cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		shell->exit_status = 1;
		return (FAILURE);
	}
	if (ft_is_valid_exit_arg(cmd) == false)
		ft_cleanup_and_exit(shell, 2);
	exit_code = ft_get_exit_code(cmd->args[1]);
	ft_cleanup_and_exit(shell, (int)exit_code);
	return (SUCCESS);
}

static bool	ft_is_valid_exit_arg(t_cmd *cmd)
{
	if (ft_is_numeric_str(cmd->args[1]) == false)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (false);
	}
	return (true);
}

static bool	ft_is_numeric_str(char *arg)
{
	int	i;
	int	has_digit;

	if (!arg || !arg[0])
		return (false);
	i = 0;
	has_digit = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] == '\'' || arg[i] == '"')
		{
			i++;
			continue ;
		}
		if (arg[i] < '0' || arg[i] > '9')
			return (false);
		has_digit = 1;
		i++;
	}
	return (has_digit == 1);
}

static long	ft_get_exit_code(char *arg)
{
	long	l_nbr;
	int		i;
	int		sign;

	l_nbr = 0;
	i = 0;
	sign = 1;
	if (arg[i] == '-')
		sign = -1;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] != '\'' && arg[i] != '"' && arg[i] >= 0 && arg[i] <= '9')
			l_nbr = l_nbr * 10 + (arg[i] - '0');
		i++;
	}
	l_nbr = l_nbr * sign;
	l_nbr = l_nbr % 256;
	if (l_nbr < 0)
		l_nbr += 256;
	return ((int)l_nbr);
}
