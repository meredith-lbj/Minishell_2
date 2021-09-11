/*
** EPITECH PROJECT, 2021
** quotes_error
** File description:
** No file there, just an epitech header exampel
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int quotes_error(char *command, char **fixed, int i, int *j)
{
    if (command[i] == '<' ||
        command[i] == '>') {
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
