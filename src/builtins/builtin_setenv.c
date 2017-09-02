#include "../../includes/ft_sh.h"

/*
** gets an argument array with name and value of an
** envv variable which is already present in the env list
** iterates to that variable and changes it
*/

void        change_env_var(char **args, t_shell *shell)
{
    t_env *

}


/*
** checks the arguments for the appropiate parameters
** goes on to allocate a new list element onto
** the end of the env vars list
** if the given variable already exists then it changes it in the envv list
*/

int     sh_setenv(char **args, t_shell *shell)
{
    t_env *tmp_env;
    char *name;

    tmp_env = NULL;
    name = NULL;
    if (!args || !shell)
        fatal("Error: no args present in (sh_setenv)");
    tmp_env = shell->env;
    if (shell->argc == 1)
        sh_env(shell);
    else if (shell->argc > 3)
    {
        ft_putendl("minishell: Too many arguments");
        return (1);
    } 
    name = args[1];
    while (tmp_env && ft_strcmp(tmp_env->name, name) != 0)
        tmp_env = tmp_env->next;
    if (ft_strcmp(tmp_env->name, name) == 0)
        change_env_var(args, shell);
    
// else just put it at the end of the list
// make sure to check for appropiate arguments

    return (1);
}