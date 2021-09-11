/*
** EPITECH PROJECT, 2021
** check_start
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int check2(char const *str1, char *str2)
{
    int i = 0;

    while (str2[i] != '\0') {
        if (str1[i] == str2[i]) {
            i++;
        }
        else {
            return (1);
        }
    }
    return (0);
}

int check_start(char const *str1, char *str2)
{
    if (my_strlen(str1) < my_strlen(str2)) {
        return (1);
    }
    return (check2(str1, str2));
}
