/*
** EPITECH PROJECT, 2021
** create_parse
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

char *fill_ope(char *commands, char *ope, int pos)
{
    if (pos + 1 <= my_strlen(commands) &&
        commands[pos - 1] == '<' &&
        commands[pos - 2] == '<') {
        ope = malloc(sizeof(char) * 3);
        ope[0] = '<';
        ope[1] = '<';
        ope[2] = '\0';
    } else if (pos + 1 <= my_strlen(commands) &&
               commands[pos - 1] == '>' &&
               commands[pos - 2] == '>') {
        ope = malloc(sizeof(char) * 3);
        ope[0] = '>';
        ope[1] = '>';
        ope[2] = '\0';
    } else {
        ope = malloc(sizeof(char) * 2);
        ope[0] = commands[pos - 1];
        ope[1] = '\0';
    }
    return (ope);
}

parse_t *create_parse(parse_t *parse, char *commands, char *fixed, int pos)
{
    parse_t *element = NULL;
    parse_t *ptr = parse;

    element = (struct parse_s *)malloc(sizeof(parse_t));
    element->com = get_commands(fixed);
    element->fixed_com = my_strdup(element->fixed_com, fixed);
    element->empty = 0;
    element->ope = fill_ope(commands, element->ope, pos);
    element->next = NULL;
    if (parse == NULL) {
        parse = element;
        return (parse);
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = element;
    return (parse);
}
