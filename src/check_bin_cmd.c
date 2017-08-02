#include "../includes/ft_sh.h"

/*
** More binaries are going to be implemented later on (maybe)
*/

T_BOOL      check_bin_cmd(char *potential_cmd)
{
    if (ft_strcmp(potential_cmd, "ls") == 0)
        return (TRUE);
    return (FALSE);
}
