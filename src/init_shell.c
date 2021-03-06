/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:47:45 by tbui              #+#    #+#             */
/*   Updated: 2017/09/29 11:51:00 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** initiaing the shell and the data required for it
*/

t_shell				*init_shell(int ac, char **av, char **envv)
{
	t_shell *shell;

	shell = NULL;
	av = NULL;
	ac = 0;
	if (!(*envv) || !envv)
		fatal("No envirionment available");
	if (!(shell = (t_shell *)malloc(sizeof(t_shell))))
		fatal("Couldn't allocate shell in init_shell");
	shell->env = init_env(envv);
	shell->home_path = get_env_var(shell, "HOME");
	shell->argc = 0;
	shell->path_var = NULL;
	shell->bin_dir = NULL;
	shell->cmds = NULL;
	return (shell);
}
