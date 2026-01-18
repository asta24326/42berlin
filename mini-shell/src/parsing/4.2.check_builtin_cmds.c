/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2.check_builtin_cmds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:25:08 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:50:01 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin_cmd(t_cmd *cmd)
{
	char	*str;

	str = cmd->args[0];
	if (!(ft_strcmp(str, "echo")) || !(ft_strcmp(str, "cd"))
		|| !(ft_strcmp(str, "pwd")) || !(ft_strcmp(str, "export"))
		|| !(ft_strcmp(str, "unset")) || !(ft_strcmp(str, "env"))
		|| !(ft_strcmp(str, "exit")))
		return (true);
	return (false);
}
