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

void knightloopstat3(package_t *pk)
{
    if (pk->en->knights->sit == 3 && sfClock_getElapsedTime
    (pk->en->knights->ckni).microseconds >= 200000) {
        sfClock_restart(pk->en->knights->ckni);
        pk->en->knights->sskni.top = 32;
        pk->en->knights->sskni.left += 64;
        if (pk->en->knights->sskni.left >= 832) {
            pk->en->knights->sskni.left = 0;
            pk->en->knights->alive = 0;
        }
        sfSprite_setTextureRect(pk->en->knights->skni,
        pk->en->knights->sskni);
    }
}

void knightloopstat1(package_t *pk)
{
    if (pk->en->knights->sit == 1 && sfClock_getElapsedTime
    (pk->en->knights->ckni).microseconds >= 200000) {
        sfClock_restart(pk->en->knights->ckni);
        mvknight(pk);
        pk->en->knights->sskni.top = 96;
        pk->en->knights->sskni.left += 64;
        if (pk->en->knights->sskni.left == 64) {
            sfSound_setVolume(pk->en->knights->ksound, 50);
            sfSound_setBuffer(pk->en->knights->ksound, pk->en->knights->walk1);
            sfSound_play(pk->en->knights->ksound);
        } if (pk->en->knights->sskni.left == 192) {
            sfSound_setBuffer(pk->en->knights->ksound, pk->en->knights->walk2);
            sfSound_play(pk->en->knights->ksound);
        } if (pk->en->knights->sskni.left >= 320)
            pk->en->knights->sskni.left = 0;
        sfSprite_setTextureRect(pk->en->knights->skni, pk->en->knights->sskni);
    }
}

void knightloopstat0(package_t *pk)
{
    if (pk->en->knights->sit == 0 && sfClock_getElapsedTime
    (pk->en->knights->ckni).microseconds >= 120000) {
        sfClock_restart(pk->en->knights->ckni);
        pk->en->knights->sskni.top = 64;
        pk->en->knights->sskni.left += 64;
    }
    if (pk->en->knights->sit == 0 && pk->en->knights->sskni.left >= 320)
        pk->en->knights->sskni.left = 0;
    sfSprite_setTextureRect(pk->en->knights->skni, pk->en->knights->sskni);
}
