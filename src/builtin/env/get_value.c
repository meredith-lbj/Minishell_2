/*
** EPITECH PROJECT, 2021
** get_value
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

int letter_count(char const *chaine)
{
    int i = 0;

    while (chaine[i] != '=') {
        i++;
    }
    return (i + 1);
}

int value_count(char const *chaine, int i)
{
    int count = 0;

    while (chaine[i] != '\0') {
        count++;
        i++;
    }
    return (count);
}

char *get_value(char const *chaine)
{
    int	i = 0;
    int k = 0;
    int	count =	0;
    char *str = NULL;

    i = letter_count(chaine);
    count = value_count(chaine, i);
    str	= malloc(sizeof(char) * (count + 1));
    str[count] = '\0';
    while (count != 0) {
        str[k] = chaine[i];
        count--;
        i++;
        k++;
    }
    return (str);
}
