/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** rev str
*/

char *my_revstr(char *str)
{
    int a = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        a++;
    }
    int length = a;
    int inc = 0;
    int dec = length -1;
    char temp;
    while (inc <= dec) {
        temp = str[inc];
        str[inc] = str[dec];
        str[dec] = temp;
        inc++;
        dec--;
    }
    return (str);
}
