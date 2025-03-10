/*
** EPITECH PROJECT, 2023
** My_rpg
** File description:
** boutons
*/

#include "../../../include/my.h"

void pause_resume(package_t *pk)
{
    if (pk->cos.x > 3066 && pk->cos.x < 3334 && pk->cos.y > 3104
        && pk->cos.y < 3185){
            pk->pa->bres.left = 192;
            sfSprite_setTextureRect(pk->pa->sres, pk->pa->bres);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
                pk->pa->bres.left = 96;
                sfSprite_setTextureRect(pk->pa->sres, pk->pa->bres);
            }
        } else {
        pk->pa->bres.left = 0;
        sfSprite_setTextureRect(pk->pa->sres, pk->pa->bres);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->pa->bres.left == 96 || pk->pa->bres.left == 192)) {
        sfSprite_setTextureRect(pk->pa->sres, pk->pa->bres);
        pk->pa->j = 0;
        pk->pa->i = 0;
    }
}

void pause_options(package_t *pk)
{
    if (pk->cos.x > 3066 && pk->cos.x < 3334 && pk->cos.y > 3294
        && pk->cos.y < 3375){
            pk->mn->bom.left = 192;
            sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->mn->bom.left = 96;
            sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
            }
        } else {
        pk->mn->bom.left = 0;
        sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->mn->bom.left == 96 || pk->mn->bom.left == 192)) {
        sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
        pk->pa->k = 1;
    }
}

void pause_quit(package_t *pk)
{
if (pk->cos.x > 3066 && pk->cos.x < 3344 && pk->cos.y > 3494
        && pk->cos.y < 3575){
            pk->mn->bqm.left = 192;
            sfSprite_setTextureRect(pk->mn->sqm, pk->mn->bqm);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->mn->bqm.left = 96;
            sfSprite_setTextureRect(pk->mn->sqm, pk->mn->bqm);
            }
        } else {
        pk->mn->bqm.left = 0;
        sfSprite_setTextureRect(pk->mn->sqm, pk->mn->bqm);

    }
    if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->mn->bqm.left == 96 || pk->mn->bqm.left == 192)) {
        sfRenderWindow_close(pk->sc->window);
    }
}

void event_pause(package_t *pk)
{
    pause_quit(pk);
    pause_options(pk);
    pause_resume(pk);
}
