/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu
*/

#include "../../include/my.h"
#include "../../include/struct.h"
void init_menu_opt(package_t *pk)
{
    init_options(pk);
    init_talk(pk);
}

void init_view(package_t *pk)
{
    pk->mn->stest = sfSprite_create();
    pk->mn->ttest = sfTexture_createFromFile("sprites/Button/title2.png", NULL);
    sfSprite_setScale(pk->mn->stest, (sfVector2f) {5, 5});
    sfSprite_setTexture(pk->mn->stest, pk->mn->ttest, sfFalse);
    pk->mn->ptest = (sfVector2f) {300,100};
    sfSprite_setPosition(pk->mn->stest, pk->mn->ptest);
    pk->mn->s = 0;
    pk->ct->view = sfView_create();
    sfView_setSize(pk->ct->view, (sfVector2f) {1920, 1080});
    pk->ga->mainmusic = sfMusic_createFromFile("sounds/music/menu.ogg");
    sfMusic_setLoop(pk->ga->mainmusic, sfTrue);
    pk->ga->gardenmusic = sfMusic_createFromFile("sounds/music/garden.ogg");
    sfMusic_setLoop(pk->ga->gardenmusic, sfTrue);
    sfMusic_setVolume(pk->ga->gardenmusic, 50);
    pk->ga->manormusic = sfMusic_createFromFile("sounds/music/garden.ogg");
    sfMusic_setLoop(pk->ga->manormusic, sfTrue);
    pk->ga->bossmusic = sfMusic_createFromFile("sounds/music/bossfight.ogg");
    sfMusic_setLoop(pk->ga->bossmusic, sfTrue);
    sfMusic_play(pk->ga->mainmusic);
    init_menu_opt(pk);
}

void cstmtc(package_t *pk)
{
    pk->mn->tqm = sfTexture_createFromFile("sprites/Button/quit.png", NULL);
    sfSprite_setTexture(pk->mn->sqm, pk->mn->tqm, sfFalse);
    pk->mn->pqm = (sfVector2f) {816,750};
    sfSprite_setScale(pk->mn->sqm, (sfVector2f) {3, 3});
    sfSprite_setPosition(pk->mn->sqm, pk->mn->pqm);
    pk->mn->bqm = (sfIntRect) {0, 0, 96, 24};
    sfSprite_setTextureRect(pk->mn->sqm, pk->mn->bqm);
    pk->mn->sod = sfSprite_create();
    pk->mn->tod = sfTexture_createFromFile("sprites/Button/OFond.png", NULL);
    sfSprite_setTexture(pk->mn->sod, pk->mn->tod, sfFalse);
    pk->mn->pod = (sfVector2f) {200,220};
    sfSprite_setPosition(pk->mn->sod, pk->mn->pod);
    sfSprite_setScale(pk->mn->sod, (sfVector2f){4, 4});
    pk->mn->scd = sfSprite_create();
    pk->mn->tcd = sfTexture_createFromFile("sprites/Button/CFond.png", NULL);
    sfSprite_setTexture(pk->mn->scd, pk->mn->tcd, sfFalse);
    pk->mn->pcd = (sfVector2f) {1300,220};
    sfSprite_setPosition(pk->mn->scd, pk->mn->pcd);
    sfSprite_setScale(pk->mn->scd, (sfVector2f){4, 4});
    init_view(pk);
}

void init_button(package_t *pk)
{
    pk->mn->bnm = (sfIntRect) {0, 0, 96, 24};
    sfSprite_setTextureRect(pk->mn->snm, pk->mn->bnm);
    pk->mn->som = sfSprite_create();
    pk->mn->tom = sfTexture_createFromFile("sprites/Button/options.png", NULL);
    sfSprite_setTexture(pk->mn->som, pk->mn->tom, sfFalse);
    sfSprite_setScale(pk->mn->som, (sfVector2f) {3, 3});
    pk->mn->pom = (sfVector2f) {816,500};
    sfSprite_setPosition(pk->mn->som, pk->mn->pom);
    pk->mn->bom = (sfIntRect) {0, 0, 96, 24};
    sfSprite_setTextureRect(pk->mn->som, pk->mn->bom);
    pk->mn->scm = sfSprite_create();
    pk->mn->tcm = sfTexture_createFromFile("sprites/Button/credits.png", NULL);
    sfSprite_setTexture(pk->mn->scm, pk->mn->tcm, sfFalse);
    pk->mn->pcm = (sfVector2f) {816,625};
    sfSprite_setScale(pk->mn->scm, (sfVector2f) {3, 3});
    sfSprite_setPosition(pk->mn->scm, pk->mn->pcm);
    pk->mn->bcm = (sfIntRect) {0, 0, 96, 24};
    sfSprite_setTextureRect(pk->mn->scm, pk->mn->bcm);
    pk->mn->sqm = sfSprite_create();
    cstmtc(pk);
}

void init_menu(package_t *pk)
{
    pk->mn->sbm = sfSprite_create();
    pk->mn->tbm = sfTexture_createFromFile("sprites/maps/bgmenu.jpg", NULL);
    sfSprite_setTexture(pk->mn->sbm, pk->mn->tbm, sfFalse);
    pk->mn->pbm = (sfVector2f) {0,0};
    sfSprite_setPosition(pk->mn->sbm, pk->mn->pbm);
    pk->mn->slm = sfSprite_create();
    pk->mn->tlm = sfTexture_createFromFile("sprites/Button/Lsave.png", NULL);
    sfSprite_setTexture(pk->mn->slm, pk->mn->tlm, sfFalse);
    pk->mn->plm = (sfVector2f) {816,250};
    sfSprite_setScale(pk->mn->slm, (sfVector2f) {3, 3});
    sfSprite_setPosition(pk->mn->slm, pk->mn->plm);
    pk->mn->blm = ((sfIntRect){0, 0, 96, 24});
    sfSprite_setTextureRect(pk->mn->slm, pk->mn->blm);
    pk->mn->snm = sfSprite_create();
    pk->mn->tnm = sfTexture_createFromFile("sprites/Button/Nsave.png", NULL);
    sfSprite_setTexture(pk->mn->snm, pk->mn->tnm, sfFalse);
    pk->mn->pnm = (sfVector2f) {816, 375};
    sfSprite_setScale(pk->mn->snm, (sfVector2f) {3, 3});
    sfSprite_setPosition(pk->mn->snm, pk->mn->pnm);
    init_button(pk);
}
