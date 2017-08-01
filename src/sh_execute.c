#include "../includes/ft_sh.h"

// a function which will print an error msg and then exit the program
void fatal(char *err_msg)
{
    ft_putendl(err_msg);
    //exit (-1);
}


/*
** if the pid is a zero, we assume it to be
** the child process
*/

int         sh_launch(char **args, char **envv)
{
    pid_t pid;
    pid_t wpid;
    int status;
    char *command;

    // fork program and save the return
    command = args[0];
    pid = fork();
    if (check_bin_cmd(args[0]) == TRUE) // binary commands
        command = ft_strjoin(BIN, args[0]); // TODO free binary string command
    if (pid == 0)
    {
        // executing the sought after program
        if (execve(command, args, envv) == -1) // Change to execve later
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



// TODO implement all the builtins
// simply checks the argument array for
// a builtin command
T_BOOL check_builtins(char **args)
{
    if (ft_strcmp(args[0], "echo") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "cd") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "setenv") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "unsetenv") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "env") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "exit") == 0)
        return (TRUE);
    return (FALSE);
}

// redirects the flow to the appropiate
// builtin
// returns whatever the builtin returns
int exec_builtin(char **args, t_shell *shell)
{
    // Just output the command for now
    if (ft_strcmp(args[0], "echo") == 0) // WIP
        return (sh_echo(args));
    if (ft_strcmp(args[0], "cd") == 0) // DONE ?
        return (sh_cd(args,shell));
    if (ft_strcmp(args[0], "setenv") == 0)
        return (1);
    if (ft_strcmp(args[0], "unsetenv") == 0)
        return (1);
    if (ft_strcmp(args[0], "env") == 0)
        return (1);
    if (ft_strcmp(args[0], "exit") == 0) // DONE
        return (sh_exit());
    fatal("Error in exec_builtin: builtin recognized, but flow not properly redirected");
    return (0);
}

// function that will either start a process or a builtin
int sh_execute(char **args, char **envv, t_shell *shell)
{        
    // There was an empty command
    if (!args || !args[0])
        return (1);
    if (check_builtins(args) == TRUE) 
        return (exec_builtin(args, shell)); // WIP
    return (sh_launch(args, envv));
}