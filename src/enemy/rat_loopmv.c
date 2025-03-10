/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void mvratturn(package_t *pk, float distx)
{
    if (distx < 0 && sfSprite_getScale(pk->en->rats->srat).x == 3) {
        sfSprite_setScale(pk->en->rats->srat, (sfVector2f) {-3, 3});
        sfSprite_move(pk->en->rats->srat, (sfVector2f) {96, 0});
        sfRectangleShape_move(pk->en->rats->slambox, (sfVector2f) {-30, 0});
    }
    if (distx >= 0 && sfSprite_getScale(pk->en->rats->srat).x == -3) {
        sfSprite_setScale(pk->en->rats->srat, (sfVector2f) {3, 3});
        sfSprite_move(pk->en->rats->srat, (sfVector2f) {-96, 0});
        sfRectangleShape_move(pk->en->rats->slambox, (sfVector2f) {30, 0});
    }
}

void mvratmove(package_t *pk, float distx, float disty)
{
    if (distx <= 60 && distx >= -150) {
        sfSprite_move(pk->en->rats->srat, (sfVector2f){0, disty / 5});
        sfRectangleShape_move(pk->en->rats->hitbox, (sfVector2f)
        {0, disty / 5});
        sfRectangleShape_move(pk->en->rats->slambox, (sfVector2f)
        {0, disty / 5});
    } else {
        sfSprite_move(pk->en->rats->srat, (sfVector2f)
        {distx / 10, disty / 10});
        sfRectangleShape_move(pk->en->rats->hitbox, (sfVector2f)
        {distx / 10, disty / 10});
        sfRectangleShape_move(pk->en->rats->slambox, (sfVector2f)
        {distx / 10, disty / 10});
    }
}

float mvratcollisionslr(package_t *pk, float distx)
{
    if (distx >= 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->rats->hitbox).x + 69,
    sfRectangleShape_getPosition(pk->en->rats->hitbox).y + 35}) == 1)
        distx = 0;
    else if (distx < 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->rats->hitbox).x,
    sfRectangleShape_getPosition(pk->en->rats->hitbox).y + 35}) == 1)
        distx = 0;
    return distx;
}

float mvratcollisionstd(package_t *pk, float disty)
{
    if (disty >= 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->rats->hitbox).x + 39.5,
    sfRectangleShape_getPosition(pk->en->rats->hitbox).y + 45}) == 1)
        disty = 0;
    else if (disty < 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->rats->hitbox).x + 22.5,
    sfRectangleShape_getPosition(pk->en->rats->hitbox).y + 25}) == 1)
        disty = 0;
    return disty;
}

void mvrat(package_t *pk)
{
    float distx = 0;
    float disty = 0;
    if (sfSprite_getScale(pk->en->rats->srat).x == 3) {
        distx = (pk->en->rats->ratpos.x + 60) - (pk->ct->ppl.x + 100);
        disty = (pk->en->rats->ratpos.y + 60) - (pk->ct->ppl.y + 30);
    } else {
        distx = (pk->en->rats->ratpos.x + 60) - (pk->ct->ppl.x + 62.5);
        disty = (pk->en->rats->ratpos.y + 32) - (pk->ct->ppl.y + 30);
    }
    distx = -(distx);
    disty = -(disty);
    distx = mvratcollisionslr(pk, distx);
    disty = mvratcollisionstd(pk, disty);
    mvratturn(pk, distx);
    mvratmove(pk, distx, disty);
    pk->en->rats->ratpos.x = sfSprite_getPosition(pk->en->rats->srat).x;
    pk->en->rats->ratpos.y = sfSprite_getPosition(pk->en->rats->srat).y;
}
