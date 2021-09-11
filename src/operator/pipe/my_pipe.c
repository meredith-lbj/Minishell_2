/*
** EPITECH PROJECT, 2021
** my_pipe
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

parse_t *my_pipe(parse_t *parse,  my_env_t *my_env)
{
    int pipefd[2];
    int status;
    pid_t child;
    int fdd = 0;
    int pipe_nb = count_pipe(parse);
    parse_t *ptr = parse;

    while (pipe_nb-- > 0) {
        if (pipe(pipefd) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        child = fork();
        if (child == -1) {
            perror("child");
            exit(EXIT_FAILURE);
        }
        if (child == 0) {
            dup2(fdd, 0);
            if (pipe_nb > 0)
                dup2(pipefd[1], 1);
            close(pipefd[0]);
            my_env = builtin_list(my_env, ptr->fixed_com);
            exit(EXIT_SUCCESS);
        }
        else {
            if (my_strcmp("cd", ptr->com[0]) == 0)
                builtin_list(my_env, ptr->fixed_com);
            close(pipefd[1]);
            fdd = pipefd[0];
            ptr = ptr->next;
            if (pipe_nb <= 2)
                waitpid(child, &status, WUNTRACED | WCONTINUED);
        }
    }
    return (parse);
}
