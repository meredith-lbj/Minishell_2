/*
** EPITECH PROJECT, 2021
** find_redirect
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

char *find_redirections(parse_t *parse)
{
    char *ope = NULL;
    parse_t *ptr = parse;

    while (my_strcmp("|" , ptr->ope) == 0)
        ptr = ptr->next;
    if (my_strcmp(ptr->ope, ">") == 0)
        ope = my_strdup(ope, ">");
    if (my_strcmp(ptr->ope, "<") == 0)
        ope = my_strdup(ope, "<");
    if (my_strcmp(ptr->ope, ">>") == 0)
        ope = my_strdup(ope, ">>");
    if (my_strcmp(ptr->ope, "<<") == 0)
        ope = my_strdup(ope, "<<");
    return (ope);
}
