/*
** EPITECH PROJECT, 2022
** convertisseur en base 2
** File description:
** base 2
*/
#include "../include/my.h"

void conv_bin(int n)
{
    if (n < 0)
        n = n -(n * 2);
    int s;
    int i = 1;
    int bin = 0;
    while (n != 0) {
        s = n % 2;
        n /= 2;
        bin += s * i;
        i *= 10;
    }
    my_putnbr(bin);
}
