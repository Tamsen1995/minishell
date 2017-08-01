#include "../../includes/ft_sh.h"

/*
** receives a linked element in a list
** and plans to removes it
*/
void remove_elem(t_env *elem)
{
    if (!elem)
        fatal("error: elem missing");
 // TODO code this
 // logic is simple, 
 // you take the previous and point it to the next
 // if it is and element in the middle


}

int     sh_unsetenv(char **args, t_shell *shell)
{
    int i;
    t_env *tmp;

    i = 1;
    tmp = NULL;
    if (!args || !shell)
        fatal("error: Missing args or shell vars");
    while (args[i])
    {
        tmp = shell->env;
        while (tmp)
        {
            if (ft_strcmp(args[i], tmp->name) == 0)
                remove_elem(tmp);
            tmp = tmp->next;
        }
        i++;
    }

    return (1);
}
