/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void pincirclepart2(package_t *pk, float range)
{
    if (range <= 300 && range > 80 && pk->en->paragons->sspar.left == 0) {
        if (pk->en->paragons->sit == 0) {
            sfSound_setVolume(pk->en->paragons->parsound, 50);
            sfSound_setBuffer(pk->en->paragons->parsound,
            pk->en->paragons->taunt);
            sfSound_play(pk->en->paragons->parsound);
        }
        pk->en->paragons->sit = 1;
    } if (range <= 80 && (((pk->en->paragons->parpos.y + 165)
    - (pk->ct->ppl.y + 60)) <= 50 && ((pk->en->paragons->parpos.y + 165) -
    (pk->ct->ppl.y + 60)) >= -50)) {
        if (pk->en->paragons->sit != 2)
            pk->en->paragons->sspar.left = 0;
        pk->en->paragons->sit = 2;
    }
    if (range >= 300)
        pk->en->paragons->sit = 0;
}

void pincircle(package_t *pk)
{
    float range = 0;
    if (pk->en->paragons->pv > 0) {
        if (sfSprite_getScale(pk->en->paragons->spar).x == -3) {
            range = sqrt(((pk->en->paragons->parpos.x - 96)
            - (pk->ct->ppl.x + 65))
            *((pk->en->paragons->parpos.x - 96) - (pk->ct->ppl.x + 65))
            + ((pk->en->paragons->parpos.y + 165) - (pk->ct->ppl.y + 60))
            *((pk->en->paragons->parpos.y + 165) - (pk->ct->ppl.y + 60)));
        } else {
            range = sqrt(((pk->en->paragons->parpos.x + 96)
            - (pk->ct->ppl.x + 65))
            *((pk->en->paragons->parpos.x + 96) - (pk->ct->ppl.x + 65))
            + ((pk->en->paragons->parpos.y + 165) - (pk->ct->ppl.y + 60))
            *((pk->en->paragons->parpos.y + 165) - (pk->ct->ppl.y + 60)));
        }
        pincirclepart2(pk, range);
    }
}

void paragonloop(package_t *pk)
{
    int c = 0;
    while (c != 1) {
        if (pk->en->paragons->pv == 0) {
            pk->en->paragons->sit = 3;
            pk->en->paragons->pv -= 1;
            pk->en->paragons->sspar.left = 0;
        } if (pk->en->paragons->alive == 1) {
            pincircle(pk);
            paragonloopstat0(pk);
            paragonloopstat1(pk);
            paragonloopstat2(pk);
            paragonloopstat3(pk);
        }
        if (pk->en->paragons->next != NULL)
            pk->en->paragons = pk->en->paragons->next;
        else
            c = 1;
    } while (pk->en->paragons->prev != NULL)
        pk->en->paragons = pk->en->paragons->prev;
}
