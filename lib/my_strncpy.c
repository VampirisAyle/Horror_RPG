/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** str ncpy
*/

#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (n != i) {
        dest[i] = src[i];
        i++;
    }
    if (n < i) {
        dest[i] = '\0';
        }
    return (dest);
}
