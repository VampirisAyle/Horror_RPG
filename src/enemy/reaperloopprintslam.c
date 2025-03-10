/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void printreaper(package_t *pk)
{
    if (pk->en->reaper->alive == 1) {
        sfRenderWindow_drawSprite(pk->sc->window, pk->en->reaper->srea, NULL);
    }
}

void slmreaper(package_t *pk)
{
    pk->en->reaper->epos.x = sfSprite_getPosition(pk->en->reaper->srea).x;
    pk->en->reaper->epos.y = sfSprite_getPosition(pk->en->reaper->srea).y;
    if (pk->ct->ppl.x + 70 < pk->en->reaper->epos.x && sfSprite_getScale(
        pk->en->reaper->srea).x == 3 && pk->en->reaper->ssrea.left >= 1024) {
        sfSprite_setScale(pk->en->reaper->srea, (sfVector2f) {-3, 3});
        sfSprite_move(pk->en->reaper->srea, (sfVector2f) {174, 0});
        sfRectangleShape_setPosition(pk->en->reaper->hitbox, (sfVector2f)
        {pk->en->reaper->epos.x + 38, pk->en->reaper->epos.y + 99});
        sfRectangleShape_setPosition(pk->en->reaper->slambox, (sfVector2f)
        {pk->en->reaper->epos.x - 50 - 100, pk->en->reaper->epos.y + 35});
    }
    if (pk->ct->ppl.x + 70 > pk->en->reaper->epos.x && sfSprite_getScale(
        pk->en->reaper->srea).x == -3 && pk->en->reaper->ssrea.left >= 1024) {
        sfSprite_setScale(pk->en->reaper->srea, (sfVector2f) {3, 3});
        sfSprite_move(pk->en->reaper->srea, (sfVector2f) {-174, 0});
        sfRectangleShape_setPosition(pk->en->reaper->hitbox, (sfVector2f)
        {pk->en->reaper->epos.x - 38 - 109, pk->en->reaper->epos.y + 99});
        sfRectangleShape_setPosition(pk->en->reaper->slambox, (sfVector2f)
        {pk->en->reaper->epos.x - 50, pk->en->reaper->epos.y + 35});
    }
}
