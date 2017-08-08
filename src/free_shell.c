#include "../includes/ft_sh.h"

/*
** Takes in the shell's environment and frees it
*/
void        free_env(t_env *env)
{
    t_env *tmp;
    
    tmp = NULL;
    tmp = env;
    while (tmp->next)
        tmp = tmp->next;

    if (tmp->prev)
        tmp = tmp->prev;
    while (tmp->prev)
    {
       tmp = tmp->prev;
       free(tmp->next->name);
       tmp->next->name = NULL;
       free(tmp->next->value);
       tmp->next->value = NULL;
       free(tmp->next);
       tmp->next = NULL;
    }
}

/*
** Takes in the shell and frees it
*/
void        free_shell(t_shell *shell)
{
    if (!shell)
        fatal("No shell to be freed in (free_shell)");
 
    // freeing the environment
    free_env(shell->env);
 
    // TODO More might be implemented later as we add more onto the shell

}