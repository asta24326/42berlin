/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.1.1.heredoc_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:51:59 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/07 20:18:22 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_heredoc_child_process(t_shell *shell, t_hdoc *curr_hdoc);
static int	ft_heredoc_read_loop(t_shell *shell, t_hdoc *curr_hdoc);
static void	ft_write_heredoc_line(t_shell *shell, t_hdoc *curr_hdoc,
				char *line);

void	ft_process_all_heredocs(t_shell *shell)
{
	t_cmd	*curr_cmd;
	t_hdoc	*curr_hdoc;

	curr_cmd = shell->cmd;
	while (curr_cmd)
	{
		if (curr_cmd->redirs && curr_cmd->redirs->hdocs)
		{
			curr_hdoc = curr_cmd->redirs->hdocs;
			while (curr_hdoc)
			{
				ft_handle_heredoc(shell, curr_hdoc);
				curr_hdoc = curr_hdoc->next;
			}
		}
		curr_cmd = curr_cmd->next;
	}
}

int	ft_handle_heredoc(t_shell *shell, t_hdoc *curr_hdoc)
{
	pid_t	pid;
	int		status;

	if (!curr_hdoc || !curr_hdoc->hdoc_delim)
		return (SUCCESS);
	if (pipe(curr_hdoc->hdoc_fd) == -1)
		return (ft_putstr_fd("minishell: heredoc pipe failed", 2), FAILURE);
	pid = fork();
	if (pid < 0)
		return (ft_putstr_fd("minishell: heredoc fork failed", 2), FAILURE);
	if (pid == 0)
		exit(ft_heredoc_child_process(shell, curr_hdoc));
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		shell->exit_status = 130;
	close(curr_hdoc->hdoc_fd[1]);
	curr_hdoc->hdoc_fd[1] = -1;
	ft_setup_signals();
	return (SUCCESS);
}

static int	ft_heredoc_child_process(t_shell *shell, t_hdoc *curr_hdoc)
{
	ft_reset_signals();
	return (ft_heredoc_read_loop(shell, curr_hdoc));
}

static int	ft_heredoc_read_loop(t_shell *shell, t_hdoc *curr_hdoc)
{
	char	*line;
	char	*delim;

	delim = ft_get_delim(curr_hdoc->hdoc_delim);
	while (true)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putstr_fd("minishell: warning:", 2);
			ft_putstr_fd("heredoc delimeted by end-of-file\n", 2);
			break ;
		}
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		ft_write_heredoc_line(shell, curr_hdoc, line);
		free(line);
	}
	free(delim);
	close(curr_hdoc->hdoc_fd[1]);
	return (SUCCESS);
}

static void	ft_write_heredoc_line(t_shell *shell, t_hdoc *curr_hdoc, char *line)
{
	char	*expanded_line;

	if (curr_hdoc->hdoc_delim[0] != '\'' && curr_hdoc->hdoc_delim[0] != '\"')
	{
		expanded_line = ft_expand_heredoc_str(shell, line);
		if (expanded_line)
		{
			write(curr_hdoc->hdoc_fd[1], expanded_line,
				ft_strlen(expanded_line));
			free(expanded_line);
		}
	}
	else
		write(curr_hdoc->hdoc_fd[1], line, ft_strlen(line));
	write(curr_hdoc->hdoc_fd[1], "\n", 1);
}
