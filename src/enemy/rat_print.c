/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void printrats(package_t *pk)
{
    int c = 0;
    while (c != 1) {
        if (pk->en->rats->alive == 1) {
            sfRenderWindow_drawSprite(pk->sc->window, pk->en->rats->srat,
            NULL);
        }
        if (pk->en->rats->next != NULL)
            pk->en->rats = pk->en->rats->next;
        else
            c = 1;
    }
    while (pk->en->rats->prev != NULL)
        pk->en->rats = pk->en->rats->prev;
}
