/*
** EPITECH PROJECT, 2021
** fix_space
** File description:
** NO file there, jus tan epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

int check_end(char *command, int i)
{
    i = move(command, i);
    if (i < my_strlen(command))
        return (0);
    else
        return (1);
    return (0);
}

char *fix_space(char *command)
{
    int i = move(command, 0);
    int j = 0;
    char *fixed = malloc(sizeof(char) * (my_strlen(command) + 1));

    while (command[i] != '\0') {
        if (check_end(command, i) == 1) {
            fixed[j] = '\0';
            return (fixed);
        }
        if (command[i] == ' ' && check_end(command, i) == 0) {
            fixed[j++] = command[i++];
            i = move(command, i);
        }
        if (command[i] == '\t' && check_end(command, i) == 0) {
            fixed[j++] = ' ';
            i = move(command, i);
        } else
            fixed[j++] = command[i++];
    }
    fixed[j] = '\0';
    return (fixed);
}
