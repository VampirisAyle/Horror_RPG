/*
** EPITECH PROJECT, 2022
** mystrtowordarray.c
** File description:
** str to word array
*/
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

int separator(char *str, int c)
{
    if (str[c] == '\n')
        return (1);
    return (0);
}

int linee(char *str)
{
    int count = 0;
    int count2 = 0;
    while (str[count] != '\0') {
        if (separator(str, count) == 1)
            count2++;
        count++;
    }
    return count2;
}

int colu(char *str, int c)
{
    int count = 0;
    while (str[c] != '\0' && separator(str, c) != 1) {
        count++;
        c++;
    }
    return count;
}

char **my_strtowoa(char *str)
{
    int c = 0;
    int c2 = 0;
    int c3 = 0;
    char **newstr = malloc((linee(str) + 2) * sizeof(char *));
    while (str[c] != '\0') {
        c3 = 0;
        newstr[c2] = malloc((colu(str, c) + 1) * sizeof(char));
        while (str[c] != '\0' && separator(str, c) != 1) {
            newstr[c2][c3] = str[c];
            c++;
            c3++;
        }
        newstr[c2][c3] = '\0';
        c2++;
        if (str[c] != '\0')
            c++;
    }
    newstr[c2] = 0;
    return (newstr);
}
