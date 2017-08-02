#include "../../includes/ft_sh.h"

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

