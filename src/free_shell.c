#include "../includes/ft_sh.h"

/*
** Takes in the shell and free it and its environment
*/
void        free_shell(t_shell *shell)
{
    t_env *tmp_env;

    tmp_env = shell->env;
    if (!shell)
        fatal("No shell to be freed in (free_shell)");
    // freeing the environment
    while (tmp_env->next)
    {
        ft_putendl(tmp_env->name);
        tmp_env = tmp_env->next;
    }
}