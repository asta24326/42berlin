/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.1.main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:34:19 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/06 13:46:57 by asharafe         ###   ########.fr       */
/*   Updated: 2026/01/06 13:51:27 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	*minishell;

	(void)ac;
	(void)av;
	minishell = (t_shell *)malloc(sizeof(t_shell));
	if (!minishell)
		return (ft_putstr_fd("shell memory allocation failed", 2), FAILURE);
	minishell->env = ft_env_dup(env);
	ft_setup_shlvl(minishell);
	if (!minishell->env)
		return (free(minishell), FAILURE);
	if (init_minishell(minishell) == FAILURE)
	{
		ft_free_arr_str(minishell->env);
		free(minishell);
		return (FAILURE);
	}
	shell_loop(minishell);
	end_minishell(minishell);
	return (SUCCESS);
}
