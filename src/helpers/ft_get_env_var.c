/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:29:00 by tbui              #+#    #+#             */
/*   Updated: 2018/03/14 18:29:03 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** gets the shell and the name of an environment variable
** iterates through the env until it find said env variable
** env_var being the sought after variable
** can in some cases return null
*/

char		*get_env_var(t_shell *shell, char *name)
{
	t_env	*tmp;
	char	*env_var;

	tmp = NULL;
	tmp = shell->env;
	env_var = NULL;
	while (ft_strcmp(tmp->name, name) != 0 && tmp->next)
		tmp = tmp->next;
	if (ft_strcmp(tmp->name, name) == 0)
		env_var = ft_strdup(tmp->value);
	return (env_var);
}
