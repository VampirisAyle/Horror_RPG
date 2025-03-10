/*
** EPITECH PROJECT, 2022
** convertir en differente base
** File description:
** base 8
*/
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void conv_octal(int n)
{
    int s;
    int i = 1;
    int octal = 0;

    if (n < 0)
        n = n -(n * 2);
    while (n != 0) {
        s = n % 8;
        n /= 8;
        octal += s * i;
        i *= 10;
    }
    my_putnbr(octal);
}
