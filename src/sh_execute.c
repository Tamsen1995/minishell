#include "../includes/ft_sh.h"

// a function which will print an error msg and then exit the program
void fatal(char *err_msg)
{
    ft_putendl(err_msg);
    //exit (-1);
}

int sh_launch(char **args)
{
    pid_t pid;
    pid_t wpid;
    int status;

    // fork program and save the return
    pid = fork();
    // if the pid is a zero, we assume it to be
    // the child process
    if (pid == 0)
    {
        // executing the sought after program
        if (execvp(args[0], args) == -1) // Change to execve later
            fatal("sh_launch ERR:001");
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
int exec_builtin(char **args)
{
    // Just output the command for now
    if (ft_strcmp(args[0], "echo") == 0) // WIP
        return (sh_echo(args));
    if (ft_strcmp(args[0], "cd") == 0) // DONE ?
        return (sh_cd(args));
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
int sh_execute(char **args)
{        
    // There was an empty command
    if (args[0] == NULL)
        return (1); 
    if (check_builtins(args) == TRUE) 
        return exec_builtin(args); // WIP
    return sh_launch(args);
}