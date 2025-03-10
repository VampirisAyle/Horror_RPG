/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu_pause
*/

#include "../../../include/my.h"

void draw_pause(package_t *pk, sfSprite *spause)
{
    sfSprite_setPosition(pk->mn->som, pk->mn->pom);
    sfSprite_setScale(pk->mn->som, (sfVector2f){2.8,2.8});
    pk->mn->pod = (sfVector2f) {3604,3000};
    sfSprite_setPosition(pk->mn->sod, pk->mn->pod);
    sfRenderWindow_drawSprite(pk->sc->window, spause, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->pa->sres, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sqm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sqm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->som, NULL);
    if (pk->pa->k == 1) {
        sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sod, NULL);
        init_options_pause(pk);
    }
    event_pause(pk);
}

void init_pause(package_t *pk)
{
    sfRenderWindow_setView(pk->sc->window, pk->pa->pa);
    sfSprite *spause = sfSprite_create();
    sfTexture *tp = sfTexture_createFromFile("sprites/Button/PFond.png", NULL);
    sfSprite_setPosition(spause, (sfVector2f) {3000, 3000});
    sfSprite_setTexture(spause, tp, sfFalse);
    sfSprite_setScale(spause, (sfVector2f) {4, 4});
    pk->pa->sres = sfSprite_create();
    pk->pa->tres = sfTexture_createFromFile("sprites/Button/res.png", NULL);
    sfSprite_setPosition(pk->pa->sres, (sfVector2f) {3070, 3110});
    sfSprite_setTexture(pk->pa->sres, pk->pa->tres, sfFalse);
    sfSprite_setScale(pk->pa->sres, (sfVector2f) {2.8, 2.8});
    sfSprite_setTextureRect(pk->pa->sres, pk->pa->bres);
    pk->mn->pqm = (sfVector2f) {3070, 3500};
    sfSprite_setPosition(pk->mn->sqm, pk->mn->pqm);
    sfSprite_setScale(pk->mn->sqm, (sfVector2f){2.8,2.8});
    pk->mn->pom = (sfVector2f) {3070, 3300};
    draw_pause(pk, spause);

}

void ppause(package_t *pk)
{
    if (pk->sc->event.type == sfEvtKeyPressed) {
        if (pk->sc->event.key.code == sfKeyEscape && pk->pa->j == 0) {
            pk->pa->j = 1;
            pk->pa->i = 1;
        }
    }
    if (pk->sc->event.type == sfEvtKeyReleased) {
        if (pk->sc->event.key.code == sfKeyEscape && pk->pa->j == 1)
            pk->pa->j = 2;
    }
    if (pk->sc->event.type == sfEvtKeyPressed) {
        if (pk->sc->event.key.code == sfKeyEscape && pk->pa->j == 2) {
            pk->pa->j = 0;
            pk->pa->i = 0;
            }
        }
}
