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
        if (execvp(args[0], args) == -1)
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
    ft_putendl(args[0]);


    return (1); // TESTING
}

// function that will either start a process or a builtin
int sh_execute(char **args)
{
    if (args[0] == NULL)
    {
        // There was an empty command
        return (1); 
    }
    if (check_builtins(args) == TRUE) 
        return exec_builtin(args); // TESTING
//    return sh_launch(args);

    return (1); // TESTING
}