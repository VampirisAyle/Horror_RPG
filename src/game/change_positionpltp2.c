/*
** EPITECH PROJECT, 2023
** for_changing
** File description:
** for_change
*/


#include "../../include/my.h"

void pltp2(package_t *pk, sfFloatRect phb, sfFloatRect tpb3)
{
    if (sfFloatRect_intersects(&phb, &tpb3, NULL)) {
        sfRenderWindow_setView(pk->sc->window, pk->ct->view);
        pk->ct->ppl.x = 1245 ;
        pk->ct->ppl.y = 5012;
        if (sfSprite_getScale(pk->ct->spl).x == 2.5)
            sfSprite_setPosition(pk->ct->spl,pk->ct->ppl);
        if (sfSprite_getScale(pk->ct->spl).x == -2.5)
            sfSprite_setPosition(pk->ct->spl,(sfVector2f) {pk->ct->ppl.x + 125
            , pk->ct->ppl.y});
    }
}
