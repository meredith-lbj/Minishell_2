/*
** EPITECH PROJECT, 2021
** free_chaine
** File description:
** No file there, jus tan epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

void free_chaine(char **str)
{
    for (int i = 0 ; str[i] != NULL ; i++)
        free(str[i]);
    free(str);
}
