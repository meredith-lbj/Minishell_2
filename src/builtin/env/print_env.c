/*
** EPITECH PROJECT, 2021
** print_env
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

my_env_t *print_env(my_env_t *my_env)
{
    my_env_t *ptr = my_env;

    while (ptr != NULL) {
        my_putstr(ptr->name);
        my_putchar('=');
        if (ptr->value != NULL) {
            my_putstr(ptr->value);
        }
        my_putchar('\n');
        ptr = ptr->next;
    }
    return (my_env);
}
