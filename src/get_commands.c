/*
** EPITECH PROJECT, 2021
** get_commands
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <stdlib.h>

void fill_chaine(char ***chaine, char const *str)
{
    int x = 0;
    int y = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == ' ') {
            (*chaine)[x][y] = '\0';
            i++;
            x++;
            y = 0;
        }
        (*chaine)[x][y] = str[i];
        y++;
    }
    (*chaine)[x][y] = '\0';
}

char **complex_commands(char const *str, char **chaine, int space)
{
    int x = 0;
    int word = 0;

    chaine = malloc(sizeof(char*) * (space + 2));
    chaine[space + 1] = NULL;
    for (int i = 0 ; str[i] != '\0' ; i++) {
        word++;
        if (str[i] == ' ') {
            chaine[x] = malloc(sizeof(char) * (word + 1));
            chaine[x][word] = '\0';
            x++;
            word = 0;
        }
    }
    chaine[x] = malloc(sizeof(char) * (word + 1));
    chaine[x][word] = '\0';
    fill_chaine(&chaine, str);
    return (chaine);
}

char **get_commands(char const *str)
{
    int space = space_count(str);
    char **chaine = NULL;

    chaine = complex_commands(str, chaine, space);
    return (chaine);
}
