/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouvement
*/

#include "../../include/my.h"

void moveright(package_t *pk)
{
    if (mapcollision(pk, (sfVector2f){sfRectangleShape_getPosition
    (pk->ct->hitbox).x + 35,
    sfRectangleShape_getPosition(pk->ct->hitbox).y + 60}) != 1) {
        if (sfSprite_getScale(pk->ct->spl).x == -2.5) {
            sfSprite_move(pk->ct->spl, (sfVector2f) {-125, 0});
            sfSprite_setScale(pk->ct->spl, (sfVector2f) {2.5, 2.5});
        }
        sfSprite_move(pk->ct->spl, (sfVector2f) {8, 0});
        pk->ct->ppl.x += 8;
        if (pk->ct->bpl.top != 36) {
            pk->ct->bpl.top = 36;
            sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        } if (sfClock_getElapsedTime(pk->ct->frame).microseconds >= 100000){
                pk->ct->bpl.left += 50;
            sfClock_restart(pk->ct->frame);
        } if (pk->ct->bpl.left >= 250)
            pk->ct->bpl.left = 0;
        sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
    }
}

void movetop(package_t *pk)
{
    if (mapcollision(pk, (sfVector2f){sfRectangleShape_getPosition
    (pk->ct->hitbox).x + 17.5,
    sfRectangleShape_getPosition(pk->ct->hitbox).y + 40}) != 1) {
        sfSprite_move(pk->ct->spl, (sfVector2f) {0, -8});
        pk->ct->ppl.y -= 8;
        if (pk->ct->bpl.top != 36) {
            pk->ct->bpl.top = 36;
            sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        }
        if (sfClock_getElapsedTime(pk->ct->frame).microseconds >= 100000){
            pk->ct->bpl.left += 50;
            sfClock_restart(pk->ct->frame);
        }
        if (pk->ct->bpl.left >= 250)
            pk->ct->bpl.left = 0;
        sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
    }
}

void moveleft(package_t *pk)
{
    if (mapcollision(pk, (sfVector2f){sfRectangleShape_getPosition
    (pk->ct->hitbox).x,
    sfRectangleShape_getPosition(pk->ct->hitbox).y + 60}) != 1) {
        if (sfSprite_getScale(pk->ct->spl).x == 2.5) {
            sfSprite_move(pk->ct->spl, (sfVector2f) {125, 0});
            sfSprite_setScale(pk->ct->spl, (sfVector2f) {-2.5, 2.5});
        }
        sfSprite_move(pk->ct->spl, (sfVector2f) {-8, 0});
        pk->ct->ppl.x -= 8;
        if (pk->ct->bpl.top != 36) {
            pk->ct->bpl.top = 36;
            sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        } if (sfClock_getElapsedTime(pk->ct->frame).microseconds >= 100000){
            pk->ct->bpl.left += 50;
            sfClock_restart(pk->ct->frame);
        } if (pk->ct->bpl.left > 250)
            pk->ct->bpl.left = 0;
        sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
    }
}

void movedown(package_t *pk)
{
    if (mapcollision(pk, (sfVector2f){sfRectangleShape_getPosition
    (pk->ct->hitbox).x + 17.5,
    sfRectangleShape_getPosition(pk->ct->hitbox).y + 70}) != 1) {
        sfSprite_move(pk->ct->spl, (sfVector2f) {0, 8});
        pk->ct->ppl.y += 8;
        if (pk->ct->bpl.top != 36) {
            pk->ct->bpl.top = 36;
            sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        }
        if (sfClock_getElapsedTime(pk->ct->frame).microseconds >= 100000){
            pk->ct->bpl.left += 50;
            sfClock_restart(pk->ct->frame);
        }
        if (pk->ct->bpl.left >= 250)
            pk->ct->bpl.left = 0;
        sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
    }
}

void staticplayer(package_t *pk)
{
    if (pk->ct->bpl.top != 0) {
        pk->ct->bpl.top = 0;
        sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
    }
    if (sfClock_getElapsedTime(pk->ct->frame).microseconds >= 250000){
        pk->ct->bpl.left += 50;
        sfClock_restart(pk->ct->frame);
    }
    if (pk->ct->bpl.left >= 150)
        pk->ct->bpl.left = 0;
    sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
}
