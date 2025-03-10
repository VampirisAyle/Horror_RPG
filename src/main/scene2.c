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

void dial2(package_t *pk)
{
    if (pk->ga->dialog == 6)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[3]);
    if (pk->ga->dialog == 7)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[4]);
    if (pk->ga->dialog == 8)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[5]);
    if (pk->ga->dialog == 9)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[6]);
    if (pk->ga->dialog == 10)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[7]);
    if (pk->ga->dialog == 11)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[8]);
    if (pk->ga->dialog == 12)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[9]);
    if (pk->ga->dialog == 13)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[10]);
    if (pk->ga->dialog == 14)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[11]);
    if (pk->ga->dialog == 15)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[12]);
}

void dial(package_t *pk)
{
    if (pk->ga->dialog == 5)
        sfText_setString(pk->ga->talk, pk->ga->dialoglist[2]);
    dial2(pk);
    if (pk->ga->dialog == 16) {
        pk->scene = 2;
        pk->ga->dialog = 0;
        enemyalive(pk);
        pk->ga->save = 1;
        save(pk);
        pk->ga->save = 0;
    }
    sfText_setFillColor(pk->ga->talk, sfGreen);
    if (pk->ga->dialog >= 5) {
        sfRenderWindow_setView(pk->sc->window, pk->ga->ta);
        sfRenderWindow_drawRectangleShape(pk->sc->window, pk->ga->sto, NULL);
        sfRenderWindow_drawText(pk->sc->window, pk->ga->talk, NULL);
        sfRenderWindow_setView(pk->sc->window, pk->ga->ta);
    }
}

void dialclick(package_t *pk)
{
    if (pk->sc->event.type == sfEvtMouseButtonPressed
    && pk->sc->event.mouseButton.button == sfMouseLeft) {
        pk->ga->dialog++;
    }
}

void gamec(package_t *pk)
{
    pk->ps = sfMouse_getPositionRenderWindow(pk->sc->window);
    pk->cos = sfRenderWindow_mapPixelToCoords(pk->sc->window, pk->ps, NULL);
    while (sfRenderWindow_pollEvent(pk->sc->window, &pk->sc->event)) {
        wclose(pk);
        dialclick(pk);
    }
    cinem(pk);
    musicloop(pk);
}

void scene_2(package_t *pk)
{
    sfView_setCenter(pk->ct->view,
    (sfVector2f) {pk->ct->ppl.x + 75, pk->ct->ppl.y + 52});
    sfRenderWindow_setView(pk->sc->window, pk->ct->view);
    backgame(pk);
    sfRenderWindow_drawRectangleShape(pk->sc->window, pk->ga->bbg, NULL);
    sfRenderWindow_drawText(pk->sc->window, pk->ga->tcinema, NULL);
    gamec(pk);
    sfRenderWindow_setView(pk->sc->window, pk->pa->pa);
    dial(pk);
}
