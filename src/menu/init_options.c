/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dsiplaysprite
*/

#include "../../include/my.h"

void option_cs(package_t *pk)
{
    sfSprite_setPosition(pk->opt->sctr, pk->opt->pctr);
    pk->opt->soff = sfSprite_create();
    pk->opt->toff = sfTexture_createFromFile("sprites/Button/off.png", NULL);
    sfSprite_setTexture(pk->opt->soff, pk->opt->toff, sfFalse);
    sfSprite_setScale(pk->opt->soff, (sfVector2f) {1.5, 1.5});
    pk->opt->poff = (sfVector2f) {445,530};
    sfSprite_setPosition(pk->opt->soff, pk->opt->poff);
    pk->opt->boff = (sfIntRect) {0, 0, 73, 24};
    sfSprite_setTextureRect(pk->opt->soff, pk->opt->boff);
    pk->opt->res = 1920;
    pk->opt->scon = sfSprite_create();
    pk->opt->tcon = sfTexture_createFromFile("sprites/Button/contr.png", NULL);
    sfSprite_setTexture(pk->opt->scon, pk->opt->tcon, sfFalse);
    sfSprite_setScale(pk->opt->scon, (sfVector2f) {3, 3});
    pk->opt->pcon = (sfVector2f) {80, 580};
    sfSprite_setPosition(pk->opt->scon, pk->opt->pcon);
}

void option_init(package_t *pk)
{
    sfSprite_setTexture(pk->opt->sqm, pk->opt->tqm, sfFalse);
    sfSprite_setScale(pk->opt->sqm, (sfVector2f) {1.5, 1.5});
    pk->opt->pqm = (sfVector2f) {445,480};
    sfSprite_setPosition(pk->opt->sqm, pk->opt->pqm);
    pk->opt->bqm = (sfIntRect) {0, 0, 73, 24};
    sfSprite_setTextureRect(pk->opt->sqm, pk->opt->bqm);
    pk->opt->sql = sfSprite_create();
    pk->opt->tql = sfTexture_createFromFile("sprites/Button/quall.png", NULL);
    sfSprite_setTexture(pk->opt->sql, pk->opt->tql, sfFalse);
    sfSprite_setScale(pk->opt->sql, (sfVector2f) {1.5, 1.5});
    pk->opt->pql = (sfVector2f) {260,530};
    sfSprite_setPosition(pk->opt->sql, pk->opt->pql);
    pk->opt->bql = (sfIntRect) {0, 0, 73, 24};
    sfSprite_setTextureRect(pk->opt->sql, pk->opt->bql);
    pk->opt->sctr = sfSprite_create();
    pk->opt->tctr = sfTexture_createFromFile("sprites/Button/ctr.png", NULL);
    sfSprite_setTexture(pk->opt->sctr, pk->opt->tctr, sfFalse);
    sfSprite_setScale(pk->opt->sctr, (sfVector2f) {0.8, 0.8});
    pk->opt->pctr = (sfVector2f) {293,655};
    option_cs(pk);
}

void init_opt(package_t *pk)
{
    sfSprite_setTextureRect(pk->opt->sgs, pk->opt->bgs);
    pk->opt->sls = sfSprite_create();
    pk->opt->tls = sfTexture_createFromFile("sprites/Button/1020.png", NULL);
    sfSprite_setTexture(pk->opt->sls, pk->opt->tls, sfFalse);
    sfSprite_setScale(pk->opt->sls, (sfVector2f) {1.5, 1.5});
    pk->opt->pls = (sfVector2f) {445,375};
    sfSprite_setPosition(pk->opt->sls, pk->opt->pls);
    pk->opt->bls = (sfIntRect) {0, 0, 73, 24};
    sfSprite_setTextureRect(pk->opt->sls, pk->opt->bls);
    pk->opt->sqh = sfSprite_create();
    pk->opt->tqh = sfTexture_createFromFile("sprites/Button/qualh.png", NULL);
    sfSprite_setTexture(pk->opt->sqh, pk->opt->tqh, sfFalse);
    sfSprite_setScale(pk->opt->sqh, (sfVector2f) {1.5, 1.5});
    pk->opt->pqh = (sfVector2f) {260,480};
    sfSprite_setPosition(pk->opt->sqh, pk->opt->pqh);
    pk->opt->bqh = (sfIntRect) {0, 0, 73, 24};
    sfSprite_setTextureRect(pk->opt->sqh, pk->opt->bqh);
    pk->opt->sqm = sfSprite_create();
    pk->opt->tqm = sfTexture_createFromFile("sprites/Button/qualm.png", NULL);
    option_init(pk);
}

void init_options(package_t *pk)
{
    pk->opt->sres = sfSprite_create();
    pk->opt->tres = sfTexture_createFromFile("sprites/Button/resol.png", NULL);
    sfSprite_setTexture(pk->opt->sres, pk->opt->tres, sfFalse);
    sfSprite_setScale(pk->opt->sres, (sfVector2f) {2.5, 2.5});
    pk->opt->pres = (sfVector2f) {130,310};
    sfSprite_setPosition(pk->opt->sres, pk->opt->pres);
    pk->opt->sdyn = sfSprite_create();
    pk->opt->tdyn = sfTexture_createFromFile("sprites/Button/light.png", NULL);
    sfSprite_setTexture(pk->opt->sdyn, pk->opt->tdyn, sfFalse);
    sfSprite_setScale(pk->opt->sdyn, (sfVector2f) {2.5, 2.5});
    pk->opt->pdyn = (sfVector2f) {135,420};
    sfSprite_setPosition(pk->opt->sdyn, pk->opt->pdyn);
    pk->opt->sgs = sfSprite_create();
    pk->opt->tgs = sfTexture_createFromFile("sprites/Button/1920.png", NULL);
    sfSprite_setTexture(pk->opt->sgs, pk->opt->tgs, sfFalse);
    sfSprite_setScale(pk->opt->sgs, (sfVector2f) {1.5, 1.5});
    pk->opt->pgs = (sfVector2f) {260,375};
    sfSprite_setPosition(pk->opt->sgs, pk->opt->pgs);
    pk->opt->bgs = (sfIntRect) {0, 0, 73, 24};
    init_opt(pk);
}

void options_button(package_t *pk)
{
    button_high(pk);
    button_med(pk);
    button_low(pk);
    button_off(pk);
    button_gs(pk);
    button_ls(pk);
}
