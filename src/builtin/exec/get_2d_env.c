/*
** EPITECH PROJECT, 2021
** get_2d_env
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

char **fill_envn(my_env_t *my_env, char **envn)
{
    int i = 0;
    my_env_t *ptr = my_env;

    while (ptr != NULL) {
        envn[i] = my_strcpy(envn[i], ptr->name);
        envn[i] = my_strcat(envn[i], "=");
        envn[i] = my_strcat(envn[i], ptr->value);
        i++;
        ptr = ptr->next;
    }
    return (envn);
}

char **alloc_mem(my_env_t *my_env, char **envn)
{
    int len = 0;
    int i = 0;
    int count = 0;
    my_env_t *ptr = my_env;

    while (ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    ptr = my_env;
    envn = malloc(sizeof(char *) * (count + 1));
    envn[count] = NULL;
    while (ptr != NULL) {
        len = my_strlen(ptr->name) + my_strlen(ptr->value);
        envn[i] = malloc(sizeof(char) * (len + 2));
        envn[i][len + 1] = '\0';
        i++;
        ptr = ptr->next;
    }
    return (envn);
}

char **get_2d_env(my_env_t *my_env)
{
    char **envn = NULL;

    envn = alloc_mem(my_env, envn);
    envn = fill_envn(my_env, envn);
    return (envn);
}
