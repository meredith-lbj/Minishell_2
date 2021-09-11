/*
** EPITECH PROJECT, 2021
** free_parse
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

void free_parse(parse_t *parse)
{
    parse_t *ptr;

    ptr = parse;
    while (ptr != NULL) {
        ptr = ptr->next;
        free_chaine(parse->com);
        free(parse->ope);
        free(parse->fixed_com);
        free(parse);
        parse = ptr;
    }
}
