/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player kick
*/

#include "../../include/my.h"

static void kick2_2(package_t *pk)
{
    if (pk->ct->bpl.left == 150)
        kickcollision(pk);
    if (pk->ct->combocd == 0 && pk->ct->combo > 0) {
        pk->ct->combo--;
        pk->ct->kick = 3;
        pk->ct->combocd = 1;
        pk->ct->bpl.top = 396;
    } if (pk->ct->combocd == 0 && pk->ct->combo == 0) {
        pk->ct->kick = 0;
        pk->ct->bpl.top = 0;
    } sfClock_restart(pk->ct->ckick);
}

void kick2(package_t *pk)
{
    if (pk->ct->kick == 2
    && sfClock_getElapsedTime(pk->ct->ckick).microseconds >= pk->ct->kcd) {
        pk->ct->bpl.left += 50;
        if (pk->ct->bpl.left >= 350) {
            pk->ct->bpl.left = 0;
            pk->ct->combocd = 0;
        } sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        kick2_2(pk);
    }
}

static void kick1_2(package_t *pk)
{
    if (pk->ct->bpl.left == 100 || pk->ct->bpl.left == 300)
        kickcollision(pk);
    if (pk->ct->combocd == 0 && pk->ct->combo > 0) {
        pk->ct->combo--;
        pk->ct->kick = 2;
        pk->ct->combocd = 1;
        pk->ct->bpl.top = 360;;
    } if (pk->ct->combocd == 0 && pk->ct->combo == 0) {
        pk->ct->kick = 0;
        pk->ct->bpl.top = 0;
    } sfClock_restart(pk->ct->ckick);
}

void kick1(package_t *pk)
{
    if (pk->ct->kick == 1
    && sfClock_getElapsedTime(pk->ct->ckick).microseconds >= pk->ct->kcd) {
        if (pk->ct->bpl.top >= 324)
            pk->ct->bpl.left += 50;
        if (pk->ct->bpl.top < 324) {
            pk->ct->bpl.top = 324;
            pk->ct->bpl.left = 0;
        } if (pk->ct->bpl.left >= 400) {
            pk->ct->bpl.left = 0;
            pk->ct->combocd = 0;
        } sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        kick1_2(pk);
    }
}
