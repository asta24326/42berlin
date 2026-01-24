/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.3.expand_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:50:52 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/08 17:10:52 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_get_var_name_len(char *arg)
{
	size_t	len;

	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	return (len);
}

bool	ft_is_valid_var_char(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

int	get_var_len_expanded(char *str)
{
	int		len;

	len = 1;
	if (str[len] == '$' || str[len] == '?')
		return (1);
	else
		while (str[len] && !is_whitespace(str[len]) 
			&& (str[len] != '$') && !is_quote(str[len]))
			len++;
	return (len - 1);
}

void	handle_dollar_sign(t_shell *shell, t_exp *curr, char *str)
{
	if (curr->last_opt == 1)
		curr->temp = get_expand_str(shell, str, curr->temp, 1);
	else
	{
		curr->temp = get_expand_str(shell, str, curr->temp2, 2);
		free(curr->temp2);
	}
}
