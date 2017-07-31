#include "../includes/ft_sh.h"

// cd
int sh_cd(char **args)
{
    if (args[1] == NULL)
    {
        if (chdir("~/") != 0)
            fatal("sh_cd ERR:001");
    }
    else
    {
        if (chdir(args[1]) != 0)
            fatal("sh_cd ERR:001");
    }
    return (1);
}

// simply exits the process
int sh_exit(void)
{
    return (0);
}

// TODO
// implement all the different flags (echo man)
// For now only the output has been implemented
int sh_echo(char **args)
{
    // For now sh_echo only outputs
    // it doesn't handle any of echo's flags yet
    ft_putendl(args[1]);
    return (1);
}



// Gets a temp pointer of the list (environment)
// and iterates through it until the sought after
// name is found
void get_env_val(char *name, t_env *env)
{
    name = NULL; // TESTING
    env = NULL; // TESTING

}

// WIP setenv man
void sh_setenv()
{
    // first I need to find the place where all the
    // env variables are stored
    
    // Then I need to unset the variable of the name
    // IF it even exists

    // then allocate enough memory for the variable and its value
    // "=" and "\0"

    // and then set it with something similar to putenv


}