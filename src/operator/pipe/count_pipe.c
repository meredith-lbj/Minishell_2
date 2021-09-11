/*
** EPITECH PROJECT, 2021
** count_pipe
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

int count_pipe(parse_t *parse)
{
    int count = 0;
    parse_t *ptr = parse;

    while (my_strcmp("|" , ptr->ope) == 0) {
        count++;
        ptr = ptr->next;
    }
    count++;
    return (count);
}
