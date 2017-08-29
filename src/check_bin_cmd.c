#include "../includes/ft_sh.h"

/*
** takes in the value of the PATH variable
** and iterates over all the folders contained in it
** to check for the binary sought after
** if there returns true
*/

T_BOOL        check_bin_dirs(t_shell *shell)
{
    char **bin_dirs;
    int i;


    i = 0;
    bin_dirs = NULL;
    if (!shell || !shell->path_var)
        fatal("Error in (check_path_bin_dirs)");
    // split the PATH variable
    bin_dirs = ft_strsplit(shell->path_var, ':');
    while (bin_dirs[i])
    {
        if (check_directory(bin_dirs[i], shell->args[0]) == TRUE)
        {
            if (shell->bin_dir) // Whenever the bin_dir has already been allocated I have to free it before re-assigning it
            {
                free(shell->bin_dir);
                shell->bin_dir = NULL;
            }
            shell->bin_dir = ft_strdup(bin_dirs[i]);
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

/*
** This is going to receive the PATH variable and check every
** directory within the path variable for a potential exec binary
** if the potential command is matched with a binary within one of
** PATH's folders. then return TRUE and execute it in parent function
*/

T_BOOL      check_bin_cmd(t_shell *shell)
{
    char *potential_cmd;

    potential_cmd = NULL;
    // potential_cmd = shell->args[0];
    get_path_var(shell); // TODO free the path_var
    // This contains the VALUE of the PATH variable
    return(check_bin_dirs(shell));
}
