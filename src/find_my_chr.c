/*
** EPITECH PROJECT, 2020
** my_strchr
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int find_my_chr(char const *str, char c)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] == c) {
            return (0);
        }
        i++;
    }
    return (1);
}
