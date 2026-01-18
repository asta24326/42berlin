/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1.handle_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:04:39 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 19:31:47 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_strlen_clean(char *orig_str)
{
	int		len;
	char	quot_mark;

	len = 0;
	quot_mark = 0;
	while (*orig_str)
	{
		if (is_quote(*orig_str) && quot_mark == 0)
			quot_mark = *orig_str;
		else if (*orig_str == quot_mark)
			quot_mark = 0;
		else
			len++;
		orig_str++;
	}
	return (len);
}

char	*get_clean_str(char *orig_str)
{
	char	*clean_str;
	char	quot_mark;
	int		i;
	int		j;

	clean_str = (char *)malloc(get_strlen_clean(orig_str) + 1);
	if (!clean_str)
		return (perror("get_clean_str"), NULL);
	i = 0;
	j = 0;
	while (orig_str[i])
	{
		if (is_quote(orig_str[i]))
		{
			quot_mark = orig_str[i++];
			while (orig_str[i] != quot_mark)
				clean_str[j++] = orig_str[i++];
			i++;
		}
		else if (is_other(orig_str[i]) || is_redir(orig_str[i]))
			while (orig_str[i] && !is_quote(orig_str[i]))
				clean_str[j++] = orig_str[i++];
	}
	clean_str[j] = '\0';
	return (free(orig_str), clean_str);
}

int	cleanup_quotes(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (strchr(arr[i], '\'') || strchr(arr[i], '\"'))
		{
			arr[i] = get_clean_str(arr[i]);
			if (!arr[i])
				return (ft_free_arr(arr), FAILURE);
		}
	}
	return (SUCCESS);
}
