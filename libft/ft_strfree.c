#include "../includes/libft.h"

/*
** Takes in a string and then frees it
** points it to NULL after
*/

void        ft_strfree(char *string)
{
    if (!string)
    {
        ft_putendl("No string to be freed in (ft_strfree)");
        exit(-1);
    }
    free(string);
    string = NULL;
}