#include "../includes/ft_sh.h"

/*
** This is going to receive the PATH variable and check every
** directory within the path variable for a potential exec binary
** if the potential command is matched with a binary within one of
** PATH's folders. then we execute it.
*/

T_BOOL      check_bin_cmd(t_shell *shell)
{
    char *potential_cmd;

    potential_cmd = NULL;
    // potential_cmd = shell->args[0];
    shell->path_var = get_path_var(shell); // TODO free the path_var
    // This contains the VALUE of the PATH variable

    check_path_binaries(shell);

    // find the path variable
    // check the folders in the path variable for the bin
    // for now just get the program to iterate over the bins
    // and print them



    ft_putendl(potential_cmd); // TESTING
    return (FALSE);
}
