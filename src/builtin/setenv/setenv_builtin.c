/*
** EPITECH PROJECT, 2021
** setenv_builtin
** File description:
** NO file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>

my_env_t *change_value(my_env_t *my_env, char *name, const char *value)
{
    my_env_t *ptr = my_env;

    while (my_strcmp(name, ptr->name) != 0) {
        ptr = ptr->next;
    }
    free(ptr->value);
    if (value != NULL) {
        ptr->value = my_strdup(ptr->value, value);
    }
    else {
        ptr->value = NULL;
    }
    return (my_env);
}

my_env_t *add_in_end(my_env_t *my_env, char *name, const char *value)
{
    my_env_t *add = NULL;
    my_env_t *ptr = my_env;
    my_env_t *ptr2 = NULL;

    add = (struct my_env_s *)malloc(sizeof(my_env_t));
    add->name = my_strdup(ptr->name, name);
    if (value != NULL) {
        add->value = my_strdup(ptr->value, value);
    }
    else {
        add->value = NULL;
    }
    add->next = NULL;
    while (ptr != NULL) {
        ptr2 = ptr;
        ptr = ptr->next;
    }
    ptr2->next = add;
    return (my_env);
}

my_env_t *setenv_builtin(my_env_t *my_env, char *name, const char *value)
{
    char error[] = "setenv: Variable name must ";
    char error2[] = "contain alphanumeric characters.\n";
    char error_letter[] = "setenv: Variable name ";
    char error_letter2[] = "must begin with a letter.\n";

    if (check_var(my_env, name) == 0)
        return (change_value(my_env, name, value));
    if ((name[0] < 65 || name[0] > 90) &&
        (name[0] < 97 || name[0] > 122)) {
        write(2, error_letter, my_strlen(error_letter));
        write(2, error_letter2, my_strlen(error_letter2));
        return (my_env);
    }
    if (find_my_chr(name, '*') == 1 && find_my_chr(name, '=') == 1)
        return (add_in_end(my_env, name, value));
    write(2, error, my_strlen(error));
    write(2, error2, my_strlen(error2));
    return (my_env);
}
