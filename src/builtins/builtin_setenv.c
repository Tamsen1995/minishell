/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:11:36 by tbui              #+#    #+#             */
/*   Updated: 2017/09/29 15:12:31 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** gets an argument array with name and value of an
** envv variable which is already present in the env list
** iterates to that variable and changes it
*/

void			change_env_var(char *name, char *value, t_shell *shell)
{
	t_env		*env_tmp;

	env_tmp = NULL;
	env_tmp = shell->env;
	if (!name)
		fatal("No name in (change_env_var)");
	if (!value)
		fatal("Value missing in (change_env_var)");
	while (env_tmp && ft_strcmp(env_tmp->name, name) != 0)
		env_tmp = env_tmp->next;
	if (!env_tmp)
		return ;
	ft_strfree(env_tmp->value);
	env_tmp->value = ft_strdup(value);
}

/*
** checks the arguments for the appropiate parameters
** goes on to allocate a new list element onto
** the end of the env vars list
** if the given variable already exists then it changes it in the envv list
*/

int				sh_setenv(char **args, t_shell *shell)
{
	t_env		*tmp_env;

	tmp_env = NULL;
	if (!args || !shell)
		fatal("Error: no args present in (sh_setenv)");
	tmp_env = shell->env;
	if (shell->argc == 1)
		return (sh_env(shell));
	else if (shell->argc > 3)
	{
		ft_putendl("minishell: Too many arguments");
		return (1);
	}
	while (tmp_env->next && ft_strcmp(tmp_env->name, args[1]) != 0)
		tmp_env = tmp_env->next;
	if (ft_strcmp(tmp_env->name, args[1]) == 0)
		change_env_var(args[1], args[2], shell);
	else
		ft_putenv(&shell->env, args[1], args[2]);
	return (1);
}
