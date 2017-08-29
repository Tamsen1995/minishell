#include "../includes/ft_sh.h"

/*
** Takes in a directory path and a filename
** and makes a file path out of it
*/

char        *make_file_path(char *dir_path, char *filename)
{
    char        *file_path;
    
    file_path = NULL;
    

}

/*
** Receives a (potential) file path and a directory path
** and checks to see if it makes with
** any of the file paths within the directory
** of the given directory path
** returns TRUE upon match
*/

void        check_dir_paths(char *dir_path, char *file_path)
{
    DIR                 *dir;
    struct dirent       *ent;
    char                *cmpd_path;

    dir = NULL;
    ent = NULL;
    cmpd_path = NULL;
    if (!dir_path || !file_path)
        fatal("Error in (check_dir_paths)");
    if (!(dir = opendir(dir_path)))
        fatal("Could not open directory in (check_dir_paths)");
    while ((ent = readdir(dir)))
    {
        cmpd_path = make_file_path(dir_path, ent->d_name);
        if ()


    }

    // open directory
    // iteratively concatenate all the filenames within it to the dir_path
    // check to see if file_path matches with that
    // if yes return TRUE


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
    bin_dirs = ft_strsplit(shell->path_var, ":");
    while (bin_dirs[i])
    {
        check_dir_paths(); // PROTOTYPE
        i++;
    }







    // go into each folder and compare the path of
        // every file in the folder with the argument given
        // if it's a match then return TRUE

    return (TRUE); // TESTING
}