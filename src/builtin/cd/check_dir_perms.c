/*
** EPITECH PROJECT, 2021
** check_dir_perms
** File description:
** No file there, just an epitech header example
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mysh.h"

void perm_denied(char *commands)
{
    write(2, commands, my_strlen(commands));
    write(2, ": Permission denied.\n", 21);
}

void not_directory(char *commands)
{
    if (commands == NULL)
        write(2, ": Not a directory.\n", 19);
    else {
        write(2, commands, my_strlen(commands));
        write(2, ": Not a directory.\n", 19);
    }
}

my_env_t *check_dir_perms(my_env_t *my_env, char *commands)
{
    struct stat file_stat;

    stat(commands, &file_stat);
    if (S_ISDIR(file_stat.st_mode)) {
        perm_denied(commands);
    }
    else {
        not_directory(commands);
    }
    return (my_env);
}
