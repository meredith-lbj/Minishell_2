/*
** EPITECH PROJECT, 2021
** create_list
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

my_env_t *create_env(my_env_t *my_env, char **env)
{
    int i = 0;
    int list = 1;
    my_env_t *var = NULL;
    my_env_t *ptr = (struct my_env_s *)malloc(sizeof(my_env_t));

    while (env[i] != NULL) {
        var = (struct my_env_s *)malloc(sizeof(my_env_t));
        var->name = get_name(env[i]);
        var->value = get_value(env[i]);
        var->next = NULL;
        ptr->next = var;
        ptr = ptr->next;
        list--;
        if (list == 0) {
            my_env = var;
        }
        i++;
    }
    return (my_env);
}
