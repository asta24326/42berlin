/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.5.shell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:13:06 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/06 13:53:40 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_loop(t_shell *minishell)
{
	char	*input_str;

	while (true)
	{
		if (g_signal_num == SIGINT)
		{
			minishell->exit_status = 130;
			g_signal_num = 0;
		}
		input_str = readline(minishell->prompt);
		if (!input_str)
		{
			ft_putstr_fd("exit\n", 1);
			ft_cleanup_and_exit(minishell, minishell->exit_status);
			break ;
		}
		if (*input_str)
		{
			add_history(input_str);
			if (parse(input_str, minishell) == SUCCESS)
				ft_exec_cmds(minishell);
			ft_cleanup_after_cmd_exec(minishell);
		}
		free(input_str);
	}
}
