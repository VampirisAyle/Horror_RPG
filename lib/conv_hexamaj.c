/*
** EPITECH PROJECT, 2022
** decimal to hexa
** File description:
** base 16
*/

#include "../include/my.h"

void conv_hexamaj(int n)
{
    char hexa[100];
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexa[i] = temp + 48;
            i ++;
        } else {
            hexa[i] = temp + 55;
            i ++;
        }
        n = n / 16;
    }
    my_putstr(my_revstr(hexa));
}
