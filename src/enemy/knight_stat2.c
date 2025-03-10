/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include "../../include/my.h"

void knightloopstat2check(package_t *pk, int deg)
{
    sfFloatRect pbounds = sfRectangleShape_getGlobalBounds(pk->ct->hitbox);
    sfFloatRect ebounds = sfRectangleShape_getGlobalBounds
    (pk->en->knights->slambox);
    if (sfFloatRect_intersects(&pbounds, &ebounds, NULL)) {
        pk->ct->deg += deg;
    }
}

void knightloopstat2_2(package_t *pk)
{
    if (pk->en->knights->sskni.left == 64) {
        knightloopstat2check(pk, 5);
        sfSound_setVolume(pk->en->knights->ksound, 100);
        sfSound_setBuffer(pk->en->knights->ksound, pk->en->knights->slam1);
        sfSound_play(pk->en->knights->ksound);
    } if (pk->en->knights->sskni.left == 320) {
        knightloopstat2check(pk, 10);
        sfSound_setBuffer(pk->en->knights->ksound, pk->en->knights->slam2);
        sfSound_play(pk->en->knights->ksound);
    } if (pk->en->knights->sskni.left == 768) {
        knightloopstat2check(pk, 30);
        sfSound_setBuffer(pk->en->knights->ksound, pk->en->knights->slam3);
        sfSound_play(pk->en->knights->ksound);
    } if (pk->en->knights->sskni.left >= 896) {
        pk->en->knights->sskni.left = 0;
        pk->en->knights->sskni.top = 64;
        pk->en->knights->cd = 400000;
    }
    sfSprite_setTextureRect(pk->en->knights->skni, pk->en->knights->sskni);
}

void knightloopstat2(package_t *pk)
{
    if (pk->en->knights->sit == 2 && sfClock_getElapsedTime
    (pk->en->knights->ckni).microseconds >= pk->en->knights->cd) {
        pk->en->knights->cd = 150000;
        sfClock_restart(pk->en->knights->ckni);
        pk->en->knights->sskni.top = 0;
        pk->en->knights->sskni.left += 64;
        knightloopstat2_2(pk);
    }
}
