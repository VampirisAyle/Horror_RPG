/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** my_strupcase.c
*/
#include "../include/my.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void conv_longhexamin(long int n)
{
    char *hexa = (char*)malloc(100 * sizeof(char));
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexa[i] = temp + 48;
            i ++;
        } else {
            hexa[i] = temp + 87;
            i ++;
        }
        n = n / 16;
    }
    hexa[i] = '\0';
    my_putstr(my_revstr(hexa));
}

void showadress(void *n)
{
    my_putstr("0x");
    conv_longhexamin((long int)n);
}
