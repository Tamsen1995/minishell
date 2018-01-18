#include "../../includes/ft_sh.h"

/*
** gets the shell and the name of an environment variable
** iterates through the env until it find said env variable
** env_var being the sought after variable
*/

char		*get_env_var(t_shell *shell, char *name)
{
	t_env	*tmp;
	char	*env_var;

	tmp = NULL;
	tmp = shell->env;
	env_var = NULL;
	while (ft_strcmp(tmp->name, name) != 0 && tmp)
		tmp = tmp->next;
	if (ft_strcmp(tmp->name, name) == 0)
		env_var = ft_strdup(tmp->value);
	if (!env_var)
		ft_putendl(name);
	return (env_var);
}
