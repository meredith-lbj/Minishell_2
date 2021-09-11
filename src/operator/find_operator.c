/*
** EPITECH PROJECT, 2021
** find_operator
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int check_double_operator(char *commands, int i)
{
    if (i + 1 <= my_strlen(commands) &&
        commands[i] == '<' &&
        commands[i + 1] == '<')
        return (1);
    else if (i + 1 <= my_strlen(commands) &&
        commands[i] == '>' &&
        commands[i + 1] == '>')
        return (1);
    return (0);
}

int find_operator(char *commands)
{
    for (int i = 0 ; commands[i] != '\0' ; i++) {
        if (commands[i] == '|' ||
            commands[i] == ';' ||
            commands[i] == '<' ||
            commands[i] == '>')
            return (1);
        if (check_double_operator(commands, i) == 1)
            return (1);
    }
    return (0);
}
