/*
** EPITECH PROJECT, 2021
** parse_commands
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int move_pos(char *commands, int pos)
{
    while (pos < my_strlen(commands) &&
           check_ope(commands, pos) != 1) {
        pos++;
    }
    return (pos);
}

int divide(char *commands, char **stock, int pos, int len)
{
    pos = move_pos(commands, pos);
    *stock = malloc(sizeof(char) * (pos - len + 1));
    (*stock)[pos - len] = '\0';
    for (int i = 0 ; i < pos - len ; i++)
        (*stock)[i] = commands[i + len];
    pos++;
    if (pos + 1 <= my_strlen(commands) &&
        commands[pos - 1] == '<' &&
        commands[pos] == '<')
        pos++;
    else if (pos + 1 <= my_strlen(commands) &&
             commands[pos - 1] == '>' &&
             commands[pos] == '>')
        pos++;
    return (pos);
}

parse_t *last_charac(parse_t *parse)
{
    int i = 0;
    parse_t *ptr = parse;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->ope = malloc(sizeof(char) * 2);
    ptr->ope[0] = 'X';
    ptr->ope[1] = '\0';
    return (parse);
}

int parse_commands(char *commands, parse_t **parse)
{
    int pos = 0;
    int len = 0;
    char *stock = NULL;
    char *fixed = NULL;

    while (pos < my_strlen(commands)) {
        len = pos;
        pos = divide(commands, &stock, pos, len);
        fixed = fix_space(stock);
        *parse = create_parse(*parse, commands, fixed, pos);
        free(stock);
        free(fixed);
    }
    if (*parse == NULL) {
        write(2, "Invalid null command.\n", 22);
        return (1);
    }
    *parse = last_charac(*parse);
    return (0);
}
