#include "../includes/libft.h"

/*
** counts all the indicated charcaters in the given string
*/

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
