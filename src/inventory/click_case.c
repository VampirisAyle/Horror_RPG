/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** inventory
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void place_the_sprite(package_t *pk, sfVector2f pos)
{
    sfSprite_setPosition(pk->iv->scb, pos);
    sfRenderWindow_drawSprite(pk->sc->window, pk->iv->scb, NULL);
    use_p(pk);
}

void get_cases_nb1(package_t *pk)
{
    if (pk->iv->mp.x >= 1363 && pk->iv->mp.x <= 1427 &&
    pk->iv->mp.y >= 232 && pk->iv->mp.y <= 296 && CO & ND) {
        pk->iv->cas = 3;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1421 && pk->iv->mp.x <= 1495 &&
    pk->iv->mp.y >= 232 && pk->iv->mp.y <= 296 && CO & ND) {
        pk->iv->cas = 4;
        pk->iv->condition++;
    } get_cases_nb2(pk);
}

sfVector2f coresp_pos(package_t *pk, sfVector2f pos)
{
    if (pk->iv->cas == 1) {
        pos.x += 1249;
        pos.y += 232;
    } if (pk->iv->cas == 2) {
        pos.x += 1305;
        pos.y += 232;
    } if (pk->iv->cas == 3) {
        pos.x += 1363;
        pos.y += 232;
    } if (pk->iv->cas == 4) {
        pos.x += 1421;
        pos.y += 232;
    } pos = coresp_pos2(pk, pos);
    return (pos);
}

void cases(package_t *pk)
{
    pk->iv->condition = 0;
    sfVector2i m = sfMouse_getPositionRenderWindow(pk->sc->window);
    pk->iv->mp = sfRenderWindow_mapPixelToCoords(pk->sc->window, m, NULL);
    sfVector2f pos = {0, 0};
    if (pk->iv->mp.x >= 1249 && pk->iv->mp.x <= 1313 &&
    pk->iv->mp.y >= 232 && pk->iv->mp.y <= 296 && CO & ND) {
        pk->iv->cas = 1;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1305 && pk->iv->mp.x <= 1369 &&
    pk->iv->mp.y >= 232 && pk->iv->mp.y <= 296 && CO & ND) {
        pk->iv->cas = 2;
        pk->iv->condition++;
    } get_cases_nb1(pk);
    if (pk->iv->condition == 0 && CO & ND) {
        pk->iv->cas = 0;
    } pos = coresp_pos(pk, pos);
    if (pk->iv->cas != 0) {
        place_the_sprite(pk, pos);
    }
}

void click_case(package_t *pk)
{
    sfView_setCenter(pk->ct->view,
    (sfVector2f) {pk->iv->pfi.x - 300, pk->iv->pfi.y + 450});
    sfRenderWindow_setView(pk->sc->window, pk->ct->view);
    if (pk->sc->event.type == sfEvtMouseButtonPressed &&
    pk->sc->event.mouseButton.button == sfMouseLeft &&
    pk->iv->icc == 0) {
        pk->iv->icc = 1;
    } if (pk->sc->event.type == sfEvtMouseButtonReleased &&
    pk->sc->event.mouseButton.button == sfMouseLeft) {
        pk->iv->icc = 0;
    } if (pk->iv->icc == 0) {
        cases(pk);
    }
}
