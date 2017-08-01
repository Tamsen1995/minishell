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
# define BIN "/bin/"
#define T_BOOL int
#define TRUE 1
#define FALSE 0

// This list determines the current state of the shell
typedef struct		s_env
{
	struct s_env	*next;
	struct s_env	*prev;
	char			*name;
	char			*value;
}					t_env;

typedef struct		s_shell
{
	int				argc; // Amount of arguments passed into my shell
	struct s_env	*env; // The environment variables
	// Add more data variables later
}					t_shell;

void				ft_putenv(t_env **begin_list, char *name, char *value);
T_BOOL  		    check_bin_cmd(char *potential_cmd);
int      			sh_env(t_shell *shell);
int   				sh_setenv(char **args, t_shell *shell);
t_env   		    *init_env(char **envv);
void 				fatal(char *err_msg);
int					get_next_line(int const fd, char **line);
int					sh_execute(char **args, char **envv, t_shell *shell);
int					sh_launch(char **args, char **envv);
int					sh_cd(char **args, t_shell *shell);
int					sh_exit(void);
int					sh_echo(char **args);
t_shell  		   *init_shell(int ac, char **av, char **envv);

#endif