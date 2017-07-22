#include "../includes/ft_sh.h"


// TODO 
// intialize a prompt for the user
// Read a command from the standard input
// Parse it, meaning we seperate the command into a program and a set of arguments
// Execute and run the parsed command
int main(void)
{
    char *buf;
    int fd;


    fd = open("./auteur", O_RDWR);
    
    while (get_next_line(fd, &buf) == 1) // GNL tested and implemented into first module
        ft_putstr(buf);





    return (0);
}