/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.3.parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:49:19 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/08 14:45:19 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_arg_len(char *str)
{
	int		len;

	len = 0;
	while (str[len] && !is_whitespace(str[len]) && !is_operator(str[len]))
	{
		if (is_quote(str[len]))
			len += get_arg_len_in_quotes(str + len);
		else
			len++;
	}
	return (len);
}

void	fill_args_arr(char *arg, t_cmd *cmd)
{
	static int	i;

	cmd->args[i] = arg;
	i++;
	if (i == cmd->args_count)
	{
		cmd->args[i] = NULL;
		i = 0;
	}
}

int	parse_cmd(char *cmd_str, t_cmd *cmd)
{
	int		index;
	char	*arg;

	index = get_arg_len(cmd_str);
	arg = ft_substr(cmd_str, 0, index);
	if (!arg)
		return (ft_putstr_fd("parse_cmd", 2), -1);
	fill_args_arr(arg, cmd);
	return (index);
}
