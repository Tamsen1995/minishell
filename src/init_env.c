/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:40:02 by tbui              #+#    #+#             */
/*   Updated: 2017/09/29 12:45:51 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** allocates a new environment variables list element
*/

t_env			*ft_new_env(char *name, char *value)
{
	t_env		*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		fatal("Error: could not allocate env var list elem in ft_new_env");
	new->next = NULL;
	new->prev = NULL;
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	return (new);
}

/*
** counts all the indicated charcaters in the given string
*/

// TODO put in libft
int				ft_count_chars(char *string, char c)
{
	int i;
	int amt;

	i = 0;
	amt = 0;
	while (string[i])
	{
		if (string[i] == c)
			amt++;
		i++;
	}
	return (amt);
}

/*
** takes in a string and copies the exact string with the indicated chars into another array
** returns said array

*/

// TODO put in libft
char			*ft_remove_char(char *string, char c)
{
	char	*ret;
	int		k; // The amount of the characters which are present in the string
	int		mem_size;
	int 	i;

	ret = NULL;
	k = 0;
	i = 0;
	mem_size = ft_strlen(string);
	if (!string || !c)
		fatal("Error in (ft_remove_char)");
	ret = ft_strnew(mem_size);
	while (string[i])
	{
		if (string[i] != c)
		{
			ret[k] = string[i];
			k++;
		}
		i++;
	}
	ret[k] = '\0';
	// TODO maybe free string
	return (ret);
}

/*
** iterates to the end of the env list
** and then adds the value to it
*/

void			ft_putenv(t_env **begin_list, char *name, char *value)
{
	t_env		*tmp;


	tmp = NULL;
	value = ft_remove_char(name, '"'); // TODO Function which will get rid of the ""s in every string
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
		tmp->next->prev = tmp;
	}
}

/*
** Takes in the environmnet vars
** and allocates a list with all the env vars in it
*/

t_env			*init_env(char **envv)
{
	t_env		*env_list;
	char		**env_var;
	int			i;

	i = 1;
	env_var = NULL;
	env_var = ft_strsplit(envv[0], '=');
	env_list = ft_new_env(env_var[0], env_var[1]);
	free_twod_arr(env_var);
	while (envv[i])
	{
		env_var = ft_strsplit(envv[i], '=');
		ft_putenv(&env_list, env_var[0], env_var[1]);
		free_twod_arr(env_var);
		i++;
	}
	return (env_list);
}
