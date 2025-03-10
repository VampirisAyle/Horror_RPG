/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouvement
*/

#include "../../include/my.h"

void init_charact(package_t *pk)
{
    pk->ct->spl = sfSprite_create();
    pk->ct->tpl = sfTexture_createFromFile
    ("sprites/Characters/PlayerSS.png", NULL);
    sfSprite_setTexture(pk->ct->spl, pk->ct->tpl, sfFalse);
    sfSprite_setScale(pk->ct->spl, (sfVector2f) {2.5, 2.5});
    pk->ct->ppl = (sfVector2f) {3920,1560};
    sfSprite_setPosition(pk->ct->spl, pk->ct->ppl);
    pk->ct->bpl = (sfIntRect) {0, 0, 50, 36};
    sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
    pk->ct->frame = sfClock_create();
    pk->ct->cdmv = sfClock_create();
    pk->ct->mvd = 0;
    pk->ct->mvt = 0;
    pk->ct->mvl = 0;
    pk->ct->mvr = 0;
    pk->DL->rectest = sfRectangleShape_create();;
    sfRectangleShape_setPosition(pk->DL->rectest, (sfVector2f) {0, 0});
    sfRectangleShape_setSize(pk->DL->rectest, (sfVector2f) {100, 100});
    dlight(300, 45, (sfVector2f) {pk->ct->ppl.x + 75, pk->ct->ppl.y + 54},
    pk);
}

void reset(package_t *pk)
{
    if (pk->sc->event.type == sfEvtKeyReleased){
        if (pk->sc->event.key.code == sfKeyZ){
            pk->ct->mvt = 0;
        } if (pk->sc->event.key.code == sfKeyQ) {
            pk->ct->mvl = 0;
        } if (pk->sc->event.key.code == sfKeyD) {
            pk->ct->mvr = 0;
        } if (pk->sc->event.key.code == sfKeyS) {
            pk->ct->mvd = 0;
        }}
}

void for_mouvement(package_t *pk)
{
    reset(pk);
    if (pk->sc->event.type == sfEvtKeyPressed){
        if (pk->sc->event.key.code == sfKeyZ)
            pk->ct->mvt = 1;
        if (pk->sc->event.key.code == sfKeyQ)
            pk->ct->mvl = 1;
        if (pk->sc->event.key.code == sfKeyS)
            pk->ct->mvd = 1;
        if (pk->sc->event.key.code == sfKeyD)
            pk->ct->mvr = 1;
    }
}

void mvlight(package_t *pk)
{
    if (sfClock_getElapsedTime(pk->ct->cdmv).microseconds >= 50000) {
        dlight(300, pk->opt->light, (sfVector2f)
        {pk->ct->ppl.x + 75, pk->ct->ppl.y + 54}, pk);
        sfClock_restart(pk->ct->cdmv);
    }
}

void playerwalk(package_t *pk)
{
    if (sfClock_getElapsedTime(pk->ct->cdmv).microseconds >= 50000
    && pk->ct->mvt == 1 && pk->ct->kick == 0)
        movetop(pk);
    if (sfClock_getElapsedTime(pk->ct->cdmv).microseconds >= 50000
    && pk->ct->mvl == 1 && pk->ct->kick == 0)
        moveleft(pk);
    if (sfClock_getElapsedTime(pk->ct->cdmv).microseconds >= 50000
    && pk->ct->mvd == 1 && pk->ct->kick == 0)
        movedown(pk);
    if (sfClock_getElapsedTime(pk->ct->cdmv).microseconds >= 50000
    && pk->ct->mvr == 1 && pk->ct->kick == 0)
        moveright(pk);
    if (sfClock_getElapsedTime(pk->ct->cdmv).microseconds >= 50000
    && pk->ct->mvt == 0 && pk->ct->mvd == 0
    && pk->ct->mvr == 0 && pk->ct->mvl == 0
    && pk->ct->kick == 0)
        staticplayer(pk);
    mvlight(pk);
}
