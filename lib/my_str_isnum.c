/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int my_str_isnum(char const *str)
{
    int i;

    for (i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] < 48 || str[i] > 57) {
            return (1);
        }
    }
    return (0);
}
