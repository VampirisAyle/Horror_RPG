/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button options
*/

#include "../../../include/my.h"

void pause_high(package_t *pk)
{
    if (pk->cos.x > 3664 && pk->cos.x < 3774 && pk->cos.y > 3270
        && pk->cos.y < 3310){
            pk->opt->bqh.left = 144;
            sfSprite_setTextureRect(pk->opt->sqh, pk->opt->bqh);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqh, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->opt->bqh.left = 72;
            sfSprite_setTextureRect(pk->opt->sqh, pk->opt->bqh);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqh, NULL);
            }} else {
        pk->opt->bqh.left = 0;
        sfSprite_setTextureRect(pk->opt->sqh, pk->opt->bqh);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqh, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->opt->bqh.left == 72 || pk->opt->bqh.left == 144)) {
        sfSprite_setTextureRect(pk->opt->sqh, pk->opt->bqh);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqh, NULL);
        pk->opt->light = 45;
        pk->opt->lightof = 0;
    }}

void pause_med(package_t *pk)
{
    if (pk->cos.x > 3849 && pk->cos.x < 3959 && pk->cos.y > 3270
        && pk->cos.y < 3310){
            pk->opt->bqm.left = 144;
            sfSprite_setTextureRect(pk->opt->sqm, pk->opt->bqm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqm, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->opt->bqm.left = 72;
            sfSprite_setTextureRect(pk->opt->sqm, pk->opt->bqm);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqm, NULL);
            }} else {
        pk->opt->bqm.left = 0;
        sfSprite_setTextureRect(pk->opt->sqm, pk->opt->bqm);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqm, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->opt->bqm.left == 72 || pk->opt->bqm.left == 144)) {
        sfSprite_setTextureRect(pk->opt->sqm, pk->opt->bqm);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sqm, NULL);
        pk->opt->light = 18;
        pk->opt->lightof = 0;
    }}

void pause_low(package_t *pk)
{
    if (pk->cos.x > 3664 && pk->cos.x < 3774 && pk->cos.y > 3320
        && pk->cos.y < 3360){
            pk->opt->bql.left = 144;
            sfSprite_setTextureRect(pk->opt->sql, pk->opt->bql);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sql, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->opt->bql.left = 72;
            sfSprite_setTextureRect(pk->opt->sql, pk->opt->bql);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sql, NULL);
            }} else {
        pk->opt->bql.left = 0;
        sfSprite_setTextureRect(pk->opt->sql, pk->opt->bql);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sql, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->opt->bql.left == 72 || pk->opt->bql.left == 144)) {
        sfSprite_setTextureRect(pk->opt->sql, pk->opt->bql);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sql, NULL);
        pk->opt->light = 8;
        pk->opt->lightof = 0;
    }}

void pause_off(package_t *pk)
{
    if (pk->cos.x > 3849 && pk->cos.x < 3959 && pk->cos.y > 3320
        && pk->cos.y < 3360){
            pk->opt->boff.left = 144;
            sfSprite_setTextureRect(pk->opt->soff, pk->opt->boff);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->soff, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->opt->boff.left = 72;
            sfSprite_setTextureRect(pk->opt->soff, pk->opt->boff);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->soff, NULL);
            }} else {
        pk->opt->boff.left = 0;
        sfSprite_setTextureRect(pk->opt->soff, pk->opt->boff);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->soff, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->opt->boff.left == 72 || pk->opt->boff.left == 144)) {
        sfSprite_setTextureRect(pk->opt->soff, pk->opt->boff);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->soff, NULL);
        pk->opt->light = 45;
        pk->opt->lightof = 1;
    }}

void pause_gs(package_t *pk)
{
    if (pk->cos.x > 3664 && pk->cos.x < 3774 && pk->cos.y > 3165
        && pk->cos.y < 3205){
            pk->opt->bgs.left = 144;
            sfSprite_setTextureRect(pk->opt->sgs, pk->opt->bgs);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sgs, NULL);
            if (pk->sc->event.type == sfEvtMouseButtonPressed) {
            pk->opt->bgs.left = 72;
            sfSprite_setTextureRect(pk->opt->sgs, pk->opt->bgs);
            sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sgs, NULL);
            }} else {
        pk->opt->bgs.left = 0;
        sfSprite_setTextureRect(pk->opt->sgs, pk->opt->bgs);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sgs, NULL);
    } if (pk->sc->event.type == sfEvtMouseButtonReleased
    && (pk->opt->bgs.left == 72 || pk->opt->bgs.left == 144)) {
        sfSprite_setTextureRect(pk->opt->sgs, pk->opt->bgs);
        sfRenderWindow_drawSprite(pk->sc->window, pk->opt->sgs, NULL);
        pk->opt->res = 1920;
    }}
