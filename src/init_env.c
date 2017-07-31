// allocates a new environment variables list element
t_env       *ft_new_env(char *name, char *value)
{
    t_env *new;

    if (!(new = (t_env *)malloc(sizeof(t_env))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    env->name = ft_strdup(name);
    env->value = ft_strdup(value);
    return (new);
}

// iterates to the end of the env list
// and then adds the value to it
void		ft_putenv(t_env **begin_list, char *name, char *value)
{
    t_env *new;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_env(name, value);
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_new_env(name, value);
    }
}

// Takes in the environmnet vars
// and allocates a list with all the env vars in it
t_env       *init_env(char **envv)
{
    char **env_var; // each individual env var split into name and value

    

    // TODO free env list
    // TODO free env list with all the strings in it
}