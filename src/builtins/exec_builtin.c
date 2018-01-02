/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 11:03:12 by tbui              #+#    #+#             */
/*   Updated: 2017/12/10 11:03:17 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** redirects the flow to the appropiate
** builtin
** returns whatever the builtin returns
*/

int					exec_builtin(t_shell *shell)
{
	if (check_builtin_path(shell) == TRUE)
	{
		ft_strfree(shell->args[0]);
		shell->args[0] = builtin_cmd_from_path(shell);
	}
	if (ft_strcmp(shell->args[0], "echo") == 0)
		return (sh_echo(shell->args));
	if (ft_strcmp(shell->args[0], "cd") == 0)
		return (sh_cd(shell->args, shell));
	if (ft_strcmp(shell->args[0], "setenv") == 0)
		return (sh_setenv(shell->args, shell));
	if (ft_strcmp(shell->args[0], "unsetenv") == 0)
		return (sh_unsetenv(shell->args, shell));
	if (ft_strcmp(shell->args[0], "env") == 0)
		return (sh_env(shell));
	if (ft_strcmp(shell->args[0], "exit") == 0)
		return (sh_exit());
	fatal("Error in exec_builtin: builtin recognized, \
			but flow not properly redirected");
	return (0);
}
