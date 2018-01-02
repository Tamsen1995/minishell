/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bin_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:24:22 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 16:26:58 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** Receives a (potential) file path and a directory path
** and checks to see if it matches with
** any of the file paths within the directory
** of the given directory path
** returns TRUE upon match
*/

T_BOOL			check_dir_paths(char *dir_path, char *file_path)
{
	DIR					*dir;
	struct dirent		*ent;
	char				*cmpd_path;

	dir = NULL;
	ent = NULL;
	cmpd_path = NULL;
	if (!dir_path || !file_path)
		fatal("Error in (check_dir_paths)");
	dir = safe_opendir(dir_path);
	while ((ent = readdir(dir)))
	{
		cmpd_path = make_file_path(dir_path, ent->d_name);
		if (ft_strcmp(cmpd_path, file_path) == 0)
		{
			free(cmpd_path);
			cmpd_path = NULL;
			closedir(dir);
			return (TRUE);
		}
		free(cmpd_path);
		cmpd_path = NULL;
	}
	closedir(dir);
	return (FALSE);
}

/*
** Checks to see if the command given
** is the path of a binary command
*/

T_BOOL			check_bin_path(t_shell *shell)
{
	char		**bin_dirs;
	int			i;

	i = 0;
	bin_dirs = NULL;
	if (!shell || !shell->args[0])
		fatal("Error in (check_bin_path)");
	get_path_var(shell);
	if (!shell->path_var)
		return (FALSE);
	bin_dirs = ft_strsplit(shell->path_var, ':');
	while (bin_dirs[i])
	{
		if (check_dir_paths(bin_dirs[i], shell->args[0]) == TRUE)
		{
			free_twod_arr(bin_dirs);
			ft_strfree(shell->path_var);
			return (TRUE);
		}
		i++;
	}
	free_twod_arr(bin_dirs);
	ft_strfree(shell->path_var);
	return (FALSE);
}
