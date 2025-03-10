/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** inventory
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void mouse_on_case(package_t *pk, sfVector2f pos)
{
    sfSprite_setPosition(pk->iv->sca, pos);
    sfRenderWindow_drawSprite(pk->sc->window, pk->iv->sca, NULL);
}

sfVector2f inter2(sfVector2f mp, sfVector2f pos)
{
    if (mp.x >= 1249 && mp.x <= 1313 && mp.y >= 291 && mp.y <= 363) {
        pos.x += 1249 + 8;
        pos.y += 291 + 8;
    } if (mp.x >= 1305 && mp.x <= 1369 && mp.y >= 291 && mp.y <= 363) {
        pos.x += 1305 + 8;
        pos.y += 291 + 8;
    } if (mp.x >= 1363 && mp.x <= 1427 && mp.y >= 291 && mp.y <= 363) {
        pos.x += 1363 + 8;
        pos.y += 291 + 8;
    } if (mp.x >= 1421 && mp.x <= 1495 && mp.y >= 291 && mp.y <= 363) {
        pos.x += 1421 + 8;
        pos.y += 291 + 8;
    } if (mp.x >= 1249 && mp.x <= 1313 && mp.y >= 348 && mp.y <= 420) {
        pos.x += 1249 + 8;
        pos.y += 348 + 8;
    } if (mp.x >= 1305 && mp.x <= 1369 && mp.y >= 348 && mp.y <= 420) {
        pos.x += 1305 + 8;
        pos.y += 348 + 8;
    } pos = inter3(mp, pos);
    return (pos);
}

void interaction(package_t *pk)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(pk->sc->window);
    sfVector2f mp = sfRenderWindow_mapPixelToCoords(pk->sc->window, m, NULL);
    sfVector2f pos = {0, 0};
        if (mp.x >= 1249 && mp.x <= 1313 && mp.y >= 232 && mp.y <= 296) {
            pos.x += 1249 + 8;
            pos.y += 232 + 8;
        } if (mp.x >= 1305 && mp.x <= 1369 && mp.y >= 232 && mp.y <= 296) {
            pos.x += 1305 + 8;
            pos.y += 232 + 8;
        } if (mp.x >= 1363 && mp.x <= 1427 && mp.y >= 232 && mp.y <= 296) {
            pos.x += 1363 + 8;
            pos.y += 232 + 8;
        } if (mp.x >= 1421 && mp.x <= 1495 && mp.y >= 232 && mp.y <= 296) {
            pos.x += 1421 + 8;
            pos.y += 232 + 8;
        } pos = inter2(mp, pos);
        if (pos.x != 0) {
            mouse_on_case(pk, pos);
        }
}

void draw_inventory2(package_t *pk)
{
    sfView_setCenter(pk->ct->view,
    (sfVector2f) {pk->iv->pfi.x - 300, pk->iv->pfi.y + 450});
    sfRenderWindow_setView(pk->sc->window, pk->ct->view);
    if (pk->iv->ire == 1 && pk->iv->ivo == 96) {
        sfRenderWindow_drawSprite(pk->sc->window, pk->iv->sfi, NULL);
        interaction(pk);
        click_case(pk);
    } if (pk->iv->ire == 0 && pk->iv->ivo == 96) {
        sfRenderWindow_drawSprite(pk->sc->window, pk->iv->sfi, NULL);
        interaction(pk);
        click_case(pk);
    }
}

void draw_inventory(package_t *pk)
{
    if (pk->sc->event.type == sfEvtKeyPressed &&
    pk->sc->event.key.code == sfKeyI && pk->iv->ire == 0) {
        pk->iv->ire = 1;
    } if (pk->sc->event.type == sfEvtKeyReleased &&
        pk->sc->event.key.code == sfKeyI) {
            if (pk->iv->ivo == 96) {
                pk->iv->ivo = 0;
                pk->iv->cas = 0;
                return;
            } pk->iv->ivo = 96;
            pk->iv->ire = 0;
    }
}
