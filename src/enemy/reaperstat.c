/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void reaperloopaction(package_t *pk)
{
    if (pk->en->reaper->sit == 1)
        mvreaper(pk);
    if (pk->en->reaper->sit == 2)
        slmreaper(pk);
}

void reaperloopstat2check(package_t *pk, int deg)
{
    sfFloatRect pbounds = sfRectangleShape_getGlobalBounds(pk->ct->hitbox);
    sfFloatRect ebounds = sfRectangleShape_getGlobalBounds
    (pk->en->reaper->slambox);
    if (sfFloatRect_intersects(&pbounds, &ebounds, NULL)) {
        pk->ct->deg += deg;
    }
}

void reaperloopstat2(package_t *pk)
{
    if (pk->en->reaper->sit == 2 && sfClock_getElapsedTime
    (pk->en->reaper->crea).microseconds >= 120000) {
        sfClock_restart(pk->en->reaper->crea);
        reaperloopaction(pk);
        pk->en->reaper->ssrea.top = 0;
        pk->en->reaper->ssrea.left += 128;
        if (pk->en->reaper->ssrea.left == 384) {
            sfSound_setBuffer(pk->en->reaper->reasound, pk->en->reaper->slamv);
            sfSound_play(pk->en->reaper->reasound);
        } if (pk->en->reaper->ssrea.left == 640) {
            reaperloopstat2check(pk, 50);
            sfSound_setBuffer(pk->en->reaper->reasound2, pk->en->reaper->slam);
            sfSound_play(pk->en->reaper->reasound2);
        }
        if (pk->en->reaper->ssrea.left >= 1792)
            pk->en->reaper->ssrea.left = 0;
        sfSprite_setTextureRect(pk->en->reaper->srea, pk->en->reaper->ssrea);
    }
}

void reaperloopstat1_2(package_t *pk)
{
    if (pk->en->reaper->ssrea.left == 384) {
        sfSound_setBuffer(pk->en->reaper->reasound, pk->en->reaper->walk1);
        sfSound_play(pk->en->reaper->reasound);
    } if (pk->en->reaper->ssrea.left == 512) {
        sfSound_setBuffer(pk->en->reaper->reasound, pk->en->reaper->walk2);
        sfSound_play(pk->en->reaper->reasound);
    } if (pk->en->reaper->ssrea.left == 896) {
        sfSound_setBuffer(pk->en->reaper->reasound, pk->en->reaper->walk3);
        sfSound_play(pk->en->reaper->reasound);
    } if (pk->en->reaper->ssrea.left == 0) {
        sfSound_setBuffer(pk->en->reaper->reasound, pk->en->reaper->walk4);
        sfSound_play(pk->en->reaper->reasound);
    }
}

void reaperloopstat1(package_t *pk)
{
    if (pk->en->reaper->sit == 1 && sfClock_getElapsedTime
    (pk->en->reaper->crea).microseconds >= 120000) {
        sfClock_restart(pk->en->reaper->crea);
        reaperloopaction(pk);
        pk->en->reaper->ssrea.top = 192;
        pk->en->reaper->ssrea.left += 128;
        if (pk->en->reaper->ssrea.left >= 1024)
            pk->en->reaper->ssrea.left = 0;
        reaperloopstat1_2(pk);
        sfSprite_setTextureRect(pk->en->reaper->srea, pk->en->reaper->ssrea);
    }
}
