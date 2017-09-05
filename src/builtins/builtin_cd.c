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
    char **new_oldpwd;

    old_pwd = NULL;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {   // getting the path of the cwd
        ft_putendl(strerror(errno));
        fatal("Expand buf size in (precede_nd_show)");
    }
    new_oldpwd = ft_twod_new(3);
    new_oldpwd[1] = ft_strdup("OLDPWD");
    new_oldpwd[2] = ft_strdup(cwd); // Making an array with the new oldpwd in 
    // to change the variable in the env
    old_pwd = get_env_var(shell, "OLDPWD"); 
    chdir(old_pwd); // Going back to the parent directory which is OLDPWD
    change_env_var(new_oldpwd, shell); // changing the oldpwd
    ft_putendl(old_pwd);
}

/*
** A basic cd command
*/

int         sh_cd(char **args, t_shell *shell)
{
    char *home_path;

    home_path = NULL;
    home_path = get_env_var(shell, "HOME");
    if (args[1] == NULL)
    {
        if (chdir(home_path) != 0)
            fatal("Error in (sh_cd)");
    }
    else if (ft_strcmp(args[1], "-") == 0)
        precede_nd_show(shell);
    else
    {
        if (chdir(args[1]) != 0)
        {
            ft_putstr("My cd: No such file or directory: ");
            ft_putendl(args[1]);
            return (1);
        }
    }
    free(home_path);
    home_path = NULL;
    return (1);
}