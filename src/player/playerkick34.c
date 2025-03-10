/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player kick
*/

#include "../../include/my.h"

static void kick4_2(package_t *pk)
{
    if (pk->ct->bpl.left == 50 || pk->ct->bpl.left == 200)
        kickcollision(pk);
    if (pk->ct->combocd == 0 && pk->ct->combo > 0) {
        pk->ct->combo = 0;
        pk->ct->kick = 0;
        pk->ct->combocd = 0;
        pk->ct->bpl.top = 0;
    } if (pk->ct->combocd == 0 && pk->ct->combo == 0) {
        pk->ct->kick = 0;
        pk->ct->bpl.top = 0;
    } sfClock_restart(pk->ct->ckick);
}

void kick4(package_t *pk)
{
    if (pk->ct->kick == 4
    && sfClock_getElapsedTime(pk->ct->ckick).microseconds >= pk->ct->kcd) {
        pk->ct->bpl.left += 50;
        if (pk->ct->bpl.left >= 350) {
            pk->ct->bpl.left = 0;
            pk->ct->combocd = 0;
        } sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        kick4_2(pk);
    }
}

static void kick3_2(package_t *pk)
{
    if (pk->ct->bpl.left == 100)
        kickcollision(pk);
    if (pk->ct->combocd == 0 && pk->ct->combo > 0) {
        pk->ct->combo--;
        pk->ct->kick = 4;
        pk->ct->combocd = 1;
        pk->ct->bpl.top = 432;
    } if (pk->ct->combocd == 0 && pk->ct->combo == 0) {
        pk->ct->kick = 0;
        pk->ct->bpl.top = 0;
    } sfClock_restart(pk->ct->ckick);
}

void kick3(package_t *pk)
{
    if (pk->ct->kick == 3
    && sfClock_getElapsedTime(pk->ct->ckick).microseconds >= pk->ct->kcd) {
        pk->ct->bpl.left += 50;
        if (pk->ct->bpl.left >= 300) {
            pk->ct->bpl.left = 0;
            pk->ct->combocd = 0;
        } sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
        kick3_2(pk);
    }
}
