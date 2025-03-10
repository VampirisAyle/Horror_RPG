/*
** EPITECH PROJECT, 2023
** for_changing
** File description:
** for_change
*/


#include "../../include/my.h"

void pltp(package_t *pk)
{
    sfFloatRect phb = sfRectangleShape_getGlobalBounds(pk->ct->hitbox);
    sfFloatRect tpb1 = sfRectangleShape_getGlobalBounds(pk->ga->tpretss);
    sfFloatRect tpb2 = sfRectangleShape_getGlobalBounds(pk->ga->tprettop1);
    sfFloatRect tpb3 = sfRectangleShape_getGlobalBounds(pk->ga->tprettop2);
    if (sfFloatRect_intersects(&phb, &tpb1, NULL) || sfFloatRect_intersects
    (&phb, &tpb2, NULL)) {
        sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 2211 ;
        pk->ct->ppl.y = 2435;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125
            , pk->ct->ppl.y});
    } pltp2(pk, phb, tpb3);
}

void change_position_maindoor(package_t *pk, int x, int y)
{
    if (x <= (2225 + 94) && x >= 2225 && y <= (668 + 71) && y >= 668) {
        sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 150 ;
        pk->ct->ppl.y = 2428;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125
            , pk->ct->ppl.y});
    } if (x <= (35 + 94) && x >= 34 && y <= (2445 + 102) && y >= 2245) {
        sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 2225 ;
        pk->ct->ppl.y = 800;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125
            , pk->ct->ppl.y});
    }
}

void change_position_maindoor_2(package_t *pk, int x, int y)
{
    if (x <= (1206 + 140) && x >= 1206 && y <= (5173 + 57) && y >= 5173) {
        sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 135;
        pk->ct->ppl.y = 6276;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125
            , pk->ct->ppl.y});
    } if (x <= (0 + 90) && x >= 0 && y <= (6159 + 158) && y >= 6159) {
        sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 1259;
        pk->ct->ppl.y = 5065;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125
            , pk->ct->ppl.y});
    }
}

void change_position_maindoor_3(package_t *pk, int x, int y)
{
    if (x <= (2359 + 86) && x >= 2359 && y <= (2509 + 124) && y >= 2509) {
    sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 742;
        pk->ct->ppl.y = 3487;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125,
            pk->ct->ppl.y});
    }  if (x <= (2352 + 99) && x >= 2352 && y <= (2352 + 92) && y >= 2352) {
        sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 80;
        pk->ct->ppl.y = 4732;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125
            , pk->ct->ppl.y});
    }
}

void change_position(package_t *pk)
{
    int x = sfSprite_getPosition(pk->ct->spl).x + 62.5;
    int y = sfSprite_getPosition(pk->ct->spl).y + 50;
    change_position_maindoor(pk, x, y);
    change_position_maindoor_2(pk, x, y);
    change_position_maindoor_3(pk, x, y);
    pltp(pk);
}
