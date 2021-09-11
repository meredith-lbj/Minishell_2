/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

int negative(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        return (-1 * nb);
    }
    return (nb);
}

int my_put_nbr(int nb)
{
    int a;
    int b;

    nb = negative(nb);
    a = nb / 10;
    b = nb % 10;
    if (a != 0) {
        my_put_nbr(a);
        my_putchar(b + '0');
    }
    else {
        my_putchar(b + '0');
    }
    return (0);
}
