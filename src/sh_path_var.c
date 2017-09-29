/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:32:33 by tbui              #+#    #+#             */
/*   Updated: 2017/09/29 12:32:36 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** Takes in the shell structure along with the environment
** extracts and returns the PATH variable's value
** putting it into the shell's env var value
*/

void			get_path_var(t_shell *shell)
{
	t_env		*env_tmp;

	env_tmp = NULL;
	if (!shell || !shell->env)
		fatal("Error in get_path_var");
	env_tmp = shell->env;
	while (env_tmp->next && ft_strcmp("PATH", env_tmp->name) != 0)
		env_tmp = env_tmp->next;
	if (ft_strcmp("PATH", env_tmp->name) == 0)
		shell->path_var = ft_strdup(env_tmp->value);
	else
		shell->path_var = NULL;
	return ;
}
