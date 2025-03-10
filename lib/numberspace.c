/*
** EPITECH PROJECT, 2022
** numberspace
** File description:
** spaces
*/
#include <stdarg.h>
#include <stddef.h>
#include "../include/my.h"

int numberspace(char *format, int i, int once)
{
    while (format[i] != '\0') {
        i++;
        once--;
    }
    while (once != 0) {
        my_putchar(' ');
        once--;
    }
    return (0);
}
