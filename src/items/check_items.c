/*
** EPITECH PROJECT, 2023
** init_items.c
** File description:
** init_items
*/

#include "../../include/my.h"
#include "../../include/struct.h"

sfSprite *get_sprite1(package_t *pk, int id)
{
    if (id == 50) {
        return (pk->it->si50);
    } if (id == 51) {
        return (pk->it->si51);
    } if (id == 52) {
        return (pk->it->si52);
    }
}

sfSprite *get_sprite(package_t *pk, int id)
{
    if (id == 0) {
        return (NULL);
    } if (id == 1) {
        return (pk->it->si1);
    } if (id == 2) {
        return (pk->it->si2);
    } if (id == 3) {
        return (pk->it->si3);
    } if (id == 4) {
        return (pk->it->si4);
    } if (id == 10) {
        return (pk->it->si10);
    } if (id == 20) {
        return (pk->it->si20);
    } if (id == 30) {
        return (pk->it->si30);
    } if (id == 40) {
        return (pk->it->si40);
    } return (get_sprite1(pk, id));
}

void display_inventory(package_t *pk, int id, int x, int y)
{
    sfSprite *affsp = sfSprite_create();
    affsp = get_sprite(pk, id);
    if (affsp == NULL)
        return;
    sfVector2f vec = {x + 2,y};
    sfSprite_setPosition(affsp, vec);
    sfRenderWindow_drawSprite(pk->sc->window, affsp, NULL);
}

void check_items2(package_t *pk)
{
    display_inventory(pk, pk->iv->cq, 1249, 462);
    display_inventory(pk, pk->iv->cr, 1305, 462);
    display_inventory(pk, pk->iv->cs, 1363, 462);
    display_inventory(pk, pk->iv->ct, 1421, 462);
    display_inventory(pk, pk->iv->cu, 1249, 520);
    display_inventory(pk, pk->iv->cv, 1305, 520);
    display_inventory(pk, pk->iv->cw, 1363, 520);
    display_inventory(pk, pk->iv->cx, 1421, 520);
}

void check_items(package_t *pk)
{
    if (pk->iv->ivo == 96) {
        display_inventory(pk, pk->iv->ca, 1249, 232);
        display_inventory(pk, pk->iv->cb, 1305, 232);
        display_inventory(pk, pk->iv->cc, 1363, 232);
        display_inventory(pk, pk->iv->cd, 1421, 232);
        display_inventory(pk, pk->iv->ce, 1249, 291);
        display_inventory(pk, pk->iv->cf, 1305, 291);
        display_inventory(pk, pk->iv->cg, 1363, 291);
        display_inventory(pk, pk->iv->ch, 1421, 291);
        display_inventory(pk, pk->iv->ci, 1249, 348);
        display_inventory(pk, pk->iv->cj, 1305, 348);
        display_inventory(pk, pk->iv->ck, 1363, 348);
        display_inventory(pk, pk->iv->cl, 1421, 348);
        display_inventory(pk, pk->iv->cm, 1249, 405);
        display_inventory(pk, pk->iv->cn, 1305, 405);
        display_inventory(pk, pk->iv->co, 1363, 405);
        display_inventory(pk, pk->iv->cp, 1421, 405);
        check_items2(pk);
    }
}
