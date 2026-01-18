/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2.parse_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:57:38 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/05 12:47:19 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_arg_len_in_quotes(char *str)
{
	int		arg_len;
	int		flag;
	char	quot_mark;

	arg_len = 1;
	flag = 1;
	quot_mark = str[0];
	while (str[arg_len] && flag == 1)
	{
		if (str[arg_len] != quot_mark)
			arg_len++;
		else if (str[arg_len] == quot_mark)
		{
			if (is_whitespace(str[arg_len + 1]) || is_redir(str[arg_len + 1]))
				flag = 0;
			arg_len++;
		}
	}
	return (arg_len);
}

int	parse_quote(char *cmd_str, t_cmd *cmd)
{
	int		arg_len;
	char	*arg;

	arg_len = get_arg_len_in_quotes(cmd_str);
	arg = ft_substr(cmd_str, 0, arg_len);
	if (!arg)
		return (ft_putstr_fd("parse_quote", 2), -1);
	fill_args_arr(arg, cmd);
	return (arg_len);
}
