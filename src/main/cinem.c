/*
** EPITECH PROJECT, 2022
** main
** File description:
** main function
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include <stdio.h>
#include <stdlib.h>

void cinem01(package_t *pk)
{
    if (pk->ga->dialog == 0
    && sfText_getFillColor(pk->ga->tcinema).a != 255
    && sfClock_getElapsedTime(pk->ga->ccinema).microseconds >= pk->ga->dcd) {
        sfText_setString(pk->ga->tcinema, pk->ga->dialoglist[0]);
        sfText_setPosition(pk->ga->tcinema, (sfVector2f)
        {sfRectangleShape_getPosition(pk->ct->hitbox).x - 550,
        sfRectangleShape_getPosition(pk->ct->hitbox).y - 50});
        sfText_setFillColor(pk->ga->tcinema, sfColor_fromRGBA(0, 255, 0,
        sfText_getFillColor(pk->ga->tcinema).a + 1));
        sfClock_restart(pk->ga->ccinema);
    } if (pk->ga->dialog == 1
    && sfText_getFillColor(pk->ga->tcinema).a != 0
    && sfClock_getElapsedTime(pk->ga->ccinema).microseconds >= pk->ga->dcd) {
        sfText_setFillColor(pk->ga->tcinema, sfColor_fromRGBA(0, 255, 0,
        sfText_getFillColor(pk->ga->tcinema).a - 1));
        if ( sfText_getFillColor(pk->ga->tcinema).a == 0)
            pk->ga->dialog++;
        sfClock_restart(pk->ga->ccinema);
    }
}

void cinem23(package_t *pk)
{
    if (pk->ga->dialog == 2
    && sfText_getFillColor(pk->ga->tcinema).a != 255
    && sfClock_getElapsedTime(pk->ga->ccinema).microseconds >= pk->ga->dcd) {
        sfText_setString(pk->ga->tcinema, pk->ga->dialoglist[1]);
        sfText_setPosition(pk->ga->tcinema, (sfVector2f)
        {sfRectangleShape_getPosition(pk->ct->hitbox).x - 460,
        sfRectangleShape_getPosition(pk->ct->hitbox).y - 100});
        sfText_setFillColor(pk->ga->tcinema, sfColor_fromRGBA(0, 255, 0,
        sfText_getFillColor(pk->ga->tcinema).a + 1));
        sfClock_restart(pk->ga->ccinema);
    } if (pk->ga->dialog == 3
    && sfText_getFillColor(pk->ga->tcinema).a != 0
    && sfClock_getElapsedTime(pk->ga->ccinema).microseconds >= pk->ga->dcd) {
        sfText_setFillColor(pk->ga->tcinema, sfColor_fromRGBA(0, 255, 0,
        sfText_getFillColor(pk->ga->tcinema).a - 1));
        if ( sfText_getFillColor(pk->ga->tcinema).a == 0)
            pk->ga->dialog++;
        sfClock_restart(pk->ga->ccinema);
    }
}

void cinem(package_t *pk)
{
    cinem01(pk);
    cinem23(pk);
    if (pk->ga->dialog >= 4
    && sfRectangleShape_getFillColor(pk->ga->bbg).a != 0
    && sfClock_getElapsedTime(pk->ga->ccinema).microseconds >= 10000) {
        sfRectangleShape_setFillColor(pk->ga->bbg, sfColor_fromRGBA(0, 0, 0,
        sfRectangleShape_getFillColor(pk->ga->bbg).a - 1));
        if (sfRectangleShape_getFillColor(pk->ga->bbg).a == 0)
            pk->ga->dialog++;
        sfClock_restart(pk->ga->ccinema);
    } if (pk->ga->dialog >= 4
    && pk->ga->cportal != 90
    && sfClock_getElapsedTime(pk->ga->sldportal).microseconds >= 28333) {
        sfSprite_move(pk->ga->sportal2, (sfVector2f) {1, 0});
        pk->ga->cportal++;
        sfClock_restart(pk->ga->sldportal);
    } if (pk->ga->dialog == 0)
        sfSprite_setPosition(pk->ga->sportal2, (sfVector2f) {0, 0});
}
