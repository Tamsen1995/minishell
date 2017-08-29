#include "../includes/ft_sh.h"

/*
** Receives the directory in which the binary is in
** and concatenates it with the binary's name
** to make a path to be executed by execve
*/

char        *make_bin_cmd(t_shell *shell)
{
    char *command;
    int len_cmd;

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

void        cmd_not_found(t_shell *shell)
{
    char *command;

    command = NULL;
    if (!shell || !shell->args[0])
        fatal("Error in (cmd_not_found");
    ft_putstr("tamshell: command not found: ");
    ft_putendl(shell->args[0]);
    exit(-1);
}

/*
** if the pid is a zero, we assume it to be
** the child process
*/

int         sh_launch(char **envv, t_shell *shell)
{
    pid_t pid;
    pid_t wpid;
    int status;
    char *command;

    // fork program and save the return
    command = NULL;
    pid = fork();
    if (check_bin_cmd(shell) == TRUE)
        command = make_bin_cmd(shell); // TODO free the command
    else if (check_bin_path(shell) == TRUE)
        command = ft_strdup(shell->args[0]); // TODO free the command
    if (pid == 0)
    {
        // executing the sought after program
        if (execve(command, shell->args, envv) == -1) // Change to execve later
        {
            ft_strfree(command);
            cmd_not_found(shell); // TODO I might have to go free the shell here
        }
        
    }
    else if (pid < 0)
        fatal("sh_launch ERR:002");
    else
    {
        // this condition is meant for the parent process
        // it waits for the status to end, either by exit
        // or signal et cetera
        wpid = waitpid(pid, &status, WUNTRACED);
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
            wpid = waitpid(pid, &status, WUNTRACED);
    }
    return (1);
}

