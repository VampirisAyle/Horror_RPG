/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void mvknightturn(package_t *pk, float distx)
{
    if (distx < 0 && sfSprite_getScale(pk->en->knights->skni).x == 3) {
        sfSprite_setScale(pk->en->knights->skni, (sfVector2f) {-3, 3});
        sfSprite_move(pk->en->knights->skni, (sfVector2f) {120, 0});
        sfRectangleShape_move(pk->en->knights->slambox, (sfVector2f) {-50, 0});
    }
    if (distx + 60 >= 0 && sfSprite_getScale(pk->en->knights->skni).x == -3) {
        sfSprite_setScale(pk->en->knights->skni, (sfVector2f) {3, 3});
        sfSprite_move(pk->en->knights->skni, (sfVector2f) {-120, 0});
        sfRectangleShape_move(pk->en->knights->slambox, (sfVector2f) {50, 0});
    }
}

void mvknightmove(package_t *pk, float distx, float disty)
{
    if (distx <= 20 && distx >= -150) {
        sfSprite_move(pk->en->knights->skni, (sfVector2f){0, disty / 10});
        sfRectangleShape_move(pk->en->knights->hitbox, (sfVector2f)
        {0, disty / 10});
        sfRectangleShape_move(pk->en->knights->slambox, (sfVector2f)
        {0, disty / 10});
    } else {
        sfSprite_move(pk->en->knights->skni, (sfVector2f)
        {distx / 20, disty / 20});
        sfRectangleShape_move(pk->en->knights->hitbox, (sfVector2f)
        {distx / 20, disty / 20});
        sfRectangleShape_move(pk->en->knights->slambox, (sfVector2f)
        {distx / 20, disty / 20});
    }
}

float mvknightcollisionslr(package_t *pk, float distx)
{
    if (distx >= 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->knights->hitbox).x + 45,
    sfRectangleShape_getPosition(pk->en->knights->hitbox).y + 56}) == 1)
        distx = 0;
    else if (distx < 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->knights->hitbox).x,
    sfRectangleShape_getPosition(pk->en->knights->hitbox).y + 56}) == 1)
        distx = 0;
    return distx;
}

float mvknightcollisionstd(package_t *pk, float disty)
{
    if (disty >= 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->knights->hitbox).x + 22.5,
    sfRectangleShape_getPosition(pk->en->knights->hitbox).y + 66}) == 1)
        disty = 0;
    else if (disty < 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->knights->hitbox).x + 22.5,
    sfRectangleShape_getPosition(pk->en->knights->hitbox).y + 46}) == 1)
        disty = 0;
    return disty;
}

void mvknight(package_t *pk)
{
    float distx = 0;
    float disty = 0;
    if (sfSprite_getScale(pk->en->knights->skni).x == 3) {
        distx = (pk->en->knights->knipos.x + 60) - (pk->ct->ppl.x + 100);
        disty = (pk->en->knights->knipos.y + 60) - (pk->ct->ppl.y + 80);
    } else {
        distx = (pk->en->knights->knipos.x + 60) - (pk->ct->ppl.x + 62.5);
        disty = (pk->en->knights->knipos.y + 60) - (pk->ct->ppl.y + 52.5);
    }
    distx = -(distx);
    disty = -(disty);
    distx = mvknightcollisionslr(pk, distx);
    disty = mvknightcollisionslr(pk, disty);
    mvknightturn(pk, distx);
    mvknightmove(pk, distx, disty);
    pk->en->knights->knipos.x = sfSprite_getPosition(pk->en->knights->skni).x;
    pk->en->knights->knipos.y = sfSprite_getPosition(pk->en->knights->skni).y;
}
