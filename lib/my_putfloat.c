/*
** EPITECH PROJECT, 2022
** my_putfloat
** File description:
** put float
*/

#include "../include/my.h"

void my_putfloat(float value)
{
    int round = (int) value;
    int decimal = (int) ((value - round)* 100);
    my_putchar('(');
    my_putnbr(round);
    my_putchar('.');
    my_putnbr(decimal);
    my_putchar('%');
    my_putchar(')');
}
