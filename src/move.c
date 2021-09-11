/*
** EPITECH PROJECT, 2021
** move
** File description:
** No file there, just ane epitech header example
*/

#include "mysh.h"

int move(char *command, int i)
{
    while ((command[i] == ' ' || command[i] == '\t') &&
           command[i] != '\0')
        i++;
    return (i);
}
