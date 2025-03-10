/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void paragonloopstat3(package_t *pk)
{
    if (pk->en->paragons->sit == 3 && sfClock_getElapsedTime
    (pk->en->paragons->cpar).microseconds >= 200000) {
        sfClock_restart(pk->en->paragons->cpar);
        pk->en->paragons->sspar.top = 192;
        pk->en->paragons->sspar.left += 64;
        if (pk->en->paragons->sspar.left >= 384) {
            pk->en->paragons->sspar.left = 0;
            pk->en->paragons->alive = 0;
        }
        sfSprite_setTextureRect(pk->en->paragons->spar,
        pk->en->paragons->sspar);
    }
}

void paragonloopstat2check(package_t *pk)
{
    sfFloatRect pbounds = sfRectangleShape_getGlobalBounds(pk->ct->hitbox);
    sfFloatRect ebounds = sfRectangleShape_getGlobalBounds
    (pk->en->paragons->slambox);
    if (sfFloatRect_intersects(&pbounds, &ebounds, NULL)) {
        pk->ct->deg += 10;
    }
}

void paragonloopstat2(package_t *pk)
{
    if (pk->en->paragons->sit == 2 && sfClock_getElapsedTime
    (pk->en->paragons->cpar).microseconds >= pk->en->paragons->cd) {
        pk->en->paragons->cd = 150000;
        sfClock_restart(pk->en->paragons->cpar);
        pk->en->paragons->sspar.top = 0;
        pk->en->paragons->sspar.left += 64;
        if (pk->en->paragons->sspar.left == 256) {
            sfSound_setBuffer(pk->en->paragons->parsound,
            pk->en->paragons->slam1);
            sfSound_play(pk->en->paragons->parsound);
        }
        if (pk->en->paragons->sspar.left == 320)
            paragonloopstat2check(pk);
        if (pk->en->paragons->sspar.left >= 448) {
            pk->en->paragons->sspar.left = 0;
            pk->en->paragons->sspar.top = 256;
            pk->en->paragons->cd = 400000;
        } sfSprite_setTextureRect(pk->en->paragons->spar,
        pk->en->paragons->sspar);
    }
}

void paragonloopstat1(package_t *pk)
{
    if (pk->en->paragons->sit == 1 && sfClock_getElapsedTime
    (pk->en->paragons->cpar).microseconds >= 200000) {
        sfClock_restart(pk->en->paragons->cpar);
        mvparagon(pk);
        pk->en->paragons->sspar.top = 320;
        pk->en->paragons->sspar.left += 64;
        if (pk->en->paragons->sspar.left >= 384)
            pk->en->paragons->sspar.left = 0;
        sfSprite_setTextureRect(pk->en->paragons->spar,
        pk->en->paragons->sspar);
    }
}

void paragonloopstat0(package_t *pk)
{
    if (pk->en->paragons->sit == 0 && sfClock_getElapsedTime
        (pk->en->paragons->cpar).microseconds >= 120000) {
            sfClock_restart(pk->en->paragons->cpar);
            pk->en->paragons->sspar.top = 256;
            pk->en->paragons->sspar.left += 64;
        } if (pk->en->paragons->sit == 0 && pk->en->paragons->sspar.left >= 384)
            pk->en->paragons->sspar.left = 0;
        sfSprite_setTextureRect(pk->en->paragons->spar,
        pk->en->paragons->sspar);
}
