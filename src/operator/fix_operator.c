/*
** EPITECH PROJECT, 2021
** fix_operator
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>

char *fix_operator(char *command)
{
    int j = 0;
    int i = 0;
    char *fixed = malloc(sizeof(char) * (my_strlen(command) + 1));

    while (command[i] != '\0') {
        i = semicolon_error(command, &fixed, i, &j);
        i = double_quotes_error(command, &fixed, i, &j);
        i = quotes_error(command, &fixed, i, &j);
        i = pipe_error(command, &fixed, i, &j);
        fixed[j++] = command[i++];
    }
    fixed[j] = '\0';
    return (fixed);
}
