#include "../includes/libft.h"

/*
** Takes in an amt of wanted arrays
** then allocates this amount of pointers
** to pointers into a twod array
*/

char        **ft_twod_new(int amt)
{
    char **arr;

    arr = NULL;
    if (!(arr = (char **)malloc(sizeof(char *) * amt + 1)))
    {
        ft_putendl("Allocation error in (ft_twod_new)");
        exit(-1);
    }
    arr[amt] = NULL;
    return (arr);
}