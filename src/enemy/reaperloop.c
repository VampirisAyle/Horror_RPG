/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void incirclepart2(package_t *pk, float range)
{
    if (range <= 500 && range > 225 && pk->en->reaper->ssrea.left == 0) {
        if (pk->en->reaper->sit == 0) {
            sfMusic_stop(pk->ga->manormusic);
            sfMusic_play(pk->ga->bossmusic);
        }
        pk->en->reaper->sit = 1;
    }
    if (range <= 225 && ((pk->en->reaper->epos.y - pk->ct->ppl.y) <= 60
    && (pk->en->reaper->epos.y - pk->ct->ppl.y) >= -132)) {
        if (pk->en->reaper->sit != 2)
            pk->en->reaper->ssrea.left = 0;
        pk->en->reaper->sit = 2;
    }
    if (range >= 600) {
        if (pk->en->reaper->sit != 0) {
            sfMusic_stop(pk->ga->bossmusic);
            sfMusic_play(pk->ga->manormusic);
        }
        pk->en->reaper->sit = 0;
    }
}

void incircle(package_t *pk)
{
    float range = 0;
    if (pk->en->reaper->pv > 0) {
        if (sfSprite_getScale(pk->en->reaper->srea).x == -3) {
            range = sqrt(((pk->en->reaper->epos.x - 81)
            - (pk->ct->ppl.x + 62.5))
            *((pk->en->reaper->epos.x - 81) - (pk->ct->ppl.x + 62.5))
            + ((pk->en->reaper->epos.y + 129) - (pk->ct->ppl.y + 52.5))
            *((pk->en->reaper->epos.y + 129) - (pk->ct->ppl.y + 52.5)));
        } else {
            range = sqrt(((pk->en->reaper->epos.x + 81)
            - (pk->ct->ppl.x + 62.5))
            *((pk->en->reaper->epos.x + 81) - (pk->ct->ppl.x + 62.5))
            + ((pk->en->reaper->epos.y + 129) - (pk->ct->ppl.y + 52.5))
            *((pk->en->reaper->epos.y + 129) - (pk->ct->ppl.y + 52.5)));
        }
        incirclepart2(pk, range);
    }
}

static void reaperloopstat0(package_t *pk)
{
    if (pk->en->reaper->sit == 0 && sfClock_getElapsedTime
    (pk->en->reaper->crea).microseconds >= 120000) {
        sfClock_restart(pk->en->reaper->crea);
        pk->en->reaper->ssrea.top = 128;
        pk->en->reaper->ssrea.left += 128;
        if (pk->en->reaper->ssrea.left >= 640)
            pk->en->reaper->ssrea.left = 0;
        sfSprite_setTextureRect(pk->en->reaper->srea, pk->en->reaper->ssrea);
    }
}

void reaperloop(package_t *pk)
{
    if (pk->en->reaper->pv == 0) {
        pk->en->reaper->sit = 3;
        pk->en->reaper->pv -= 1;
        pk->en->reaper->ssrea.left = 0;
    } if (pk->en->reaper->alive == 1) {
        incircle(pk);
        reaperloopstat0(pk);
        reaperloopstat1(pk);
        reaperloopstat2(pk);
        reaperloopstat3(pk);
    }
}
