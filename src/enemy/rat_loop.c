/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void raincirclepart2(package_t *pk, float range)
{
    if (range <= 300 && range > 32 && pk->en->rats->ssrat.left == 0) {
        if (pk->en->rats->sit == 0) {
            sfSound_setBuffer(pk->en->rats->ratsound, pk->en->rats->laugh);
            sfSound_play(pk->en->rats->ratsound);
        }
        pk->en->rats->sit = 1;
    }
    if (range <= 32 && ((pk->en->rats->ratpos.y - pk->ct->ppl.y + 62.5) <=
    150 && (pk->en->rats->ratpos.y - pk->ct->ppl.y + 62.5) >= -50)) {
        if (pk->en->rats->sit != 2)
            pk->en->rats->ssrat.left = 0;
        pk->en->rats->sit = 2;
    }
    if (range >= 300)
        pk->en->rats->sit = 0;
}

void raincircle(package_t *pk)
{
    float range = 0;
    if (pk->en->rats->pv > 0) {
        if (sfSprite_getScale(pk->en->rats->srat).x == -3) {
            range = sqrt(((pk->en->rats->ratpos.x - 81) - (pk->ct->ppl.x + 90))
            *((pk->en->rats->ratpos.x - 81) - (pk->ct->ppl.x + 90))
            + ((pk->en->rats->ratpos.y + 60) - (pk->ct->ppl.y + 52.5))
            *((pk->en->rats->ratpos.y + 60) - (pk->ct->ppl.y + 52.5)));
        } else {
            range = sqrt(((pk->en->rats->ratpos.x + 81) - (pk->ct->ppl.x + 90))
            *((pk->en->rats->ratpos.x + 81) - (pk->ct->ppl.x + 90))
            + ((pk->en->rats->ratpos.y + 60) - (pk->ct->ppl.y + 40))
            *((pk->en->rats->ratpos.y + 60) - (pk->ct->ppl.y + 40)));
        }
        raincirclepart2(pk, range);
    }
}

void ratloop(package_t *pk)
{
    int c = 0;
    while (c != 1) {
        if (pk->en->rats->pv == 0) {
            pk->en->rats->sit = 3;
            pk->en->rats->pv -= 1;
            pk->en->rats->ssrat.left = 0;
        } if (pk->en->rats->alive == 1) {
            raincircle(pk);
            ratloopstat0(pk);
            ratloopstat1(pk);
            ratloopstat2(pk);
            ratloopstat3(pk);
        }
        if (pk->en->rats->next != NULL)
            pk->en->rats = pk->en->rats->next;
        else
            c = 1;
    } while (pk->en->rats->prev != NULL)
        pk->en->rats = pk->en->rats->prev;
}
