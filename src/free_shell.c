#include "../includes/ft_sh.h"

/*
** Takes in an env_var and frees it
*/
void free_env_var(t_env *env_var)
{
    free(env_var->name);
    env_var->name = NULL;
    free(env_var->value);
    env_var->value = NULL;
    free(env_var);
    env_var = NULL;
}

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
        free_env_var(tmp->next);
    }
    free_env_var(tmp);
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