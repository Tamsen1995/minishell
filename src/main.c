#include "../includes/ft_sh.h"

// the main loop of the program
// intialize a prompt for the user
// Read a command from the standard input
// Parse it, meaning we seperate the command into a program and a set of arguments

int         count_args(char **args)
{
    int argc;

    argc = 0;
    if (!args)
        return (0);
    while (args[argc])
        argc++;
    return (argc); // TODO test this function
}


// receives a buffer with potential tabs in it
// makes a copy of this buffer in which the tabs
// are replaced with spaces
char        *replace_tabs(char *buf)
{
    char *line;
    int i;

    i = 0;
    line = NULL;
    line = ft_strdup(buf);
    while (line[i])
    {
        if (line[i] == '\t')
            line [i] = ' ';
        i++;
    }
    return (line);
}

void        sh_loop(t_shell *shell, char **envv)
{
    int status;
    char *line;
    char *buf;

    status = 1;
    buf = NULL;
    line = NULL;
    while (status == 1) 
    {
        shell->args = NULL;
        ft_putstr("tamshell$> ");
        get_next_line(0, &buf); // waiting for the input
        line = replace_tabs(buf);
        shell->args = ft_strsplit(line, ' '); // splitting the input into commands and parameters
        shell->argc = count_args(shell->args);
        status = sh_execute(envv, shell);
        free(line);
        free_twod_arr(shell->args);
    }

}

// TESTING
void        testing_prev(t_env *env)
{
    t_env *tmp;

    tmp = env;
    while (tmp->next)
        tmp = tmp->next;
    while (tmp->prev)
    {
        ft_putendl(tmp->name);
        tmp = tmp->prev;
    }
}

int         main(int ac, char **av, char **envv)
{
    t_shell *shell;

    shell = NULL;
    shell = init_shell(ac, av, envv); // Initiating the shell
    //testing_prev(shell->env); // TESTING
    sh_loop(shell, envv);  // the programs main loop
    free_shell(shell);
    return (0);
}


// Execute and run the parsed command
    // seperate processes and builtins
    // a process will imply a child a process being split from its parent
    // and then running seperately

    // a builtin will be a command within the shell itself
