/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.2.expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:31:01 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/08 17:10:29 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_env_var(t_shell *shell, char *str, int len)
{
	char	*var_name;
	char	*var_value;

	var_name = ft_substr(str, 1, len);
	if (!var_name)
		return (NULL);
	var_value = ft_getenv(shell->env, var_name);
	free(var_name);
	if (var_value)
		return (ft_strdup(var_value));
	else
		return (ft_strdup(""));
}

char	*get_expand_str(t_shell *shell, char *str, char *unexp_str, int flag)
{
	char	*result;
	char	*expanded_var;

	if (str[1] && (str[1] == ' ' || str[1] == '"'))
		expanded_var = ft_strdup("$");
	else if (str[1] && str[1] == '?')
		expanded_var = ft_itoa(shell->exit_status);
	else if (str[1] && str[1] == '$')
		expanded_var = ft_itoa(shell->shell_pid);
	else if (str[1] && ft_is_valid_var_char(str[1]))
		expanded_var = ft_expand_env_var(shell, str, get_var_len_expanded(str));
	else
		expanded_var = ft_strdup("");
	if (unexp_str != NULL)
	{
		result = ft_strjoin(unexp_str, expanded_var);
		if (flag == 1)
			free (unexp_str);
	}
	else
		result = ft_strdup(expanded_var);
	return (free(expanded_var), result);
}

char	*get_unexpand_str(char *str, char *exp_str)
{
	char	*result;
	char	*temp;
	int		index;

	index = 0;
	while (str[index] && str[index] != '"' && str[index] != '$')
		index++;
	temp = ft_substr(str, 0, index);
	if (exp_str && *exp_str)
		result = ft_strjoin(exp_str, temp);
	else
		result = ft_strdup(temp);
	return (free(temp), result);
}

char	*ft_expand_dquotes_str(t_shell *shell, char *str)
{
	int		i;
	t_exp	*curr;

	i = 1;
	curr = shell->expansion;
	while (str[i] && str[i] != '"')
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
			while (str[i] != '"' && str[i] != '$')
				i++;
		}
	}
	if (curr->last_opt == 1)
		return (ft_patch_with_dquotes(curr->temp));
	return (ft_patch_with_dquotes(curr->temp2));
}

char	*ft_patch_with_dquotes(char *str)
{
	char	*result;
	char	*temp;

	temp = ft_strjoin("\"", str);
	free(str);
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, "\"");
	if (!result)
		return (free(temp), NULL);
	free(temp);
	return (result);
}
