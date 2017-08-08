#include "../../includes/ft_sh.h"

char *get_home_path(t_shell *shell)
{
    t_env   *tmp;
    char    *home_path;

    tmp = NULL;
    tmp = shell->env;
    home_path = NULL;
    while (ft_strcmp(tmp->name, "HOME") != 0)
        tmp = tmp->next;
    home_path = tmp->value;
    return (home_path);
}

// cd
int sh_cd(char **args, t_shell *shell)
{
    char *home_path;

    home_path = NULL;
    home_path = get_home_path(shell);
    if (args[1] == NULL)
    {
        if (chdir(home_path) != 0)
            fatal("");
    }
    else
    {
        if (chdir(args[1]) != 0)
            fatal("");
    }

    // TODO free home path
    return (1);
}