#include "../includes/ft_sh.h"

void print_twod_arr(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        ft_putendl(args[i]);
        i++;
    }
}


// the main loop of the program
// intialize a prompt for the user
// Read a command from the standard input
// Parse it, meaning we seperate the command into a program and a set of arguments
void sh_loop(void)
{
    T_BOOL status;
    char **args;
    char *line;

    status = TRUE;
    while (status) 
    {
        ft_putstr("tamshell$> ");
        get_next_line(0, &line); // waiting for the input
        args = ft_strsplit(line, ' '); // splitting the input into commands and parameters
    //    status = sh_execute(args);
    
    }
}

int main(void)
{
    // starting the program
    sh_loop();
    return (0);
}


// Execute and run the parsed command
    // seperate processes and builtins
    // a process will imply a child an process being split from its parent
    // and then running seperately

    // a builtin will be a command within the shell itself
