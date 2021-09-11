/*
** EPITECH PROJECT, 2021
** exec_pipe
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

parse_t *free_pipe(my_env_t *my_env, parse_t *parse)
{
    while (my_strcmp("|" , parse->ope) == 0)
        parse = delete_node(parse);
    if (my_strcmp(">" , parse->ope) == 0 ||
        my_strcmp("<" , parse->ope) == 0 ||
        my_strcmp(">>" , parse->ope) == 0 ||
        my_strcmp("<<" , parse->ope) == 0) {
        parse = delete_node(parse);
        parse = delete_node(parse);
    }
    else
        parse = delete_node(parse);
    return (parse);
}

parse_t *exec_pipe(my_env_t *my_env, parse_t *parse)
{
    redirect_t *redirect = redirections(parse, redirect);

    parse = check_exit(my_env, parse);
    parse = free_pipe(my_env, parse);
    if (redirect != NULL)
        reset_fd(redirect);
    return (parse);
}
