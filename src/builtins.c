#include "../includes/ft_sh.h"

// cd
int sh_cd(char **args)
{
    if (args[1] == NULL)
        fatal("tams_shell: expected argument to run cd");
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