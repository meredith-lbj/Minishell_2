/*
** EPITECH PROJECT, 2021
** find_letter
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int find_letter(char *commands, int i)
{
    if (check_double_operator(commands, i) == 1)
        return (2);
    if (commands[i] == '|' ||
        commands[i] == ';' ||
        commands[i] == '<' ||
        commands[i] == '>')
        return (1);
    return (0);
}
