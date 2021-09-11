/*
** EPITECH PROJECT, 2021
** reset_fd
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void reset_output_fd(redirect_t *redirect)
{
    close(redirect->fdfile);
    dup2(redirect->stdout, 1);
    close(redirect->stdout);
    free(redirect->filepath);
    free(redirect->ope);
    free(redirect);
}

void reset_input_fd(redirect_t *redirect)
{
    close(redirect->fdfile);
    dup2(redirect->stdin, 0);
    close(redirect->stdin);
    free(redirect->filepath);
    free(redirect->ope);
    free(redirect);
}

void reset_complex_output_fd(redirect_t *redirect)
{
    close(redirect->fdfile);
    dup2(redirect->stdout, 1);
    close(redirect->stdout);
    free(redirect->filepath);
    free(redirect->ope);
    free(redirect);
}

void reset_complex_input_fd(redirect_t *redirect)
{
}

int reset_fd(redirect_t *redirect)
{
    if (my_strcmp(">", redirect->ope) == 0) {
        reset_output_fd(redirect);
        return (0);
    }
    if (my_strcmp("<", redirect->ope) == 0) {
        reset_input_fd(redirect);
        return (0);
    }
    if (my_strcmp(">>", redirect->ope) == 0) {
        reset_complex_output_fd(redirect);
        return (0);
    }
    if (my_strcmp("<<", redirect->ope) == 0) {
        return (0);
    }
    return (0);
}
