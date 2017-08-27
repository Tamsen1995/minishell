#include "../includes/ft_sh.h"

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
    command = shell->args[0];
    pid = fork();
    if (check_bin_cmd(shell) == TRUE)
        command = ft_strjoin(BIN, shell->args[0]); // TODO free binary string command
    if (pid == 0)
    {
        // executing the sought after program
        if (execve(command, shell->args, envv) == -1) // Change to execve later
            fatal("ERROR in child process (sh_launch)");
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

