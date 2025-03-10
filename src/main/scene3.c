/*
** EPITECH PROJECT, 2022
** main
** File description:
** main function
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include <stdio.h>
#include <stdlib.h>

void dial3(package_t *pk)
{
    if (pk->ga->dialog == 0) {
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[13]);
        sfSprite_setPosition(pk->ga->sportal2, (sfVector2f) {0, 0});
        pk->ga->ibghb = sfImage_createFromFile("sprites/maps/maphbop.png");
        sfRectangleShape_setFillColor(pk->ga->bbg,
        sfColor_fromRGBA(0, 0, 0, 0));
        sfText_setFillColor(pk->ga->tcinema,
        sfColor_fromRGBA(0, 255, 0, 0));
    }
    if (pk->ga->dialog == 1)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[14]);
    if (pk->ga->dialog == 2) {
        pk->scene = 2;
        pk->ga->dialog = 0;
    }
    sfText_setFillColor(pk->ga->talk, sfGreen);
    sfRenderWindow_setView(pk->sc->window, pk->ga->ta);
    sfRenderWindow_drawRectangleShape(pk->sc->window, pk->ga->sto, NULL);
    sfRenderWindow_drawText(pk->sc->window, pk->ga->talk, NULL);
    sfRenderWindow_setView(pk->sc->window, pk->ga->ta);
}

void dialclick3(package_t *pk)
{
    if (pk->sc->event.type == sfEvtMouseButtonPressed
    && pk->sc->event.mouseButton.button == sfMouseLeft) {
        pk->ga->dialog++;
    }
}

void gamec3(package_t *pk)
{
    pk->ps = sfMouse_getPositionRenderWindow(pk->sc->window);
    pk->cos = sfRenderWindow_mapPixelToCoords(pk->sc->window, pk->ps, NULL);
    while (sfRenderWindow_pollEvent(pk->sc->window, &pk->sc->event)) {
        wclose(pk);
        dialclick3(pk);
    }
    musicloop(pk);
}

void scene_3(package_t *pk)
{
    sfView_setCenter(pk->ct->view,
    (sfVector2f) {pk->ct->ppl.x + 75, pk->ct->ppl.y + 52});
    sfRenderWindow_setView(pk->sc->window, pk->ct->view);
    backgame(pk);
    sfRenderWindow_drawText(pk->sc->window, pk->ga->tcinema, NULL);
    gamec3(pk);
    sfRenderWindow_setView(pk->sc->window, pk->ga->gui);
    sfRenderWindow_setView(pk->sc->window, pk->pa->pa);
    dial3(pk);
}
