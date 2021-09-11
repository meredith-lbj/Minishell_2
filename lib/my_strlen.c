/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int my_strlen(char const *str)
{
    int x = 0;

    for (int i = 0 ; str[i] != '\0' ; i++)
        x++;
    return (x);
}
