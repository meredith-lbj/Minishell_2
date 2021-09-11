/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int signe(char const *str, int i, int x)
{
    if (str[i] == '-') {
        x = x * (-1);
    }
    return (x);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int x = 1;
    int result = 0;

    while ((str[i] == '-' || str[i] == '+') && str[i] != '\0') {
        x = signe(str, i, x);
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0') {
        result = result * 10 + str[i] - '0';
        i++;
        if (result < nb) {
            return (0);
        }
        nb = result;
    }
    result = result * x;
    return (result);
}
