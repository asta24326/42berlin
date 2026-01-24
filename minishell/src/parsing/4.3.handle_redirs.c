/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.3.handle_redirs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:05:38 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:54:12 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_out_redir(t_shell *shell, char *filename, t_cmd *cmd, int op_count)
{
	int	fd;

	if (cmd->redirs->out_fd > 0)
		close(cmd->redirs->out_fd);
	if (op_count == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (op_count == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (free(filename), FAILURE);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(filename, 2);
		perror(" ");
		shell->exit_status = 1;
		return (free(filename), FAILURE);
	}
	cmd->redirs->out_fd = fd;
	return (free(filename), SUCCESS);
}

int	handle_infile(t_shell *shell, char *filename, t_cmd *cmd, int op_count)
{
	int	fd;

	fd = 0;
	if (cmd->redirs->in_fd > 0)
		close(cmd->redirs->in_fd);
	if (op_count == 1)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(filename, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			shell->exit_status = 1;
			return (free(filename), FAILURE);
		}
	}
	if (op_count == 2)
		fd = -1;
	cmd->redirs->in_fd = fd;
	return (free(filename), SUCCESS);
}

char	*get_filename(char *redir_str)
{
	int	skip;
	int	len;

	skip = 0;
	len = ft_strlen(redir_str);
	while (is_redir(redir_str[skip]) || is_whitespace(redir_str[skip]))
		skip++;
	return (ft_substr(redir_str, skip, len - skip));
}

int	process_redirs(t_shell *shell, t_cmd *cmd, char *rdr_str, char *filename)
{
	int	result;

	result = 0;
	if (rdr_str[0] == '>' && rdr_str[1] != '>')
		result = handle_out_redir(shell, filename, cmd, 1);
	else if (rdr_str[0] == '>' && rdr_str[1] == '>')
		result = handle_out_redir(shell, filename, cmd, 2);
	else if (rdr_str[0] == '<' && rdr_str[1] != '<')
		result = handle_infile(shell, filename, cmd, 1);
	else if (rdr_str[0] == '<' && rdr_str[1] == '<')
		result = handle_infile(shell, filename, cmd, 2);
	return (result);
}

int	handle_redirs(t_shell *shell, t_cmd *cmd)
{
	int		i;
	char	*filename;

	i = -1;
	while (cmd->redirs->list[++i])
	{
		filename = get_filename(cmd->redirs->list[i]);
		if (!filename)
			return (FAILURE);
		if (process_redirs(shell, cmd, cmd->redirs->list[i],
				filename) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
