/*
** EPITECH PROJECT, 2021
** get_name
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

char *get_name(char const *chaine)
{
    int i = 0;
    int count = 0;
    char *str = NULL;

    while (chaine[i] != '=') {
        count++;
        i++;
    }
    i = 0;
    str = malloc(sizeof(char) * (count + 1));
    str[count] = '\0';
    while (count != 0) {
        str[i] = chaine[i];
        count--;
        i++;
    }
    return (str);
}
