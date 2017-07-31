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

