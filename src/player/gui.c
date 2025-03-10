/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** gui
*/

#include "../../include/my.h"

void init_vie(package_t *pk)
{
    pk->ct->sst = sfSprite_create();
    pk->ct->tst = sfTexture_createFromFile("sprites/Gui/PE.png", NULL);
    sfSprite_setTexture(pk->ct->sst, pk->ct->tst, sfFalse);
    pk->ct->pst = (sfVector2f) {2800,2500};
    sfSprite_setPosition(pk->ct->sst, pk->ct->pst);
    sfSprite_setScale(pk->ct->sst, (sfVector2f){2, 2});
    pk->ct->bst = (sfIntRect) {0, 0, 190, 22};
    sfSprite_setTextureRect(pk->ct->sst, pk->ct->bst);
    pk->ct->sfo = sfSprite_create();
    sfSprite_setTexture(pk->ct->sfo, pk->ct->tca, sfFalse);
    pk->ct->pfo = (sfVector2f) {2800,2500};
    sfSprite_setPosition(pk->ct->sfo, pk->ct->pfo);
    sfSprite_setScale(pk->ct->sfo, (sfVector2f){2, 2});
}

void init_gui(package_t *pk)
{
    pk->ct->spv = sfSprite_create();
    pk->ct->tpv = sfTexture_createFromFile("sprites/Gui/PV.png", NULL);
    sfSprite_setTexture(pk->ct->spv, pk->ct->tpv, sfFalse);
    pk->ct->ppv = (sfVector2f) {2800,2430};
    sfSprite_setPosition(pk->ct->spv, pk->ct->ppv);
    sfSprite_setScale(pk->ct->spv, (sfVector2f){2, 2});
    pk->ct->bpv = (sfIntRect) {0, 0, 190, 22};
    sfSprite_setTextureRect(pk->ct->spv, pk->ct->bpv);
    pk->ct->sca = sfSprite_create();
    pk->ct->tca = sfTexture_createFromFile("sprites/Gui/Cadre.png", NULL);
    sfSprite_setTexture(pk->ct->sca, pk->ct->tca, sfFalse);
    pk->ct->pca = (sfVector2f) {2800,2430};
    sfSprite_setPosition(pk->ct->sca, pk->ct->pca);
    sfSprite_setScale(pk->ct->sca, (sfVector2f){2, 2});
    pk->ct->hp = 100;
    init_vie(pk);
}

void dead(package_t *pk)
{
    if (sfSprite_getTextureRect(pk->ct->spv).width <= 0) {
        pk->ct->bpv = (sfIntRect) {0, 0, 190, 22};
        sfSprite_setTextureRect(pk->ct->spv, pk->ct->bpv);
        loadsave(pk);
    }
}

void dgpv(package_t *pk)
{
    while (pk->ct->deg > 0) {
        pk->ct->hp -= pk->ct->deg;
        pk->ct->bpv.width -= pk->ct->deg;
        pk->ct->deg = 0;
        sfSprite_setTextureRect(pk->ct->spv, pk->ct->bpv);
    }
}
