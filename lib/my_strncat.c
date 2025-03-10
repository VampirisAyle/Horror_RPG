/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** task03
*/
char *my_strncat(char *dest, char const *src, int nb)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0')
        a++;
    while (nb != 0) {
        dest[a] = src[b];
        a++;
        b++;
        nb--;
        dest[a] = '\0';
    }
    return (dest);
}
