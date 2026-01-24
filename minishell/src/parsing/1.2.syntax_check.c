/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.2.syntax_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:55:55 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/06 13:10:40 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_syntax_err_print(char *str)
{
	ft_putstr_fd("minishell: syntax error", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

int	are_valid_pipes(char *copy)
{
	int	flag;

	flag = 0;
	while (*copy)
	{
		if (is_quote(*copy) || is_redir(*copy) || is_other(*copy))
			flag = 1;
		else if (*copy == '|')
		{
			if (flag == 0)
				return (false);
			flag = 0;
		}
		copy++;
	}
	if (flag == 0)
		return (false);
	return (true);
}

int	are_valid_redirs(char *copy)
{
	int		i;

	i = -1;
	while (copy[++i])
	{
		if (is_redir(copy[i]))
		{
			i++;
			if (copy[i] == copy[i - 1])
				i++;
			while (is_whitespace(copy[i]))
				i++;
			while (is_quote(copy[i]))
				i++;
			if (!is_other(copy[i]) || !copy[i])
				return (false);
		}
	}
	return (true);
}

int	are_closed_quotes(char *copy)
{
	char	quot_mark;

	quot_mark = 0;
	while (*copy)
	{
		if (is_quote(*copy) & !quot_mark)
			quot_mark = *copy;
		else if (*copy == quot_mark)
			quot_mark = 0;
		copy++;
	}
	if (quot_mark == 0)
		return (true);
	return (false);
}

int	is_valid_syntax(char *copy, int pipe_count)
{
	if (pipe_count > 0)
		if (are_valid_pipes(copy) == false)
			return (ft_syntax_err_print(" unexpected token '|'"), false);
	if (are_valid_redirs(copy) == false)
		return (ft_syntax_err_print(" near unexpected token"), false);
	if (are_closed_quotes(copy) == false)
		return (ft_syntax_err_print(": unclosed quote"), false);
	return (true);
}
