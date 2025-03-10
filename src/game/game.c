/*
** EPITECH PROJECT, 2023
** game
** File description:
** game
*/

#include "../../include/my.h"

void backgame(package_t *pk)
{
    sfRenderWindow_drawSprite(pk->sc->window, pk->ga->sbg, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ga->ssave, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ct->spl, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ct->spl, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ga->spnj, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ga->sportal1, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ga->sportal2, NULL);
    printreaper(pk);
    printknights(pk);
    printrats(pk);
    printparagons(pk);
    sfRenderWindow_drawVertexArray(pk->sc->window, pk->DL->LVA, NULL);
    sfRenderWindow_drawVertexArray(pk->sc->window, pk->DL->SLVA, NULL);
    sfRenderWindow_drawRectangleShape(pk->sc->window, pk->ga->sto, NULL);
    if (pk->pa->i == 1)
        init_pause(pk);
}

void musicloop(package_t *pk)
{
    if (pk->ct->ppl.y <= 1973)
        pk->ga->cmusic = 1;
    else
        pk->ga->cmusic = 2;
    if (pk->ga->cmusic != pk->ga->pmusic) {
        pk->ga->pmusic = pk->ga->cmusic;
        if (pk->ga->cmusic == 1) {
            sfMusic_stop(pk->ga->mainmusic);
            sfMusic_stop(pk->ga->manormusic);
            sfMusic_play(pk->ga->gardenmusic);
        }
        if (pk->ga->cmusic == 2) {
            sfMusic_stop(pk->ga->mainmusic);
            sfMusic_stop(pk->ga->gardenmusic);
            sfMusic_play(pk->ga->manormusic);
        }
    }
}

void end(package_t *pk)
{
    sfFloatRect erect = sfRectangleShape_getGlobalBounds(pk->ga->rend);
    sfFloatRect prect = sfRectangleShape_getGlobalBounds(pk->ct->hitbox);
    if (sfFloatRect_intersects(&erect, &prect, NULL)) {
        pk->scene = 4;
        pk->ga->dialog = 0;
    }
    if (pk->ga->end == 0 && enemydead(pk) == 0) {
        pk->scene = 3;
        pk->ga->dialog = 0;
        pk->ga->end = 1;
    }
}

void coding_sytle(package_t *pk)
{
    end(pk);
    musicloop(pk);
    dgpv(pk);
    kickevent(pk);
}

void game(package_t *pk)
{
    enemyloop(pk);
    pk->ps = sfMouse_getPositionRenderWindow(pk->sc->window);
    pk->cos = sfRenderWindow_mapPixelToCoords(pk->sc->window, pk->ps, NULL);
    while (sfRenderWindow_pollEvent(pk->sc->window, &pk->sc->event)) {
        wclose(pk);
        ppause(pk);
        if (pk->pa->k == 1)
            button_opt(pk);
        kickcheck(pk);
        for_mouvement(pk);
        draw_inventory(pk);
    }
    coding_sytle(pk);
    change_position(pk);
    playerwalk(pk);
    draw_inventory2(pk);
    check_items(pk);
    save(pk);
    dead(pk);
}
