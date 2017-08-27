#include "../includes/ft_sh.h"


/*
** takes in the value of the PATH variable
** and iterates over all the folders contained in it
** to check for the binaries
*/

void        check_path_binaries(t_shell *shell)
{
    char **bin_dirs;
    int i;

    i = 0;
    bin_dirs = NULL;
    // split the PATH variable
    bin_dirs = ft_strsplit(shell->path_var, ':');
    while (bin_dirs[i])
    {
        // open each folder in it
        i++;
    }
 

    
    // iterate over all binaries in each one of them

}

/*
** Takes in the shell structure along with the environment
** extracts and returns the PATH variable's value
*/

char        *get_path_var(t_shell *shell)
{
    t_env *env_tmp;
    char *path_var;

    env_tmp = NULL;
    path_var = NULL;
    env_tmp = shell->env;
    while (ft_strcmp("PATH", env_tmp->name) != 0 && env_tmp)
        env_tmp = env_tmp->next;
    path_var = ft_strdup(env_tmp->value);
    return (path_var);
    // The value of the PATH var
}