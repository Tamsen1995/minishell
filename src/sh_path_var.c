#include "../includes/ft_sh.h"

/*
** Takes in the shell structure along with the environment
** extracts and returns the PATH variable's value
** putting it into the shell's env var value
*/

char        *get_path_var(t_shell *shell)
{
    t_env *env_tmp;
    char *path_var;

    env_tmp = NULL;
    path_var = NULL;
    if (!shell || !shell->env)
        fatal("Error in get_path_var");
    env_tmp = shell->env;
    while (ft_strcmp("PATH", env_tmp->name) != 0 && env_tmp)
        env_tmp = env_tmp->next;
    path_var = ft_strdup(env_tmp->value);
    return (path_var);
    // The value of the PATH var
}


