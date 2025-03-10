/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "../../include/my.h"

void kincirclepart2(package_t *pk, float range)
{
    if (range <= 300 && range > 80 && pk->en->knights->sskni.left == 0)
        pk->en->knights->sit = 1;
    if (range <= 80 && ((pk->en->knights->knipos.y - pk->ct->ppl.y + 62.5) <=
    150 && (pk->en->knights->knipos.y - pk->ct->ppl.y + 62.5) >= -50)) {
        if (pk->en->knights->sit != 2)
            pk->en->knights->sskni.left = 0;
        pk->en->knights->sit = 2;
    }
    if (range >= 300)
        pk->en->knights->sit = 0;
}

void kincircle(package_t *pk)
{
    float range = 0;
    if (pk->en->knights->pv > 0) {
        if (sfSprite_getScale(pk->en->knights->skni).x == -3) {
            range = sqrt(((pk->en->knights->knipos.x - 81)
            - (pk->ct->ppl.x + 62.5))
            *((pk->en->knights->knipos.x - 81) - (pk->ct->ppl.x + 60))
            + ((pk->en->knights->knipos.y + 60) - (pk->ct->ppl.y + 52.5))
            *((pk->en->knights->knipos.y + 60) - (pk->ct->ppl.y + 52.5)));
        } else {
            range = sqrt(((pk->en->knights->knipos.x + 81)
            - (pk->ct->ppl.x + 100))
            *((pk->en->knights->knipos.x + 81) - (pk->ct->ppl.x + 80))
            + ((pk->en->knights->knipos.y + 60) - (pk->ct->ppl.y + 52.5))
            *((pk->en->knights->knipos.y + 60) - (pk->ct->ppl.y + 52.5)));
        }
        kincirclepart2(pk, range);
    }
}

void knightloop(package_t *pk)
{
    int c = 0;
    while (c != 1) {
        if (pk->en->knights->pv == 0) {
            pk->en->knights->sit = 3;
            pk->en->knights->pv -= 1;
            pk->en->knights->sskni.left = 0;
        } if (pk->en->knights->alive == 1) {
            kincircle(pk);
            knightloopstat0(pk);
            knightloopstat1(pk);
            knightloopstat2(pk);
            knightloopstat3(pk);
        }
        if (pk->en->knights->next != NULL)
            pk->en->knights = pk->en->knights->next;
        else
            c = 1;
    } while (pk->en->knights->prev != NULL)
        pk->en->knights = pk->en->knights->prev;
}
