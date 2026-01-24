/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.2.minishell_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:13:31 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/08 00:18:54 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_minishell(t_shell *minishell)
{
	minishell->prompt = ft_strjoin(getenv("USER"), "@croissant_minishell: ");
	if (!minishell->prompt)
		return (FAILURE);
	minishell->pipe_count = 0;
	minishell->pipes = NULL;
	minishell->cmd = NULL;
	minishell->exit_status = 0;
	minishell->shell_pid = getpid();
	minishell->orig_stdin = dup(STDIN_FILENO);
	minishell->orig_stdout = dup(STDOUT_FILENO);
	minishell->expansion = NULL;
	ft_setup_signals();
	return (SUCCESS);
}
