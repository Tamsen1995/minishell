#include "../includes/ft_sh.h"

/*
** Takes in a directory path and a filename
** and makes a file path out of it
*/

// TODO put into libft

char        *make_file_path(char *dir_path, char *filename)
{
    char        *file_path;
    int         fl_path_len;

    fl_path_len = 0;
    file_path = NULL;
    fl_path_len = ft_strlen(dir_path);
    fl_path_len = fl_path_len + ft_strlen(filename);
    fl_path_len = fl_path_len + 2; // Adding two one for '/' and one for '/'
    file_path = ft_strnew(fl_path_len);
    file_path = ft_strcat(file_path, dir_path);
    file_path = ft_strcat(file_path, "/"); // subject to change
    file_path = ft_strcat(file_path, filename);
    return (file_path);
}

/*
** a wrapper around opendir to make it safer
** in case the function fails it safely exits the programs
*/

// TODO put into libft

DIR   *safe_opendir(char *dir_path)
{
    DIR *dir;

    dir = NULL;
    if (!(dir = opendir(dir_path)))
        fatal("Could not open directory in (check_dir_paths)");
    return (dir);
}
/*
** Receives a (potential) file path and a directory path
** and checks to see if it makes with
** any of the file paths within the directory
** of the given directory path
** returns TRUE upon match
*/

T_BOOL        check_dir_paths(char *dir_path, char *file_path)
{
    DIR                 *dir;
    struct dirent       *ent;
    char                *cmpd_path;

    dir = NULL;
    ent = NULL;
    cmpd_path = NULL;
    if (!dir_path || !file_path)
        fatal("Error in (check_dir_paths)");
    dir = safe_opendir(dir_path);
    while ((ent = readdir(dir)))
    {
        cmpd_path = make_file_path(dir_path, ent->d_name);
        if (ft_strcmp(cmpd_path, file_path) == 0)
        {
            free(cmpd_path);
            cmpd_path = NULL;
            closedir(dir);
            return (TRUE);
        }
        free(cmpd_path);
        cmpd_path = NULL;
    }
    closedir(dir);
    return (FALSE);
}

/*
** Checks to see if the command given
** is the path of a binary command
*/

T_BOOL      check_bin_path(t_shell *shell)
{
    char **bin_dirs;
    int i;

    i = 0;
    bin_dirs = NULL;
    if (!shell || !shell->args[0])
        fatal("Error in (check_bin_path)");
    // get the path variable
    get_path_var(shell);
    bin_dirs = ft_strsplit(shell->path_var, ':');
    while (bin_dirs[i])
    {
        if (check_dir_paths(bin_dirs[i], shell->args[0]) == TRUE)
            return (TRUE);
        i++;
    }
    return (FALSE);
}