/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button_options
*/

#include "../../include/my.h"

void button_ls(package_t *pk)
{
    if (pk->cos.x > 444 && pk->cos.x < 554 && pk->cos.y > 374
        && pk->cos.y < 414){
            pk->opt->bls.left = 144;
            sfSprite_setTextureRect(pk->opt->sls, pk->opt->bls);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sls, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->opt->bls.left = 72;
            sfSprite_setTextureRect(pk->opt->sls, pk->opt->bls);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sls, NULL);
            }
        } else {
        pk->opt->bls.left = 0;
        sfSprite_setTextureRect(pk->opt->sls, pk->opt->bls);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sls, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->opt->bls.left == 72 || pk->opt->bls.left == 144)) {
        sfSprite_setTextureRect(pk->opt->sls, pk->opt->bls);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sls, NULL);
        pk->opt->res = 1020;
    }
}
