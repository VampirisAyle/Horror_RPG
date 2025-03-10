/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void printparagons(package_t *pk)
{
    int c = 0;
    while (c != 1) {
        if (pk->en->paragons->alive == 1) {
            sfRenderWindow_drawSprite(pk->sc->window, pk->en->paragons->spar,
            NULL);
        }
        if (pk->en->paragons->next != NULL)
            pk->en->paragons = pk->en->paragons->next;
        else
            c = 1;
    }
    while (pk->en->paragons->prev != NULL)
        pk->en->paragons = pk->en->paragons->prev;
}
