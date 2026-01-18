/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.3.signal_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:18:03 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/06 13:52:43 by kschmitt         ###   ########.fr       */
/*   Updated: 2026/01/06 12:00:49 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

volatile sig_atomic_t	g_signal_num = 0;

void	ft_signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_signal_num = SIGINT;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_setup_signals(void)
{
	g_signal_num = 0;
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signal_handler_for_parent(int signum)
{
	if (signum == SIGINT)
	{
		g_signal_num = SIGINT;
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_handle_child_status(t_shell *shell, int status)
{
	int	sig;

	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
			shell->exit_status = 130;
		else if (sig == SIGQUIT)
			shell->exit_status = 131;
		else if (WTERMSIG(status) == SIGPIPE)
			shell->exit_status = 0;
	}
}

void	ft_reset_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
