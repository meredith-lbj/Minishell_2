/*
** EPITECH PROJECT, 2021
** check_ope
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int check_ope(char *commands, int pos)
{
    if (commands[pos] == '|' ||
        commands[pos] == ';' ||
        commands[pos] == '<' ||
        commands[pos] == '>')
        return (1);
    if (pos + 1 <= my_strlen(commands) &&
        commands[pos] == '<' &&
        commands[pos + 1] == '<')
        return (1);
    if (pos + 1 <= my_strlen(commands) &&
        commands[pos] == '>' &&
        commands[pos + 1] == '>')
        return (1);
    return (0);
}
