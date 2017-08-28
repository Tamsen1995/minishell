#include "../../includes/ft_sh.h"

char *get_home_path(t_shell *shell)
{
    t_env   *tmp;
    char    *home_path;

    tmp = NULL;
    tmp = shell->env;
    home_path = NULL;
    while (ft_strcmp(tmp->name, "HOME") != 0 && tmp)
        tmp = tmp->next;
    if (ft_strcmp(tmp->name, "HOME") == 0)
        home_path = ft_strdup(tmp->value);
    if (!home_path)
        fatal("Error in (get_home_path)");
    return (home_path);
}

/*
** A basic cd command
*/

int sh_cd(char **args, t_shell *shell)
{
    char *home_path;

    home_path = NULL;
    home_path = get_home_path(shell);
    if (args[1] == NULL)
    {
        if (chdir(home_path) != 0)
            fatal("Error in (sh_cd)");
    }
    else
    {
        if (chdir(args[1]) != 0)
            fatal("Error in (sh_cd)");
    }
    free(home_path);
    home_path = NULL;
    return (1);
}