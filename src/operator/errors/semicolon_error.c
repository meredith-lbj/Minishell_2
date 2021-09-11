/*
** EPITECH PROJECT, 2021
** semicolon_error
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int move_semicolon(char *command, int i)
{
    while (i < my_strlen(command) && command[i] == ';') {
        i++;
	return (move_semicolon(command, i));
    }
    while (i < my_strlen(command) &&
	   (command[i] == ' ' || command[i] == '\t')) {
	i++;
        return (move_semicolon(command, i));
    }
    return (i);
}

int semicolon_error(char *command, char **fixed, int i, int *j)
{
    if (command[i] == ';') {
        (*fixed)[(*j)++] = command[i++];
        i = move_semicolon(command, i);
        if (find_letter(command, i) == 2) {
            write(2, "Invalid null command.\n", 22);
            exit(1);
        }
        if (command[i] == '|' ||
            command[i] == '<' ||
            command[i] == '>') {
            write(2, "Invalid null command.\n", 22);
            exit(1);
        }
        if (i >= my_strlen(command))
            exit(0);
    }
    return (i);
}
