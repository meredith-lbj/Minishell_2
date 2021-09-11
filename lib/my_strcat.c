/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;

    for (int i = 0 ; dest[i] != '\0' ; i++) {
        a++;
    }
    for (int j = 0 ; src[j] != '\0' ; j++) {
        dest[a+j] = src[j];
        dest[a+j+1] = '\0';
    }
    return (dest);
}
