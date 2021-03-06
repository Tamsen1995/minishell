/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bin_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:55:06 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 19:28:56 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** takes in the value of the PATH variable
** and iterates over all the folders contained in it
** to check for the binary sought after
** if there returns true
*/

T_BOOL			check_bin_dirs(t_shell *shell)
{
	char	**bin_dirs;
	int		i;

	i = 0;
	bin_dirs = NULL;
	if (!shell || !shell->path_var)
		return (FALSE);
	bin_dirs = ft_strsplit(shell->path_var, ':');
	while (bin_dirs[i])
	{
		if (check_directory(bin_dirs[i], shell->cmds->args[0]) == TRUE)
		{
			if (shell->bin_dir)
				ft_strfree(shell->bin_dir);
			shell->bin_dir = ft_strdup(bin_dirs[i]);
			free_twod_arr(bin_dirs);
			return (TRUE);
		}
		i++;
	}
	free_twod_arr(bin_dirs);
	return (FALSE);
}

/*
** This is going to receive the PATH variable and check every
** directory within the path variable for a potential exec binary
** if the potential command is matched with a binary within one of
** PATH's folders. then return TRUE and execute it in parent function
*/

T_BOOL			check_bin_cmd(t_shell *shell)
{
	char		*potential_cmd;
	T_BOOL		bin_cmd_present;

	potential_cmd = NULL;
	bin_cmd_present = FALSE;
	get_path_var(shell);
	bin_cmd_present = check_bin_dirs(shell);
	ft_strfree(shell->path_var);
	return (bin_cmd_present);
}
