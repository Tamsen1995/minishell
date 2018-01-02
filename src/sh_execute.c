/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:32:46 by tbui              #+#    #+#             */
/*   Updated: 2017/09/29 16:34:02 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** function that will either start a process or a builtin
*/

int				sh_execute(char **envv, t_shell *shell)
{
	if (!shell->args || !shell->args[0])
		return (1);
	if (check_builtins(shell->args[0]) == TRUE || \
			check_builtin_path(shell) == TRUE)
		return (exec_builtin(shell));
	return (sh_launch(envv, shell));
}
