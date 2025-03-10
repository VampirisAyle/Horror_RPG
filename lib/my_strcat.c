/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** task02
*/
char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0')
        a++;
    while (src[b] != '\0') {
        dest[a] = src[b];
        a++;
        b++;
        dest[a] = '\0';
    }
    return (dest);
}
