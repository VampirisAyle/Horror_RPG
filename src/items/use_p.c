/*
** EPITECH PROJECT, 2023
** use_p.c
** File description:
** use_p
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void app_final(package_t *pk)
{
    pk->ct->bpv = (sfIntRect) {0, 0, 190, 22};
    sfSprite_setTextureRect(pk->ct->spv, pk->ct->bpv);
}

void app_p2(package_t *pk, int a)
{
    if (a == 5) {
        pk->iv->ce = 0;
        app_final(pk);
    } if (a == 6) {
        pk->iv->cf = 0;
        app_final(pk);
    } if (a == 7) {
        pk->iv->cg = 0;
        app_final(pk);
    } if (a == 8) {
        pk->iv->ch = 0;
        app_final(pk);
    }
}

void app_p(package_t *pk, int a)
{
    if (a == 1) {
        pk->iv->ca = 0;
        app_final(pk);
    } if (a == 2) {
        pk->iv->cb = 0;
        app_final(pk);
    } if (a == 3) {
        pk->iv->cc = 0;
        app_final(pk);
    } if (a == 4) {
        pk->iv->cd = 0;
        app_final(pk);
    } app_p2(pk, a);
}

void use_p(package_t *pk)
{
    int a = 0;
    if (pk->iv->cas == 1) {
        a = 1;
    } if (pk->iv->cas == 2) {
        a = 2;
    } if (pk->iv->cas == 3) {
        a = 3;
    } if (pk->iv->cas == 4) {
        a = 4;
    } if (pk->iv->cas == 5) {
        a = 5;
    } if (pk->iv->cas == 6) {
        a = 6;
    } if (pk->iv->cas == 7) {
        a = 7;
    } if (pk->iv->cas == 8) {
        a = 8;
    } app_p(pk, a);
}
