/*
** EPITECH PROJECT, 2021
** init_redirect
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
char *get_filepath(parse_t *parse, char *ope)
{
    char *filepath = NULL;
    parse_t *ptr = parse;

    while (my_strcmp("|" , ptr->ope) == 0) {
        ptr = ptr->next;
    }
    if (my_strcmp(ptr->ope, ope) == 0)
        filepath = my_strdup(filepath, ptr->next->fixed_com);
    return (filepath);
}

redirect_t *init_redirect(parse_t *parse, redirect_t *redirect, char *ope)
{
    redirect = (struct redirect_s *)malloc(sizeof(redirect_t));
    redirect->ope = my_strdup(redirect->ope, ope);
    redirect->filepath = get_filepath(parse, ope);
    redirect->fdfile = 0;
    redirect->stdout = 0;
    redirect->stdin = 0;
    return (redirect);
}
