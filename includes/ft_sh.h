#ifndef FT_SH_H
# define FT_SH_H

#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include "../includes/libft.h"


# define BUFF_SIZE 8
#define T_BOOL int
#define TRUE 1
#define FALSE 0

// This list determines the current state of the shell
typedef struct		s_state
{
	T_BOOL				running;
	int				return_val;
	char			**env;
}					t_state;

int					get_next_line(int const fd, char **line);
int					sh_execute(char **args);

#endif