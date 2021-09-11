/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

my_env_t *mysh(my_env_t *my_env, char *command)
{
    char *fixed = NULL;
    parse_t *parse = NULL;

    if (find_operator(command) == 1) {
        fixed = fix_operator(fix_space(command));
        if (parse_commands(fixed, &parse) == 1) {
            free(command);
            free(fixed);
            free_list(my_env);
            exit(1);
        }
        free(fixed);
        return (exec_operator(my_env, parse));
    }
    return (builtin_list(my_env, command));
}

void print_prompt(void)
{
    if (isatty(0) == 1)
        my_putstr("$>");
}

int main(int argc, char **argv, char **env)
{
    my_env_t *my_env = NULL;
    char *command = NULL;
    size_t len = 0;
    ssize_t command_len = 0;

    print_prompt();
    command_len = getline(&command, &len, stdin);
    my_env = create_env(my_env, env);
    if (command_len == -1 || my_strcmp("\n", command) == 0)
        return (0);
    while (command_len != -1) {
        command[command_len - 1] = '\0';
        my_env = mysh(my_env, command);
        len = 0;
        free(command);
        print_prompt();
        command_len = getline(&command, &len, stdin);
    }
    free_list(my_env);
    return (0);
}
