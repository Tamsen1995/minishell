#include "../../includes/ft_sh.h"

/*

** checks the arguments for the appropiate parameters
** goes on to allocate a new list element onto
** the end of the env vars list

*/

int     sh_setenv(char **args, t_shell *shell)
{
    t_env *tmp;

    tmp = NULL;
    if (!args || !shell)
        fatal("Error: no args present in (sh_setenv)");
    tmp = shell->env;
    if (shell->argc == 1)
        sh_env(shell);
    else if (shell->argc > 3)
    {
        ft_putendl("minishell: Too many arguments");
        return (1);
    } 
    else if (shell->argc == 2)
        ft_putenv(&tmp, args[1], "");
    else
        ft_putenv(&tmp, args[1], args[2]);

    return (1);
}