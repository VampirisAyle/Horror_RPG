/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player kick
*/

#include "../../include/my.h"

void kickstatcheck(package_t *pk)
{
    if (pk->ct->kick == 1) {
        pk->ct->mvr = 0;
        pk->ct->mvd = 0;
        pk->ct->mvt = 0;
        pk->ct->mvl = 0;
    }
}

void initkick(package_t *pk)
{
    pk->ct->kick = 0;
    pk->ct->kcd = 100000;
    pk->ct->combocd = 0;
    pk->ct->combo = 0;
    pk->ct->ckick = sfClock_create();
    pk->ct->ccombo = sfClock_create();
    pk->ct->kickbox = sfRectangleShape_create();
    pk->ct->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(pk->ct->hitbox, (sfVector2f) {35, 67.5});
    sfRectangleShape_setPosition(pk->ct->hitbox, (sfVector2f) {(pk->ct->ppl.x
    + 45), (pk->ct->ppl.y + 20)});
    sfRectangleShape_setFillColor(pk->ct->hitbox, sfGreen);
    sfRectangleShape_setSize(pk->ct->kickbox, (sfVector2f) {62.5, 50});
    sfRectangleShape_setPosition(pk->ct->kickbox, (sfVector2f) {(pk->ct->ppl.x
    + 62.5), (pk->ct->ppl.y + 25)});
    sfRectangleShape_setFillColor(pk->ct->kickbox, sfRed);
}

void kickevent(package_t *pk)
{
    if (pk->ct->combo > 0 && pk->ct->kick == 0) {
        pk->ct->combo--;
        pk->ct->kick = 1;
    }
    kick1(pk);
    kick2(pk);
    kick3(pk);
    kick4(pk);
    sfRectangleShape_setPosition(pk->ct->hitbox, (sfVector2f) {(pk->ct->ppl.x
    + 45), (pk->ct->ppl.y + 20)});
    if (sfSprite_getScale(pk->ct->spl).x >= 0) {
        sfRectangleShape_setPosition(pk->ct->kickbox, (sfVector2f)
        {(pk->ct->ppl.x + 62.5), (pk->ct->ppl.y + 25)});
    } else {
        sfRectangleShape_setPosition(pk->ct->kickbox, (sfVector2f)
        {(pk->ct->ppl.x), (pk->ct->ppl.y + 25)});
    }
}

void kickcheck(package_t *pk)
{
    if (pk->iv->ivo != 96) {
        if (pk->sc->event.type == sfEvtMouseButtonPressed
        && pk->sc->event.mouseButton.button == sfMouseLeft
        && sfClock_getElapsedTime(pk->ct->ccombo).microseconds >= 500000) {
            pk->ct->combo++;
            pk->ct->combocd = 1;
            sfClock_restart(pk->ct->ccombo);
        }
    } if (pk->sc->event.type == sfEvtKeyPressed
    && pk->sc->event.key.code == sfKeyE
    && pk->ga->save == 0) {
        sfFloatRect pbox = sfRectangleShape_getGlobalBounds(pk->ct->hitbox);
        sfFloatRect sbox = sfRectangleShape_getGlobalBounds(pk->ga->savebox);
        if (sfFloatRect_intersects(&pbox, &sbox, NULL) == sfTrue)
            pk->ga->save = 1;
    } if (pk->sc->event.type == sfEvtKeyReleased
    && pk->sc->event.key.code == sfKeyE)
        pk->ga->save = 0;
}
