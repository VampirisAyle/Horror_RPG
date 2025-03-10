/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void mvparagonturn(package_t *pk, float distx)
{
    if (distx < 0 && sfSprite_getScale(pk->en->paragons->spar).x == 3) {
        sfSprite_setScale(pk->en->paragons->spar, (sfVector2f) {-3, 3});
        sfSprite_move(pk->en->paragons->spar, (sfVector2f) {192, 0});
        sfRectangleShape_move(pk->en->paragons->slambox, (sfVector2f) {-54, 0});
    }
    if (distx + 60 >= 0 && sfSprite_getScale(pk->en->paragons->spar).x == -3) {
        sfSprite_setScale(pk->en->paragons->spar, (sfVector2f) {3, 3});
        sfSprite_move(pk->en->paragons->spar, (sfVector2f) {-192, 0});
        sfRectangleShape_move(pk->en->paragons->slambox, (sfVector2f) {54, 0});
    }
}

void mvparagonmove(package_t *pk, float distx, float disty)
{
    if (distx <= 80 && distx >= -80) {
        sfSprite_move(pk->en->paragons->spar, (sfVector2f){0, disty / 10});
        sfRectangleShape_move(pk->en->paragons->hitbox, (sfVector2f)
        {0, disty / 10});
        sfRectangleShape_move(pk->en->paragons->slambox, (sfVector2f)
        {0, disty / 10});
    } else {
        sfSprite_move(pk->en->paragons->spar, (sfVector2f)
        {distx / 20, disty / 20});
        sfRectangleShape_move(pk->en->paragons->hitbox, (sfVector2f)
        {distx / 20, disty / 20});
        sfRectangleShape_move(pk->en->paragons->slambox, (sfVector2f)
        {distx / 20, disty / 20});
    }
}

float mvparagoncollisionslr(package_t *pk, float distx)
{
    if (distx >= 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).x + 96,
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).y + 65}) == 1)
        distx = 0;
    else if (distx < 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).x,
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).y + 65}) == 1)
        distx = 0;
    return distx;
}

float mvparagoncollisionstd(package_t *pk, float disty)
{
    if (disty >= 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).x + 48,
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).y + 75}) == 1)
        disty = 0;
    else if (disty < 0 && mapcollision(pk, (sfVector2f){
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).x + 48,
    sfRectangleShape_getPosition(pk->en->paragons->hitbox).y + 55}) == 1)
        disty = 0;
    return disty;
}

void mvparagon(package_t *pk)
{
    float distx = 0;
    float disty = 0;
    if (sfSprite_getScale(pk->en->paragons->spar).x == 3) {
        distx = (pk->en->paragons->parpos.x + 96) - (pk->ct->ppl.x + 65);
        disty = (pk->en->paragons->parpos.y + 165) - (pk->ct->ppl.y + 60);
    } else {
        distx = (pk->en->paragons->parpos.x - 96) - (pk->ct->ppl.x + 65);
        disty = (pk->en->paragons->parpos.y + 165) - (pk->ct->ppl.y + 60);
    }
    distx = -(distx);
    disty = -(disty);
    distx = mvparagoncollisionslr(pk, distx);
    disty = mvparagoncollisionstd(pk, disty);
    mvparagonturn(pk, distx);
    mvparagonmove(pk, distx, disty);
    pk->en->paragons->parpos.x = sfSprite_getPosition(pk->en->paragons->spar).x;
    pk->en->paragons->parpos.y = sfSprite_getPosition(pk->en->paragons->spar).y;
}
