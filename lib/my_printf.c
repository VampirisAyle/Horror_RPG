/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/
#include <stdarg.h>
#include "../include/my.h"

int groupe1(va_list arg, char const *format, int i, int forn)
{
    int check = 0;
    if (format[i] == 'c') {
        my_putchar(va_arg(arg, int));
        check = 1;
    } if (format[i] == 's') {
        my_putstr(va_arg(arg, char*));
        check = 1;
    } if (format[i] == 'i' || format[i] == 'd') {
        my_putnbr(va_arg(arg, int));
        check = 1;
    } if (format[i] == 'n') {
        int *a = va_arg(arg, int*);
        *a = forn;
        check = 1;
    } if (format[i] == 'u') {
        my_putnbru(va_arg(arg, int));
        check = 1;
    } return (check);
}

int groupe2(va_list arg, char const *format, int i)
{
    int check = 0;
    if (format[i] == 'o') {
        conv_octal(va_arg(arg, int));
        check = 1;
    } if (format[i] == 'x' ) {
        conv_hexamin(va_arg(arg, int));
        check = 1;
    } if (format[i] == 'X' ) {
        conv_hexamaj(va_arg(arg, int));
        check = 1;
    } if (format[i] == 'b' ) {
        conv_bin(va_arg(arg, int));
        check = 1;
    } if (format[i] == 'p') {
        showadress(va_arg(arg, void*));
        check = 1;
    } return (check);
}

int modulopart2(int check, char const *format, int i, int forn)
{
    if (check == 0) {
        if (format[i] != '%')
            my_putchar('%');
        i = forn;
    }
    return (i);
}

int modulo(va_list arg, char const *format, int i)
{
    int check = 0;
    int forn = i;
    while ((format[i] < 'a' || format[i] > 'z')
            && (format[i] < 'A' || format[i] > 'Z')) {
        i++;
        if (format[i] == '%') {
            my_putchar('%');
            check = 1;
            break;
        }}
    if ((format[i] >= 'a' && format[i + 1] <= 'z')
        || (format[i] >= 'A' && format[i + 1] <= 'Z')) {
        if (groupe1(arg, format, i, forn) == 1
            || groupe2(arg, format, i) == 1)
            check = 1;
    } i = modulopart2(check, format, i, forn);
    return (i);
}

int my_printf(char const *format, ...)
{
    va_list arg;
    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        if (format[i] == '%') {
            i = modulo(arg, format, i);
        }
        va_end(arg);
    }
    return (0);
}
