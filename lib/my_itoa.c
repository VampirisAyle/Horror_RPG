/*
** EPITECH PROJECT, 2022
** my_itoa
** File description:
** convert an integrer into a string
*/
#include <stdlib.h>
#include "../include/my.h"

char *my_itoa(int nbr)
{
    char *str = malloc(sizeof(int));
    int c = 0;
    int neg = 0;
    if (nbr < 0) {
        neg = 1;
        nbr = -(nbr);
    } str[c] = (nbr % 10) + 48;
    str[c + 1] = '\0';
    nbr /= 10;
    c++;
    while (nbr != 0) {
        str[c] = (nbr % 10) + 48;
        str[c+ 1] = '\0';
        c++;
        nbr /= 10;
    } if (neg == 1)
        str[c] = '-';
    str = my_revstr(str);
    return str;
}
