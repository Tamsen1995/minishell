#include "../../includes/ft_sh.h"

/*
** check the given directory (path)
** for eventual matches with the given shell argument as well
** as it being a match with a builtin
** if both cases are true it returns TRUE
*/

T_BOOL      iter_builtin_bin_paths(char *bin_dir, t_shell *shell)
{
    DIR             *dir;
    struct  dirent  *ent;
    char            *file_path;

    dir = NULL;
    ent = NULL;
    file_path = NULL;
    dir = safe_opendir(bin_dir);
    while ((ent = readdir(dir)))
    {
        file_path = make_file_path(bin_dir, ent->d_name);

        ft_putendl(shell->args[0]); // TESTING

        if (ft_strcmp(file_path, shell->args[0]) == 0 &&
            check_builtins(shell) == TRUE)
        {
            closedir(dir);
            ft_strfree(file_path);
            return (TRUE);
        }
        ft_strfree(file_path);
    }
    closedir(dir);
    return (FALSE);
}


/*
** Goes through through all the binaries in the PATH variable
** compares all the paths for the individual binaries
** with the argument given
** if there is a match it return true
*/

T_BOOL      check_builtin_path(t_shell *shell)
{
    char    **bin_dirs;
    int     i;

    i = 0;
    bin_dirs = NULL;
    get_path_var(shell);
    bin_dirs = ft_strsplit(shell->path_var, ':');
    while (bin_dirs[i])
    {
        if (iter_builtin_bin_paths(bin_dirs[i], shell))
            return (TRUE);
        i++;
    }
    return (FALSE);
}

/*
** simply checks the argument array for
** a builtin command
*/

T_BOOL check_builtins(t_shell *shell)
{
    if (ft_strcmp(shell->args[0], "echo") == 0)
        return (TRUE);
    if (ft_strcmp(shell->args[0], "cd") == 0)
        return (TRUE);
    if (ft_strcmp(shell->args[0], "setenv") == 0)
        return (TRUE);
    if (ft_strcmp(shell->args[0], "unsetenv") == 0)
        return (TRUE);
    if (ft_strcmp(shell->args[0], "env") == 0)
        return (TRUE);
    if (ft_strcmp(shell->args[0], "exit") == 0)
        return (TRUE);
    return (FALSE);
}

/*
** redirects the flow to the appropiate
** builtin
** returns whatever the builtin returns
*/

int         exec_builtin(t_shell *shell)
{


    if (check_builtin_path(shell) == TRUE)
        // TODO make shell->args[0] the command




    // Just output the command for now
    if (ft_strcmp(shell->args[0], "echo") == 0)
        return (sh_echo(shell->args));
    if (ft_strcmp(shell->args[0], "cd") == 0)
        return (sh_cd(shell->args, shell));
    if (ft_strcmp(shell->args[0], "setenv") == 0)
        return (sh_setenv(shell->args, shell));
    if (ft_strcmp(shell->args[0], "unsetenv") == 0)
        return (sh_unsetenv(shell->args, shell));
    if (ft_strcmp(shell->args[0], "env") == 0)
        return (sh_env(shell));
    if (ft_strcmp(shell->args[0], "exit") == 0)
        return (sh_exit());
    fatal("Error in exec_builtin: builtin recognized, but flow not properly redirected");
    ft_strfree(shell->path_var);
    return (0);
}
