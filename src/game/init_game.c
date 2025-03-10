/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_jeu
*/

#include "../../include/my.h"

void init_save(package_t *pk)
{
    pk->ga->ssave = sfSprite_create();
    pk->ga->tsave = sfTexture_createFromFile("sprites/maps/Savep.png", NULL);
    sfSprite_setTexture(pk->ga->ssave, pk->ga->tsave, sfFalse);
    sfSprite_setPosition(pk->ga->ssave, (sfVector2f) {436, 2310});
    pk->ga->savebox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->ga->savebox, (sfVector2f) {436, 2310});
    sfRectangleShape_setSize(pk->ga->savebox, (sfVector2f) {48, 48});
}

void init_tpback(package_t *pk)
{
    pk->ga->tpretss = sfRectangleShape_create();
    pk->ga->tprettop1 = sfRectangleShape_create();
    pk->ga->tprettop2 = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->ga->tpretss, (sfVector2f) {579, 3454});
    sfRectangleShape_setPosition(pk->ga->tprettop1, (sfVector2f) {0, 4616});
    sfRectangleShape_setPosition(pk->ga->tprettop2, (sfVector2f) {0, 6101});
    sfRectangleShape_setSize(pk->ga->tpretss, (sfVector2f) {58, 37});
    sfRectangleShape_setSize(pk->ga->tprettop1, (sfVector2f) {45, 86});
    sfRectangleShape_setSize(pk->ga->tprettop2, (sfVector2f) {93, 102});
}

void init_cine(package_t *pk)
{
    pk->ga->sportal1 = sfSprite_create();
    pk->ga->sportal2 = sfSprite_create();
    pk->ga->tportal1 = sfTexture_createFromFile("sprites/maps/prt1.png", NULL);
    pk->ga->tportal2 = sfTexture_createFromFile("sprites/maps/prt2.png", NULL);
    sfSprite_setTexture(pk->ga->sportal1, pk->ga->tportal1, sfFalse);
    sfSprite_setTexture(pk->ga->sportal2, pk->ga->tportal2, sfFalse);
    sfSprite_setPosition(pk->ga->sportal1, (sfVector2f) {0, 0});
    sfSprite_setPosition(pk->ga->sportal2, (sfVector2f) {90, 0});
    pk->ga->sldportal = sfClock_create();
    pk->ga->cportal = 0;
    pk->ga->spnj = sfSprite_create();
    pk->ga->tpnj = sfTexture_createFromFile("sprites/maps/pnj.png", NULL);
    sfSprite_setTexture(pk->ga->spnj, pk->ga->tpnj, sfFalse);
    sfSprite_setScale(pk->ga->spnj, (sfVector2f) {-2.5, 2.5});
    sfSprite_setPosition(pk->ga->spnj, (sfVector2f) {4157, 1700});
    pk->ga->rend = sfRectangleShape_create();
    sfRectangleShape_setSize(pk->ga->rend, (sfVector2f) {86, 225});
    sfRectangleShape_setPosition(pk->ga->rend, (sfVector2f) {4232, 1594});
}

void init_viewport(package_t *pk)
{
    pk->ga->mainmenu = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfView_setViewport(pk->ga->mainmenu, (sfFloatRect) {0.01, 0.01, 1, 1});
    pk->ga->gui = sfView_createFromRect((sfFloatRect){2800, 2430, 1920, 1080});
    sfView_setViewport(pk->ga->gui, (sfFloatRect) {0.01, 0.01, 1, 1});
    pk->pa->pa = sfView_createFromRect((sfFloatRect) {3000, 3000, 1920, 1080});
    sfView_setViewport(pk->pa->pa, (sfFloatRect) {0.4, 0.2, 1, 1});
    pk->ga->inv = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    sfView_setViewport(pk->ga->inv, (sfFloatRect) {0.6, 0.2, 1, 1});
    pk->ga->ta = sfView_createFromRect((sfFloatRect) {3495, 3495, 1920, 1080});
    sfView_setViewport(pk->ga->ta, (sfFloatRect) {0.008, 0.755, 1, 1});
    pk->ga->pmusic = 0;
    pk->ga->cmusic = 0;
    pk->ga->dialog = 0;
    pk->ga->end = 0;
    sfRectangleShape_setPosition(pk->ct->hitbox, (sfVector2f) {(pk->ct->ppl.x
    + 45), (pk->ct->ppl.y + 20)});
    init_cine(pk);
    init_tpback(pk);
    init_save(pk);
}

void init_game(package_t *pk)
{
    pk->ga->sbg = sfSprite_create();
    pk->ga->tbg = sfTexture_createFromFile("sprites/maps/mapi.png", NULL);
    sfSprite_setTexture(pk->ga->sbg, pk->ga->tbg, sfFalse);
    pk->ga->pbg = (sfVector2f) {0,0};
    sfSprite_setPosition(pk->ga->sbg, pk->ga->pbg);
    pk->ga->sbghb = sfSprite_create();
    pk->ga->ibghb = sfImage_createFromFile("sprites/maps/maphbcl.png");
    pk->ga->tbghb = sfTexture_createFromImage(pk->ga->ibghb, NULL);
    sfSprite_setTexture(pk->ga->sbghb, pk->ga->tbghb, sfFalse);
    sfSprite_setPosition(pk->ga->sbghb, (sfVector2f) {0,0});
    pk->pa->bres = (sfIntRect) {0, 0, 96, 24};
    pk->ga->alivesave2 = malloc(9 * sizeof(char));
    init_talk(pk);
    init_viewport(pk);
    init_txt(pk);
}
