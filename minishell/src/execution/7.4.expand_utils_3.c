/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.4.expand_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:30:44 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/08 17:10:34 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_simple_str(t_shell *shell, char *str)
{
	int		i;
	t_exp	*curr;

	i = 0;
	curr = shell->expansion;
	while (str[i])
	{
		if (str[i] == '$')
		{
			handle_dollar_sign(shell, curr, &str[i]);
			i += get_var_len_expanded(&str[i]) + 1;
			curr->last_opt = 1;
		}
		else
		{
			curr->temp2 = get_unexpand_str(&str[i], curr->temp);
			free(curr->temp);
			curr->last_opt = 2;
			while (str[i] && str[i] != '$')
				i++;
		}
	}
	if (curr->last_opt == 1)
		return (return_and_free_temps(curr->temp));
	return (return_and_free_temps(curr->temp2));
}

char	*return_and_free_temps(char *str)
{
	char	*result;

	result = ft_strdup(str);
	free(str);
	return (result);
}
