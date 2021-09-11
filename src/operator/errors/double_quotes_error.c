/*
** EPITECH PROJECT, 2021
** double_quotes_error
** File description:
** No file there, just ane pitech header example
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int double_quotes_error(char *command, char **fixed, int i, int *j)
{
    if (find_letter(command, i) == 2) {
        (*fixed)[(*j)++] = command[i++];
        (*fixed)[(*j)++] = command[i++];
        i = move(command, i);
        if (find_letter(command, i) == 2 ||
            find_letter(command, i) == 1 ||
            i >= my_strlen(command)) {
            write(2, "Missing name for redirect.\n", 27);
            exit(1);
        }
    }
    return (i);
}
