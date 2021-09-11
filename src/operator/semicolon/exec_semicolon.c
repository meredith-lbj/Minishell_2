/*
** EPITECH PROJECT, 2021
** exec_semicolon
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdio.h>
#include <stdlib.h>

int semicolon_count(parse_t *parse)
{
    parse_t *ptr = parse;
    int count = 0;

    while (my_strcmp(";" , ptr->ope) == 0) {
        count++;
        ptr = ptr->next;
    }
    return (count);
}

parse_t *exec_semicolon(my_env_t *my_env, parse_t *parse)
{
    int semicolon_nb = 0;

    semicolon_nb = semicolon_count(parse);
    while (semicolon_nb > 0) {
        if (my_strcmp(parse->com[0], "exit") == 0 &&
            parse->next != NULL) {
            parse = delete_node(parse);
            semicolon_nb--;
        }
        else {
            my_env = builtin_list(my_env, parse->fixed_com);
            parse = delete_node(parse);
            semicolon_nb--;
        }
    }
    return (parse);
}
