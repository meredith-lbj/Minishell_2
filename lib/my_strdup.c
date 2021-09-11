/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>
#include "mysh.h"

char *my_strdup(char *str, char const *src)
{
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return (str);
}
