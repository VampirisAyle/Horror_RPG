/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button_menu_function
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void button_lg(package_t *pk)
{
    if (pk->cos.x > 816 && pk->cos.x < 1104 && pk->cos.y > 249
        && pk->cos.y < 321){
            pk->mn->blm.left = 192;
            sfSprite_setTextureRect(pk->mn->slm, pk->mn->blm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->slm, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->mn->blm.left = 96;
            sfSprite_setTextureRect(pk->mn->slm, pk->mn->blm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->slm, NULL);
            }
        } else {
        pk->mn->blm.left = 0;
        sfSprite_setTextureRect(pk->mn->slm, pk->mn->blm);
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->slm, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->mn->blm.left == 96 || pk->mn->blm.left == 192)) {
        pk->scene = 2;
        pk->ga->cmusic = 1;
        loadsave(pk);
    }
}

void button_ns(package_t *pk)
{
    if (pk->cos.x > 816 && pk->cos.x < 1104 && pk->cos.y > 374
        && pk->cos.y < 446){
            pk->mn->bnm.left = 192;
            sfSprite_setTextureRect(pk->mn->snm, pk->mn->bnm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->snm, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->mn->bnm.left = 96;
            sfSprite_setTextureRect(pk->mn->snm, pk->mn->bnm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->snm, NULL);
            }
        } else {
        pk->mn->bnm.left = 0;
        sfSprite_setTextureRect(pk->mn->snm, pk->mn->bnm);
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->snm, NULL);
    }
    if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->mn->bnm.left == 96 || pk->mn->bnm.left == 192)) {
        pk->scene = 1;
        pk->ga->cmusic = 1;
    }
}

void button_options(package_t *pk)
{
    if (pk->cos.x > 816 && pk->cos.x < 1104 && pk->cos.y > 499
        && pk->cos.y < 573){
            pk->mn->bom.left = 192;
            sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->som, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->mn->bom.left = 96;
            sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->som, NULL);
            }
        } else {
        pk->mn->bom.left = 0;
        sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->som, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->mn->bom.left == 96 || pk->mn->bom.left == 192)) {
        sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->som, NULL);
        pk->mn->s = 1;
    }
}

void button_credits(package_t *pk)
{
    if (pk->cos.x > 816 && pk->cos.x < 1104 && pk->cos.y > 624
        && pk->cos.y < 696){
            pk->mn->bcm.left = 192;
            sfSprite_setTextureRect(pk->mn->scm, pk->mn->bcm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->scm, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->mn->bcm.left = 96;
            sfSprite_setTextureRect(pk->mn->scm, pk->mn->bcm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->scm, NULL);
            }} else {
        pk->mn->bcm.left = 0;
        sfSprite_setTextureRect(pk->mn->scm, pk->mn->bcm);
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->scm, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->mn->bcm.left == 96 || pk->mn->bcm.left == 192)) {
        pk->mn->bcm.left = 0;
        sfSprite_setTextureRect(pk->mn->scm, pk->mn->bcm);
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->scm , NULL);
        pk->mn->s = 2;
    }
}

void button_quit(package_t *pk)
{
    if (pk->cos.x > 816 && pk->cos.x < 1104 && pk->cos.y > 749
        && pk->cos.y < 825){
            pk->mn->bqm.left = 192;
            sfSprite_setTextureRect(pk->mn->sqm, pk->mn->bqm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sqm, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->mn->bqm.left = 96;
            sfSprite_setTextureRect(pk->mn->sqm, pk->mn->bqm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sqm, NULL);
            }
        } else {
        pk->mn->bqm.left = 0;
        sfSprite_setTextureRect(pk->mn->sqm, pk->mn->bqm);
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sqm, NULL);
    }
    if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->mn->bqm.left == 96 || pk->mn->bqm.left == 192)) {
        sfRenderWindow_close(pk->sc->window);
    }
}
