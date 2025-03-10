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

void dialclick4(package_t *pk)
{
    if (pk->sc->event.type == sfEvtMouseButtonPressed
    && pk->sc->event.mouseButton.button == sfMouseLeft) {
        pk->ga->dialog++;
    }
}

void gamec4(package_t *pk)
{
    pk->ps = sfMouse_getPositionRenderWindow(pk->sc->window);
    pk->cos = sfRenderWindow_mapPixelToCoords(pk->sc->window, pk->ps, NULL);
    while (sfRenderWindow_pollEvent(pk->sc->window, &pk->sc->event)) {
        wclose(pk);
        dialclick4(pk);
    }
    cinem4(pk);
    musicloop(pk);
}

void endreset_2(package_t *pk)
{
    pk->ga->cmusic = 0;
    pk->ga->pmusic = 0;
    pk->mn->s = 0;
    pk->mn->pom = (sfVector2f) {816,500};
    sfSprite_setPosition(pk->mn->som, pk->mn->pom);
    sfSprite_setScale(pk->mn->som, (sfVector2f) {3, 3});
    pk->mn->pqm = (sfVector2f) {816,750};
    sfSprite_setPosition(pk->mn->sqm, pk->mn->pqm);
    sfSprite_setScale(pk->mn->sqm, (sfVector2f) {3, 3});
}

void endreset(package_t *pk)
{
    sfRenderWindow_setView(pk->sc->window, pk->ga->mainmenu);
    pk->ct->ppl = (sfVector2f) {3920,1560};
    sfSprite_setPosition(pk->ct->spl, pk->ct->ppl);
    pk->ga->dialog = 0;
    sfRectangleShape_setPosition(pk->ct->hitbox, (sfVector2f) {(pk->ct->ppl.x
    + 45), (pk->ct->ppl.y + 20)});
    pk->ct->mvr = 0;
    pk->ct->mvt = 0;
    pk->ct->mvd = 0;
    pk->ct->bpl = (sfIntRect) {0, 0, 50, 36};
    sfSprite_setTextureRect(pk->ct->spl, pk->ct->bpl);
    dlight(300, 45, (sfVector2f) {pk->ct->ppl.x + 75, pk->ct->ppl.y + 54},
    pk);
    pk->ga->cportal = 0;
    pk->ga->ibghb = sfImage_createFromFile("sprites/maps/maphbcl.png");
    sfMusic_stop(pk->ga->manormusic);
    sfMusic_stop(pk->ga->gardenmusic);
    sfMusic_play(pk->ga->mainmusic);
    endreset_2(pk);
}

void scene_4(package_t *pk)
{
    sfView_setCenter(pk->ct->view,
    (sfVector2f) {pk->ct->ppl.x + 75, pk->ct->ppl.y + 52});
    sfRenderWindow_setView(pk->sc->window, pk->ct->view);
    backgame(pk);
    sfRenderWindow_drawRectangleShape(pk->sc->window, pk->ga->bbg, NULL);
    sfRenderWindow_drawText(pk->sc->window, pk->ga->tcinema, NULL);
    gamec4(pk);
    sfRenderWindow_setView(pk->sc->window, pk->ga->gui);
    sfRenderWindow_setView(pk->sc->window, pk->pa->pa);
    if (pk->scene == 0)
        endreset(pk);
}
