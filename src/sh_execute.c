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
        // if waits for the status to end, either by exit
        // or signal et cetera
        wpid = waitpid(pid, &status, WUNTRACED);
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
            wpid = waitpid(pid, &status, WUNTRACED);
    }
    return (1);
}

// function that will either start a process or a builtin
int sh_execute(char **args)
{
    ft_putendl(args[0]); // HACKY / TESTING PURPOSES ONLY

    return (0);

}