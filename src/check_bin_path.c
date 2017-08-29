#include "../includes/ft_sh.h"

/*
** Checks to see if the command given
** is the path of a binary command
*/

T_BOOL      check_bin_path(t_shell *shell)
{
    if (!shell || !shell->args[0])
        fatal("Error in (check_bin_path)");

    // TODO finish


    return (TRUE); // TESTING
}