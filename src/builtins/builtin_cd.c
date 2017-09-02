#include "../../includes/ft_sh.h"


/*
** gets the shell and the name of an environment variable
** iterates through the env until it find said env variable
** env_var being the sought after variable
*/
char *get_env_var(t_shell *shell, char *name)
{
    t_env   *tmp;
    char    *env_var;

    tmp = NULL;
    tmp = shell->env;
    env_var = NULL;
    while (ft_strcmp(tmp->name, name) != 0 && tmp)
        tmp = tmp->next;
    if (ft_strcmp(tmp->name, name) == 0)
        env_var = ft_strdup(tmp->value);
    if (!env_var)
    {
        ft_putendl(name); // for debugging purposes we need to know 
        // if a name has been entered which does not exist
        fatal("Error in (get_env_var)");
    }
    return (env_var);
}


/*
** goes to the parent folder and 
** shows its path
** always relative to the current path
*/

void        precede_nd_show(t_shell *shell)
{
    char cwd[BUF_SIZE];
    char *old_pwd;

    old_pwd = NULL;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        ft_putendl(strerror(errno));
        fatal("Expand buf size in (precede_nd_show)");
    }
    old_pwd = get_env_var(shell, "OLDPWD"); 
    chdir(old_pwd);

        // getting the path of the cwd
        // then going back to the parent directory which is OLDPWD

    // change to oldpwd
    // change the oldpwd env variable
    //

}

/*
** A basic cd command
*/

int         sh_cd(char **args, t_shell *shell)
{
    char *home_path;

    home_path = NULL;
    home_path = get_env_var(shell, "HOME");


    // check the argument array in and discern wether anything 
    // else in the arguments array is folder path or not
    if (ft_strcmp(args[1], "-") == 0)
        precede_nd_show(shell);


    /*
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
    */

    free(home_path);
    home_path = NULL;
    return (1);
}