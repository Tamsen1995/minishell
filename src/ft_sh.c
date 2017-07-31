#include "../includes/ft_sh.h"

// the main loop of the program
// intialize a prompt for the user
// Read a command from the standard input
// Parse it, meaning we seperate the command into a program and a set of arguments
void sh_loop(void)
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
        status = sh_execute(args);
    }

    // TODO free args
}

// iterates to the end of the env list
// and then adds the value to it
t_env       *sh_putenv(char *name_value)
{
    // TODO implement this

    ft_putstr(name_value); // TESTING
    return (NULL); // TESTING
}

// initiaing the shell and the data required for it
t_shell     *init_shell()
{
    t_shell *shell;

    shell = NULL;
    if (!(shell = (t_shell *)malloc(sizeof(t_shell))))
        fatal("Couldn't allocate shell in init_shell");
    shell->env = sh_putenv("HOME=");

    return (NULL); // TESTING
}




void			print_twod(char **envv)
{
	int i;

	i = 0;
	while (envv[i])
	{
		ft_putendl(envv[i]);
		i++;
	}
}


int main(int ac, char **av, char **envv)
{
    t_shell *shell;

    shell = NULL;
    ac = 0;
    av = NULL;

	print_twod(envv);// TESTING


    shell = init_shell(); // Initiating the shell
    sh_loop();  // the programs main loop
    
    
    // TODO free shell
    return (0);


}


// Execute and run the parsed command
    // seperate processes and builtins
    // a process will imply a child an process being split from its parent
    // and then running seperately

    // a builtin will be a command within the shell itself
