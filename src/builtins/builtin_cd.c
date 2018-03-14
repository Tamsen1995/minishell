/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:01:05 by tbui              #+#    #+#             */
/*   Updated: 2018/03/14 18:27:17 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** iterates to the pwd to be updated. if it exists then it updates it.
** if not then it adds it to the list
*/

void		put_pwd(t_shell *shell, char *pwd)
{
	char		current_dir[BUF_SIZE];
	t_env		*tmp_env;

	tmp_env = NULL;
	ft_bzero(current_dir, BUF_SIZE);
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
		fatal("Error 2 in : (update_oldpwd)");
	tmp_env = shell->env;
	while (tmp_env->next && ft_strcmp(tmp_env->name, pwd) != 0)
		tmp_env = tmp_env->next;
	if (ft_strcmp(tmp_env->name, pwd) == 0)
		change_env_var(pwd, current_dir, shell);
	else
		ft_putenv(&shell->env, pwd, current_dir);
}

/*
** simply a function to update the oldpwd OR the PWD
** within the environment variable list
** sets the oldpwd / owd to the current working directory
*/

void		update_pwd(enum e_pwd pwd, t_shell *shell)
{
	if (!shell || !shell->env)
		fatal("Error 1 in : (update_oldpwd)");
	if (pwd == OLD)
		put_pwd(shell, "OLDPWD");
	if (pwd == CUR)
		put_pwd(shell, "PWD");
}

/*
** a safe wrapper around chdir
*/

void		safe_chdir(t_shell *shell, char *path)
{
	update_pwd(OLD, shell);
	if (!path)
		return ;
	if (chdir(path) != 0 && ft_strcmp(path, "-") != 0)
	{
		ft_putstr("My cd: No such file or directory: ");
		ft_putendl(path);
	}
}

/*
** A basic cd command
*/

int			sh_cd(char **args, t_shell *shell)
{
	char *oldpwd;

	oldpwd = NULL;
	if (!args || !shell)
		fatal("Error in : (sh_cd)");
	if (args[1] && ft_strcmp(args[1], "-") == 0)
	{
		oldpwd = get_env_var(shell, "OLDPWD");
		safe_chdir(shell, oldpwd);
	}
	if (args[1] == NULL)
		safe_chdir(shell, shell->home_path);
	else
		safe_chdir(shell, args[1]);
	update_pwd(CUR, shell);
	return (1);
}
