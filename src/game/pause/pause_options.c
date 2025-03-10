/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** draw button pause
*/

#include "../../../include/my.h"

void draw_options_pause(package_t *pk)
{
    pk->opt->pcon = (sfVector2f) {3484,3360};
    sfSprite_setPosition(pk->opt->scon, pk->opt->pcon);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sres, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sls, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sgs, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sdyn, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqh, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sql, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->soff, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sctr, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->opt->scon, NULL);
}

void init_options_pause(package_t *pk)
{
    pk->opt->pres = (sfVector2f) {3534,3110};
    sfSprite_setPosition(pk->opt->sres, pk->opt->pres);
    pk->opt->pdyn = (sfVector2f) {3534,3210};
    sfSprite_setPosition(pk->opt->sdyn, pk->opt->pdyn);
    pk->opt->pgs = (sfVector2f) {3664,3165};
    sfSprite_setPosition(pk->opt->sgs, pk->opt->pgs);
    pk->opt->pls = (sfVector2f) {3849,3165};
    sfSprite_setPosition(pk->opt->sls, pk->opt->pls);
    pk->opt->pqh = (sfVector2f) {3664,3270};
    sfSprite_setPosition(pk->opt->sqh, pk->opt->pqh);
    pk->opt->pqm = (sfVector2f) {3849,3270};
    sfSprite_setPosition(pk->opt->sqm, pk->opt->pqm);
    pk->opt->pql = (sfVector2f) {3664,3320};
    sfSprite_setPosition(pk->opt->sql, pk->opt->pql);
    pk->opt->pctr = (sfVector2f) {3697,3435};
    sfSprite_setPosition(pk->opt->sctr, pk->opt->pctr);
    pk->opt->poff = (sfVector2f) {3849,3320};
    sfSprite_setPosition(pk->opt->soff, pk->opt->poff);
    draw_options_pause(pk);
}

void pause_ls(package_t *pk)
{
    if (pk->cos.x > 3849 && pk->cos.x < 3959 && pk->cos.y > 3165
        && pk->cos.y < 3205){
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

void button_opt(package_t *pk)
{
    pause_high(pk);
    pause_med(pk);
    pause_low(pk);
    pause_off(pk);
    pause_gs(pk);
    pause_ls(pk);
}
