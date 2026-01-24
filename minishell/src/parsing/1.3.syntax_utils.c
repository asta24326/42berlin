/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.3.syntax_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:58:07 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:44:40 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_whitespace(char c)
{
	if (c == 32 || c == 9)
		return (true);
	return (false);
}

int	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (true);
	return (false);
}

int	is_redir(char c)
{
	if (c == '>' || c == '<')
		return (true);
	return (false);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

int	is_other(char c)
{
	if (is_whitespace(c) || is_operator(c) || is_quote(c))
		return (false);
	return (true);
}
