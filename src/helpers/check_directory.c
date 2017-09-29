/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:50:02 by tbui              #+#    #+#             */
/*   Updated: 2017/09/29 17:51:37 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** receives a directory path
** and checks the directory for
** sought after filename
*/

T_BOOL				check_directory(char *dir_path, char *file)
{
	DIR				*dir;
	struct dirent	*ent;

	dir = NULL;
	ent = NULL;
	if (!(dir = opendir(dir_path)))
		fatal("Could not open directory in (check_directory)");
	if (!dir_path || !file)
		fatal("Error in (check_directory)");
	while ((ent = readdir(dir)))
	{
		if (ft_strcmp(ent->d_name, file) == 0)
		{
			closedir(dir);
			return (TRUE);
		}
	}
	closedir(dir);
	return (FALSE);
}
