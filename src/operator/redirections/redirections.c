/*
** EPITECH PROJECT, 2021
** redirections
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

redirect_t *redirect_output(parse_t *parse, redirect_t *redirect, char *ope)
{
    redirect = init_redirect(parse, redirect, ope);
    free(ope);
    redirect->stdout = dup(1);
    redirect->fdfile = open(redirect->filepath, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    dup2(redirect->fdfile, STDOUT_FILENO);
    return (redirect);
}

redirect_t *redirect_input(parse_t *parse, redirect_t *redirect, char *ope)
{
    redirect = init_redirect(parse, redirect, ope);
    free(ope);
    redirect->stdout = dup(0);
    if ((redirect->fdfile = open(redirect->filepath, O_RDONLY)) < 0) {
            free(redirect->filepath);
            free(redirect->ope);
            free(redirect);
            return (NULL);
    }
    dup2(redirect->fdfile, STDOUT_FILENO);
    return (redirect);
}

redirect_t *redirect_output_in_end(parse_t *parse, redirect_t *redirect, char *ope)
{
    redirect = init_redirect(parse, redirect, ope);
    free(ope);
    redirect->stdout = dup(1);
    redirect->fdfile = open(redirect->filepath, O_CREAT | O_WRONLY | O_APPEND, 0777);
    dup2(redirect->fdfile, STDOUT_FILENO);
    return (redirect);
}

redirect_t *redirect_ouput_pipe(parse_t *parse, redirect_t *redirect, char *ope)
{
    return (redirect);
}

redirect_t *redirections(parse_t *parse, redirect_t *redirect)
{
    char *ope = find_redirections(parse);

    if (ope == NULL)
        return (NULL);
    if (my_strcmp(">", ope) == 0)
        return (redirect_output(parse, redirect, ope));
    if (my_strcmp("<", ope) == 0)
        return (redirect_input(parse, redirect, ope));
    if (my_strcmp(">>", ope) == 0)
        return (redirect_output_in_end(parse, redirect, ope));
    if (my_strcmp("<<", ope) == 0) {
        return (redirect);
    }
    return (NULL);
}
