/*
** EPITECH PROJECT, 2023
** initinventory.c
** File description:
** initinventory
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void init_tab2(package_t *pk)
{
    pk->iv->ct = 0;
    pk->iv->cu = 0;
    pk->iv->cv = 0;
    pk->iv->cw = 0;
    pk->iv->cx = 0;
}

void init_tab(package_t *pk)
{
    pk->iv->ca = 52;
    pk->iv->cb = 52;
    pk->iv->cc = 52;
    pk->iv->cd = 52;
    pk->iv->ce = 52;
    pk->iv->cf = 52;
    pk->iv->cg = 52;
    pk->iv->ch = 52;
    pk->iv->ci = 1;
    pk->iv->cj = 2;
    pk->iv->ck = 3;
    pk->iv->cl = 4;
    pk->iv->cm = 10;
    pk->iv->cn = 20;
    pk->iv->co = 30;
    pk->iv->cp = 40;
    pk->iv->cq = 50;
    pk->iv->cr = 51;
    pk->iv->cs = 0;
    init_tab2(pk);
}

void init_inventory(package_t *pk)
{
    pk->iv->ivo = 0;
    pk->iv->ire = 0;
    pk->iv->icc = 0;
    pk->iv->cas = 0;
    pk->iv->tfi = sfTexture_createFromFile("sprites/Inventory/invt2.png", NULL);
    pk->iv->sfi = sfSprite_create();
    sfSprite_setTexture(pk->iv->sfi, pk->iv->tfi, sfFalse);
    pk->iv->pfi = (sfVector2f) {1200,100};
    sfSprite_setScale(pk->iv->sfi, (sfVector2f) {2, 2});
    sfSprite_setPosition(pk->iv->sfi, pk->iv->pfi);
    pk->iv->tca = sfTexture_createFromFile("sprites/Inventory/cs1.png", NULL);
    pk->iv->sca = sfSprite_create();
    sfSprite_setTexture(pk->iv->sca, pk->iv->tca, sfFalse);
    sfSprite_setScale(pk->iv->sca, (sfVector2f) {2, 2});
    pk->iv->tcb = sfTexture_createFromFile("sprites/Inventory/cs2.png", NULL);
    pk->iv->scb = sfSprite_create();
    sfSprite_setTexture(pk->iv->scb, pk->iv->tcb, sfFalse);
    sfSprite_setScale(pk->iv->scb, (sfVector2f) {2, 2});
    init_tab(pk);
}
