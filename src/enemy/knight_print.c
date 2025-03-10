/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void printknights(package_t *pk)
{
    int c = 0;
    while (c != 1) {
        if (pk->en->knights->alive == 1) {
            sfRenderWindow_drawSprite(pk->sc->window, pk->en->knights->skni,
            NULL);
        }
        if (pk->en->knights->next != NULL)
            pk->en->knights = pk->en->knights->next;
        else
            c = 1;
    }
    while (pk->en->knights->prev != NULL)
        pk->en->knights = pk->en->knights->prev;
}
