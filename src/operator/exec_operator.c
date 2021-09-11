/*
** EPITECH PROJECT, 2021
** exec_operator
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_redirection(char *ope)
{
    if (my_strcmp(">", ope) == 0)
        return (1);
    if (my_strcmp("<", ope) == 0)
        return (1);
    if (my_strcmp(">>", ope) == 0)
        return (1);
    if (my_strcmp("<<", ope) == 0)
        return (1);
    return (0);
}

parse_t *exec_redirection(my_env_t *my_env, parse_t *parse, char *command)
{
    redirect_t *redirect = NULL;

    redirect = redirections(parse, redirect);
    if (redirect != NULL) {
        my_env = builtin_list(my_env, command);
        reset_fd(redirect);
    }
    parse = delete_node(parse);
    parse = delete_node(parse);
    return (parse);
}

parse_t *exec_simple_com(my_env_t *my_env, parse_t *parse)
{
    my_env = builtin_list(my_env, parse->fixed_com);
    parse = delete_node(parse);
    return (parse);
}

my_env_t *exec_operator(my_env_t *my_env, parse_t *parse)
{
    parse_t *ptr = parse;

    while (ptr != NULL) {
        if (my_strcmp("|" , ptr->ope) == 0)
            parse = exec_pipe(my_env, parse);
        else if (my_strcmp(";" , ptr->ope) == 0)
            parse = exec_semicolon(my_env, parse);
        else if (is_redirection(ptr->ope) == 1)
            parse = exec_redirection(my_env, parse, ptr->fixed_com);
        else
            parse = exec_simple_com(my_env, parse);
        ptr = parse;
    }
    if (parse != NULL) {
        my_env = builtin_list(my_env, parse->fixed_com);
        free_parse(parse);
    }
    return (my_env);
}
