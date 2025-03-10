/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** len
*/

int my_strlen(char const *str)
{
    int compteur = 0;
    while (str[compteur] != '\0') {
        compteur += 1;
    }
    return (compteur);
}
