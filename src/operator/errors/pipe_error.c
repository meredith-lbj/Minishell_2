/*
** EPITECH PROJECT, 2021
** pipe_error
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void exit_input_quote(char *command, int i)
{
    if (command[i] == '<') {
        i++;
        i = move(command, i);
        if (find_letter(command, i) == 2 ||
            find_letter(command, i) == 1) {
            write(2, "Missing name for redirect.\n", 27);
            exit(1);
        }
        write(2, "Ambiguous input redirect.\n", 26);
        exit(1);
    }
}

void exit_output_quote(char *command, int i)
{
    if (command[i] == '>') {
        i++;
        i = move(command, i);
        if (find_letter(command, i) == 2 ||
            find_letter(command, i) == 1) {
            write(2, "Missing name for redirect.\n", 27);
            exit(1);
        }
        write(2, "Invalid null command.\n", 22);
        exit(1);
    }
}

void exit_input_quotes(char *command, int i)
{
    if (i + 1 <= my_strlen(command) &&
        command[i + 1] == '<' &&
        command[i] == '<') {
        i += 2;
        i = move(command, i);
        if (find_letter(command, i) == 2 ||
            find_letter(command, i) == 1) {
            write(2, "Missing name for redirect.\n", 27);
            exit(1);
        }
        write(2, "Ambiguous input redirect.\n", 26);
        exit(1);
    }
}

void exit_output_quotes(char *command, int i)
{
    if (i + 1 <= my_strlen(command) &&
        command[i + 1] == '>' &&
        command[i] == '>') {
        i += 2;
        i = move(command, i);
        if (find_letter(command, i) == 2 ||
            find_letter(command, i) == 1) {
            write(2, "Missing name for redirect.\n", 27);
            exit(1);
        }
        write(2, "Invalid null command.\n", 22);
        exit(1);
    }
}

int pipe_error(char *command, char **fixed, int i, int *j)
{
    if (command[i] == '|') {
        (*fixed)[(*j)++] = command[i++];
        i = move(command, i);
        if (command[i] == ';' ||
            command[i] == '|') {
            write(2, "Invalid null command.\n", 22);
            exit(1);
        }
        exit_output_quotes(command, i);
        exit_input_quotes(command, i);
        exit_input_quote(command, i);
        exit_output_quote(command, i);
        if (i >= my_strlen(command)) {
            write(2, "Invalid null command.\n", 22);
            exit(1);
        }
    }
    return (i);
}
