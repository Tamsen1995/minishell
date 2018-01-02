#include "../includes/libft.h"

/*
** takes in a string and copies the exact string with the indicated chars into another array
** returns said array
*/

char			*ft_remove_char(char *string, char c)
{
	char	*ret;
	int		k;
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
	return (ret);
}
