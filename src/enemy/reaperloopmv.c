/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void mvreaperturn(package_t *pk, float distx)
{
    if (distx < 0 && sfSprite_getScale(pk->en->reaper->srea).x == 3) {
        sfSprite_setScale(pk->en->reaper->srea, (sfVector2f) {-3, 3});
        sfSprite_move(pk->en->reaper->srea, (sfVector2f) {174, 0});
        sfRectangleShape_setPosition(pk->en->reaper->hitbox, (sfVector2f)
        {pk->en->reaper->epos.x + 38, pk->en->reaper->epos.y + 99});
        sfRectangleShape_setPosition(pk->en->reaper->slambox, (sfVector2f)
        {pk->en->reaper->epos.x - 50 - 100, pk->en->reaper->epos.y + 35});
    }
    if (distx >= 0 && sfSprite_getScale(pk->en->reaper->srea).x == -3) {
        sfSprite_setScale(pk->en->reaper->srea, (sfVector2f) {3, 3});
        sfSprite_move(pk->en->reaper->srea, (sfVector2f) {-174, 0});
        sfRectangleShape_setPosition(pk->en->reaper->hitbox, (sfVector2f)
        {pk->en->reaper->epos.x - 38 - 109, pk->en->reaper->epos.y + 99});
        sfRectangleShape_setPosition(pk->en->reaper->slambox, (sfVector2f)
        {pk->en->reaper->epos.x - 50, pk->en->reaper->epos.y + 35});
    }
}

void mvreapermove(package_t *pk, float distx, float disty)
{
    if (distx <= 150 && distx >= -150) {
        sfSprite_move(pk->en->reaper->srea, (sfVector2f){0, disty / 10});
        sfRectangleShape_move(pk->en->reaper->hitbox, (sfVector2f)
        {0, disty / 10});
        sfRectangleShape_move(pk->en->reaper->slambox, (sfVector2f)
        {0, disty / 10});
    } else {
        sfSprite_move(pk->en->reaper->srea, (sfVector2f)
        {distx / 10, disty / 10});
        sfRectangleShape_move(pk->en->reaper->hitbox, (sfVector2f)
        {distx / 10, disty / 10});
        sfRectangleShape_move(pk->en->reaper->slambox, (sfVector2f)
        {distx / 10, disty / 10});
    }
}

void mvreaper(package_t *pk)
{
    float distx = 0;
    float disty = 0;
    if (sfSprite_getScale(pk->en->reaper->srea).x == 3) {
        distx = (pk->en->reaper->epos.x + 81) - (pk->ct->ppl.x + 62.5);
        disty = (pk->en->reaper->epos.y + 129) - (pk->ct->ppl.y + 52.5);
    } else {
        distx = (pk->en->reaper->epos.x - 81) - (pk->ct->ppl.x + 62.5);
        disty = (pk->en->reaper->epos.y + 129) - (pk->ct->ppl.y + 52.5);
    }
    distx = -(distx);
    disty = -(disty);
    mvreaperturn(pk, distx);
    mvreapermove(pk, distx, disty);
    pk->en->reaper->epos.x = sfSprite_getPosition(pk->en->reaper->srea).x;
    pk->en->reaper->epos.y = sfSprite_getPosition(pk->en->reaper->srea).y;
}
