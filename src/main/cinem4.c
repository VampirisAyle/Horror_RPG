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

void cinem4_2(package_t *pk)
{
    if (pk->ga->dialog == 1
    && sfText_getFillColor(pk->ga->tcinema).a != 0
    && sfClock_getElapsedTime(pk->ga->ccinema).microseconds >= pk->ga->dcd) {
        sfText_setFillColor(pk->ga->tcinema, sfColor_fromRGBA(0, 255, 0,
        sfText_getFillColor(pk->ga->tcinema).a - 1));
        if ( sfText_getFillColor(pk->ga->tcinema).a == 0)
            pk->scene = 0;
        sfClock_restart(pk->ga->ccinema);
    }
}

void cinem4(package_t *pk)
{
    if (pk->ga->dialog == 0
    && sfText_getFillColor(pk->ga->tcinema).a != 255
    && sfRectangleShape_getFillColor(pk->ga->bbg).a != 255
    && sfClock_getElapsedTime(pk->ga->ccinema).microseconds >= pk->ga->dcd) {
        sfText_setString(pk->ga->tcinema, pk->ga->dialoglist[15]);
        sfText_setPosition(pk->ga->tcinema, (sfVector2f)
        {sfRectangleShape_getPosition(pk->ct->hitbox).x - 550,
        sfRectangleShape_getPosition(pk->ct->hitbox).y - 50});
        sfText_setFillColor(pk->ga->tcinema, sfColor_fromRGBA(0, 255, 0,
        sfText_getFillColor(pk->ga->tcinema).a + 1));
        sfRectangleShape_setFillColor(pk->ga->bbg, sfColor_fromRGBA(0, 0, 0,
        sfRectangleShape_getFillColor(pk->ga->bbg).a + 1));
        sfClock_restart(pk->ga->ccinema);
    } cinem4_2(pk);
}
