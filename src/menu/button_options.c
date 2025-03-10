/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button main menu
*/

#include "../../include/my.h"

void button_high(package_t *pk)
{
    if (pk->cos.x > 259 && pk->cos.x < 369 && pk->cos.y > 479
        && pk->cos.y < 519){
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

void button_med(package_t *pk)
{
    if (pk->cos.x > 444 && pk->cos.x < 554 && pk->cos.y > 479
        && pk->cos.y < 519){
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

void button_low(package_t *pk)
{
    if (pk->cos.x > 259 && pk->cos.x < 369 && pk->cos.y > 529
        && pk->cos.y < 569){
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

void button_off(package_t *pk)
{
    if (pk->cos.x > 444 && pk->cos.x < 554 && pk->cos.y > 529
        && pk->cos.y < 569){
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

void button_gs(package_t *pk)
{
    if (pk->cos.x > 260 && pk->cos.x < 370 && pk->cos.y > 375
        && pk->cos.y < 415){
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
    }
}
