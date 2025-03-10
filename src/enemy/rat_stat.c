/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void ratloopstat3(package_t *pk)
{
    if (pk->en->rats->sit == 3 && sfClock_getElapsedTime
    (pk->en->rats->crat).microseconds >= 200000) {
        sfClock_restart(pk->en->rats->crat);
        pk->en->rats->ssrat.top = 32;
        pk->en->rats->ssrat.left += 32;
        if (pk->en->rats->ssrat.left >= 192) {
            pk->en->rats->ssrat.left = 0;
            pk->en->rats->alive = 0;
        }
        sfSprite_setTextureRect(pk->en->rats->srat,
        pk->en->rats->ssrat);
    }
}

void ratloopstat2check(package_t *pk, int deg)
{
    sfFloatRect pbounds = sfRectangleShape_getGlobalBounds(pk->ct->hitbox);
    sfFloatRect ebounds = sfRectangleShape_getGlobalBounds
    (pk->en->rats->slambox);
    if (sfFloatRect_intersects(&pbounds, &ebounds, NULL)) {
        pk->ct->deg += deg;
    }
}

void ratloopstat2(package_t *pk)
{
    if (pk->en->rats->sit == 2 && sfClock_getElapsedTime
    (pk->en->rats->crat).microseconds >= pk->en->rats->cd) {
        pk->en->rats->cd = 150000;
        sfClock_restart(pk->en->rats->crat);
        pk->en->rats->ssrat.top = 0;
        pk->en->rats->ssrat.left += 32;
        if (pk->en->rats->ssrat.left == 96) {
            sfSound_setVolume(pk->en->rats->ratsound, 50);
            sfSound_setBuffer(pk->en->rats->ratsound, pk->en->rats->slam1);
            sfSound_play(pk->en->rats->ratsound);
        } if (pk->en->rats->ssrat.left == 160)
            ratloopstat2check(pk, 10);
        if (pk->en->rats->ssrat.left >= 192) {
            pk->en->rats->ssrat.left = 0;
            pk->en->rats->ssrat.top = 64;
            pk->en->rats->cd = 400000;
        }
        sfSprite_setTextureRect(pk->en->rats->srat, pk->en->rats->ssrat);
    }
}

void ratloopstat1(package_t *pk)
{
    if (pk->en->rats->sit == 1 && sfClock_getElapsedTime
    (pk->en->rats->crat).microseconds >= 200000) {
        sfClock_restart(pk->en->rats->crat);
        mvrat(pk);
        pk->en->rats->ssrat.top = 96;
        pk->en->rats->ssrat.left += 32;
        if (pk->en->rats->ssrat.left >= 192)
            pk->en->rats->ssrat.left = 0;
        sfSprite_setTextureRect(pk->en->rats->srat, pk->en->rats->ssrat);
    }
}

void ratloopstat0(package_t *pk)
{
    if (pk->en->rats->sit == 0 && sfClock_getElapsedTime
    (pk->en->rats->crat).microseconds >= 120000) {
        sfClock_restart(pk->en->rats->crat);
        pk->en->rats->ssrat.top = 64;
        pk->en->rats->ssrat.left += 32;
    }
    if (pk->en->rats->sit == 0 && pk->en->rats->ssrat.left >= 192)
        pk->en->rats->ssrat.left = 0;
    sfSprite_setTextureRect(pk->en->rats->srat, pk->en->rats->ssrat);
}
