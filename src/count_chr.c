/*
** EPITECH PROJECT, 2021
** count_chr
** File description:
** No file there, just an epitech header example
*/

#include <mysh.h>

int count_chr(char *chaine, char chr)
{
    int count = 0;

    for (int i = 0 ; chaine[i] != '\0' ; i++) {
        if (chaine[i] == chr) {
            count++;
        }
    }
    return (count);
}
