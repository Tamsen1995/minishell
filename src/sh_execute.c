#include "../includes/ft_sh.h"

// a function which will print an error msg and then exit the program
void fatal(char *err_msg)
{
    ft_putendl(err_msg);
    exit (-1);
}

// TODO implement all the builtins
// simply checks the argument array for
// a builtin command
T_BOOL check_builtins(char **args)
{
    if (ft_strcmp(args[0], "echo") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "cd") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "setenv") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "unsetenv") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "env") == 0)
        return (TRUE);
    if (ft_strcmp(args[0], "exit") == 0)
        return (TRUE);
    return (FALSE);
}

// redirects the flow to the appropiate
// builtin
// returns whatever the builtin returns
int exec_builtin(t_shell *shell)
{
    // Just output the command for now
    if (ft_strcmp(shell->args[0], "echo") == 0) // WIP
        return (sh_echo(shell->args));
    if (ft_strcmp(shell->args[0], "cd") == 0) // DONE ?
        return (sh_cd(shell->args, shell));
    if (ft_strcmp(shell->args[0], "setenv") == 0) // DONE
        return (sh_setenv(shell->args, shell));
    if (ft_strcmp(shell->args[0], "unsetenv") == 0)
        return (sh_unsetenv(shell->args, shell));
    if (ft_strcmp(shell->args[0], "env") == 0)
        return (sh_env(shell));
    if (ft_strcmp(shell->args[0], "exit") == 0) // DONE
        return (sh_exit());
    fatal("Error in exec_builtin: builtin recognized, but flow not properly redirected");
    return (0);
}

// function that will either start a process or a builtin
int sh_execute(char **envv, t_shell *shell)
{        
    // There was an empty command
    if (!shell->args || !shell->args[0])
        return (1);
    if (check_builtins(shell->args) == TRUE) 
        return (exec_builtin(shell)); // WIP
    return (sh_launch(envv, shell));
}