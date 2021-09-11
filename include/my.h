/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** No file there, just an epitech header example
*/

#ifndef MY_H_
#define MY_H_
void my_putchar(char c);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *str, char const *src);
char *my_strcat(char *dest, char const *src);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char *str2);
void free_chaine(char **str);
#endif
