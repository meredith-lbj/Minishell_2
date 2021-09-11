/*
** EPITECH PROJECT, 2021
** calcul_operator
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int calcul_operator(char *commands)
{
    int count = 0;

    for (int i = 0 ; commands[i] != '\0' ; i++) {
        if (commands[i] == '|' ||
            commands[i] == ';' ||
            commands[i] == '<' ||
            commands[i] == '>') {
            count++;
        }
    }
    count++;
    return (count);
}
