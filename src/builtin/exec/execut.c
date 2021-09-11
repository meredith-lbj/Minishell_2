/*
** EPITECH PROJECT, 2021
** process_child
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void termsig_status(int status)
{
    if (WTERMSIG(status) == 8) {
        write(2, "Floating exception\n", 19);
    }
    else if (WTERMSIG(status) == 11) {
        write(2, "Segmentation fault\n", 19);
    }
    else if (WTERMSIG(status) == 2) {
        exit(EXIT_SUCCESS);
    }
}

void core_dump_status(int status)
{
    if (WTERMSIG(status) == 8) {
        write(2, "Floating exception (core dumped)\n", 33);
    }
    else if (WTERMSIG(status) == 11) {
        write(2, "Segmentation fault (core dumped)\n", 33);
    }
    else if (WTERMSIG(status) == 2) {
        exit(EXIT_SUCCESS);
    }
}

void check_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (WCOREDUMP(status)) {
            core_dump_status(status);
        }
        else {
            termsig_status(status);
        }
    }
}

void is_executable(my_env_t *my_env, char **exe)
{
    char format[] = ": Exec format error. Wrong Architecture.\n";

    if (errno == ENOEXEC) {
        write(2, exe[0], my_strlen(exe[0]));
        write(2, format, my_strlen(format));
    }
    else if (errno == EACCES) {
        perm_denied(exe[0]);
    }
    else {
        write(2, exe[0], my_strlen(exe[0]));
        perror(": ");
    }
    exit(EXIT_SUCCESS);
}

int execut(my_env_t *my_env, char **exe)
{
    int status;
    pid_t child;
    char **envn = get_2d_env(my_env);

    child = fork();
    if (child != 0) {
        waitpid(child, &status, WUNTRACED | WCONTINUED);
    }
    if (child == 0) {
        if (execve(exe[0], exe, envn) == -1) {
            is_executable(my_env, exe);
        }
        free_chaine(envn);
        exit(EXIT_SUCCESS);
    }
    else {
        check_status(status);
        free_chaine(envn);
    }
    return (0);
}
