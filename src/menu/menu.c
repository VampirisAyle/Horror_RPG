/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void draw_options_main(package_t *pk)
{
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sod, NULL);
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

void draw_credits(package_t *pk)
{

    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->scd, NULL);
    pk->mn->te = sfText_create();
    pk->mn->fe = sfFont_createFromFile("sprites/font.ttf");
    sfText_setFont(pk->mn->te, pk->mn->fe);
    sfText_setFillColor(pk->mn->te, sfWhite);
    sfText_setPosition(pk->mn->te, (sfVector2f) {1335,320});
    sfText_setString(pk->mn->te, "Maxime Dietrich");
    sfText_setScale(pk->mn->te, (sfVector2f) {1.5,1.5});
    sfRenderWindow_drawText(pk->sc->window, pk->mn->te, NULL);
    sfText_setString(pk->mn->te, "\n\nLouis Lorrain Marechal");
    sfRenderWindow_drawText(pk->sc->window, pk->mn->te, NULL);
    sfText_setString(pk->mn->te, "\n\n\n\nYounes Elotmani");
    sfRenderWindow_drawText(pk->sc->window, pk->mn->te, NULL);
    sfText_setString(pk->mn->te, "\n\n\n\n\n\nDaniil Danilovskii");
    sfRenderWindow_drawText(pk->sc->window, pk->mn->te, NULL);
}

void backmenu(package_t *pk)
{
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sbm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->slm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->sqm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->scm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->snm, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->som, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->mn->stest, NULL);
    if (pk->mn->s == 1) {
        draw_options_main(pk);
    } if (pk->mn->s == 2)
        draw_credits(pk);
    }

void menu(package_t *pk)
{
    pk->ps = sfMouse_getPositionRenderWindow(pk->sc->window);
    pk->cos = sfRenderWindow_mapPixelToCoords(pk->sc->window, pk->ps, NULL);
    while (sfRenderWindow_pollEvent(pk->sc->window, &pk->sc->event)) {
        wclose(pk);
        button_lg(pk);
        button_ns(pk);
        button_options(pk);
        button_credits(pk);
        button_quit(pk);
        if (pk->mn->s == 1)
            options_button(pk);
    }
}
