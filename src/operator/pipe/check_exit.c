/*
** EPITECH PROJECT, 2021
** check_exit
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

int diff_ope(my_env_t *my_env, parse_t *parse, char *ope)
{
    parse_t *ptr = parse;

    while (my_strcmp(ope , ptr->ope) == 0)
        ptr = ptr->next;
    if (my_strcmp("X", ptr->ope) == 1)
        return (1);
    return (0);
}

parse_t *exit_excep(my_env_t *my_env, parse_t *parse)
{
    char *stock = NULL;

    stock = my_strdup(stock, parse->fixed_com);
    parse = delete_node(parse);
    parse = my_pipe(parse, my_env);
    my_env = builtin_list(my_env, stock);
    free(stock);
    return (parse);
}

parse_t *check_exit(my_env_t *my_env, parse_t *parse)
{
    if (parse->next != NULL &&
        my_strcmp(parse->com[0], "exit") == 0 &&
        diff_ope(my_env, parse, "|") == 0) {
        parse = exit_excep(my_env, parse);
    }
    else if (parse->next != NULL &&
             my_strcmp(parse->com[0], "exit") == 0 &&
             diff_ope(my_env, parse, "|") == 1) {
        parse = delete_node(parse);
        parse = my_pipe(parse, my_env);
    } else
        parse = my_pipe(parse, my_env);
    return (parse);
}
