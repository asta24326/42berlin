/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.1.2.heredoc_handle_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:18:43 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/07 20:16:40 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_heredoc_str(t_shell *shell, char *str)
{
	if (!str)
		return (NULL);
	if (str[0] == '$')
		return (ft_expand_dollar_start(shell, str));
	return (ft_strdup(str));
}

char	*ft_get_delim(char *old_delim)
{
	char	*delim;
	size_t	len;

	len = ft_strlen(old_delim);
	if (old_delim[0] == '\'' || old_delim[0] == '"')
		delim = ft_substr(old_delim, 1, len - 2);
	else
		delim = ft_strdup(old_delim);
	return (delim);
}
