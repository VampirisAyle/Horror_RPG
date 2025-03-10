/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** putnbr
*/

#include "../include/my.h"

int my_putnbr(int nb)
{
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        if (nb > -2147483648) {
            return my_putnbr(-nb);
        }
        my_putnbr(-(nb / 10));
        return my_putnbr(-(nb % 10));
    }
    my_putnbr(nb / 10);
    return my_putnbr(nb % 10);
}
