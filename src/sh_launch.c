/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:41:33 by tbui              #+#    #+#             */
/*   Updated: 2017/09/29 11:41:37 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** Receives the directory in which the binary is in
** and concatenates it with the binary's name
** to make a path to be executed by execve
*/

char			*make_bin_cmd(t_shell *shell)
{
	char		*command;
	int			len_cmd;

	command = NULL;
	len_cmd = 0;
	if (!shell || !shell->bin_dir || !shell->args[0])
		fatal("Error in (make_bin_cmd)");
	len_cmd = ft_strlen(shell->bin_dir) + 1;
	len_cmd = len_cmd + ft_strlen(shell->args[0]);
	command = ft_strnew(len_cmd);
	command = ft_strcat(command, shell->bin_dir);
	command = ft_strcat(command, "/");
	command = ft_strcat(command, shell->args[0]);
	return (command);
}

/*
** simply a function which exists if the typed in
** command hasn't
** been found
*/

void			cmd_not_found(t_shell *shell)
{
	char *command;

	command = NULL;
	if (!shell || !shell->args[0])
		fatal("Error in (cmd_not_found");
	ft_putstr("tamshell: command not found: ");
	ft_putendl(shell->args[0]);
	free_twod_arr(shell->args);
	free_shell(shell);
	exit(-1);
}

/*
** if the pid is a zero, we assume it to be
** the child process
*/

int				sh_launch(char **envv, t_shell *shell)
{
	pid_t		pid;
	pid_t		wpid;
	int			status;
	char		*command;

	command = NULL;
	pid = fork();
	if (check_bin_cmd(shell) == TRUE)
		command = make_bin_cmd(shell);
	else if (check_bin_path(shell) == TRUE)
		command = ft_strdup(shell->args[0]);
	if (pid == 0)
	{
		if (execve(command, shell->args, envv) == -1)
			cmd_not_found(shell);
	}
	else if (pid < 0)
		fatal("sh_launch ERR:002");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	ft_strfree(command);
	return (1);
}
