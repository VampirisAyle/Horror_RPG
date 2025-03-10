/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void reaperloopstat3(package_t *pk)
{
    if (pk->en->reaper->sit == 3 && sfClock_getElapsedTime
    (pk->en->reaper->crea).microseconds >= 200000) {
        sfClock_restart(pk->en->reaper->crea);
        pk->en->reaper->ssrea.top = 64;
        pk->en->reaper->ssrea.left += 128;
        if (pk->en->reaper->ssrea.left >= 1792) {
            pk->en->reaper->ssrea.left = 0;
            pk->en->reaper->alive = 0;
        }
        sfSprite_setTextureRect(pk->en->reaper->srea,
        pk->en->reaper->ssrea);
    }
}
