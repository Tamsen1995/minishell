/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:36:17 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 16:37:06 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** Takes in an env_var and frees it
*/

void		free_env_var(t_env *env_var)
{
	free(env_var->name);
	env_var->name = NULL;
	free(env_var->value);
	env_var->value = NULL;
	free(env_var);
	env_var = NULL;
}

/*
** Takes in the shell's environment and frees it
*/

void		free_env(t_env *env)
{
	t_env *tmp;

	tmp = NULL;
	tmp = env;
	if (!env)
		fatal("Error in (free_env)");
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->prev)
	{
		tmp = tmp->prev;
		free_env_var(tmp->next);
	}
	free_env_var(tmp);
}

/*
** frees the argument variables of the shell
*/

void		free_args(t_shell *shell)
{
	int i;

	i = 0;
	if (!shell)
		fatal("Error in (free_args)");
	while (shell->cmds->args[i])
	{
		free(shell->cmds->args[i]);
		i++;
	}
}

void		free_cmds(t_cmds *cmds)
{
	t_cmds *tmp;

	tmp = NULL;
	if (!cmds)
		fatal("Error (free_cmds)");
	tmp = cmds;
	while (tmp->next)
	{
		ft_putendl("\n\n\n\n");
		ft_putendl(tmp->args[0]);
		ft_putendl("\n\n\n\n"); // TESTING
		tmp = tmp->next;
	}
	while (tmp->prev)
	{
		tmp = tmp->prev;
		free_twod_arr(tmp->next->args);
		free(tmp->next);
	}
	free_twod_arr(tmp->args);
	free(tmp);
}

/*
** Takes in the shell and frees it
** implement more
*/

void		free_shell(t_shell *shell)
{
	if (!shell)
		fatal("No shell to be freed in (free_shell)");
	if (shell->env != NULL)
		free_env(shell->env);
	if (shell->bin_dir != NULL)
		ft_strfree(shell->bin_dir);
	if (shell->cmds)
		free_cmds(shell->cmds);
	free(shell);
	shell = NULL;
}
