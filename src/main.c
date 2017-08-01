#include "../includes/ft_sh.h"

// the main loop of the program
// intialize a prompt for the user
// Read a command from the standard input
// Parse it, meaning we seperate the command into a program and a set of arguments
void sh_loop(t_shell *shell, char **envv)
{
    int status;
    char **args;
    char *line;

    status = 1;
    while (status == 1) 
    {
        ft_putstr("tamshell$> ");
        get_next_line(0, &line); // waiting for the input
        args = ft_strsplit(line, ' '); // splitting the input into commands and parameters
        status = sh_execute(args, envv, shell);
    }
    // TODO free args
}

int         main(int ac, char **av, char **envv)
{
    t_shell *shell;

    shell = NULL;
    shell = init_shell(ac, av, envv); // Initiating the shell
    sh_loop(shell, envv);  // the programs main loop
    // TODO free shell
    return (0);
}


// Execute and run the parsed command
    // seperate processes and builtins
    // a process will imply a child an process being split from its parent
    // and then running seperately

    // a builtin will be a command within the shell itself
