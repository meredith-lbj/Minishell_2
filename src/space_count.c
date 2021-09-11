/*
** EPITECH PROJECT, 2021
** space_count
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int space_count(char const *command)
{
    int count = 0;
    int i = 0;

    while (command[i] != '\0') {
        if (command[i] == ' ')
            count++;
        i++;
    }
    return (count);
}
