#include "../includes/ft_sh.h"

T_BOOL      check_bin_cmd(char *potential_cmd)
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
