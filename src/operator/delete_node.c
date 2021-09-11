/*
** EPITECH PROJECT, 2021
** delete_node
** File description:
** No file there, just an epitech header example
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

parse_t *delete_node(parse_t *parse)
{
    parse_t *ptr = NULL;

    if (my_strcmp("X" , parse->ope) == 1) {
        ptr = parse->next;
        free_chaine(parse->com);
        free(parse->fixed_com);
        free(parse->ope);
        free(parse);
        parse = ptr;
    } else {
        free_chaine(parse->com);
        free(parse->fixed_com);
        free(parse->ope);
        free(parse);
        parse = NULL;
    }
    return (parse);
}
