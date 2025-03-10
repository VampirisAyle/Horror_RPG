/*
** EPITECH PROJECT, 2023
** init_items.c
** File description:
** init_items
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void init_items3(package_t *pk)
{
    pk->it->ti50 = sfTexture_createFromFile("sprites/items/item50.png", NULL);
    pk->it->si50 = sfSprite_create();
    sfSprite_setTexture(pk->it->si50, pk->it->ti50, sfFalse);
    sfSprite_setScale(pk->it->si50, (sfVector2f) {0.2, 0.2});
    pk->it->ti51 = sfTexture_createFromFile("sprites/items/item51.png", NULL);
    pk->it->si51 = sfSprite_create();
    sfSprite_setTexture(pk->it->si51, pk->it->ti51, sfFalse);
    sfSprite_setScale(pk->it->si51, (sfVector2f) {0.23, 0.23});
    pk->it->ti52 = sfTexture_createFromFile("sprites/items/item52.png", NULL);
    pk->it->si52 = sfSprite_create();
    sfSprite_setTexture(pk->it->si52, pk->it->ti52, sfFalse);
    sfSprite_setScale(pk->it->si52, (sfVector2f) {0.19, 0.19});
}

void init_items2(package_t *pk)
{
    pk->it->ti10 = sfTexture_createFromFile("sprites/items/item10.png", NULL);
    pk->it->si10 = sfSprite_create();
    sfSprite_setTexture(pk->it->si10, pk->it->ti10, sfFalse);
    pk->it->ti20 = sfTexture_createFromFile("sprites/items/item20.png", NULL);
    pk->it->si20 = sfSprite_create();
    sfSprite_setTexture(pk->it->si20, pk->it->ti20, sfFalse);
    pk->it->ti30 = sfTexture_createFromFile("sprites/items/item30.png", NULL);
    pk->it->si30 = sfSprite_create();
    sfSprite_setTexture(pk->it->si30, pk->it->ti30, sfFalse);
    pk->it->ti40 = sfTexture_createFromFile("sprites/items/item40.png", NULL);
    pk->it->si40 = sfSprite_create();
    sfSprite_setTexture(pk->it->si40, pk->it->ti40, sfFalse);
    init_items3(pk);
}

void init_items(package_t *pk)
{
    pk->it->ti1 = sfTexture_createFromFile("sprites/items/item1.png", NULL);
    pk->it->si1 = sfSprite_create();
    sfSprite_setTexture(pk->it->si1, pk->it->ti1, sfFalse);
    sfSprite_setScale(pk->it->si1, (sfVector2f) {0.1, 0.1});
    pk->it->ti2 = sfTexture_createFromFile("sprites/items/item2.png", NULL);
    pk->it->si2 = sfSprite_create();
    sfSprite_setTexture(pk->it->si2, pk->it->ti2, sfFalse);
    sfSprite_setScale(pk->it->si2, (sfVector2f) {0.05, 0.05});
    pk->it->ti3 = sfTexture_createFromFile("sprites/items/item3.png", NULL);
    pk->it->si3 = sfSprite_create();
    sfSprite_setTexture(pk->it->si3, pk->it->ti3, sfFalse);
    sfSprite_setScale(pk->it->si3, (sfVector2f) {0.08, 0.08});
    pk->it->ti4 = sfTexture_createFromFile("sprites/items/item4.png", NULL);
    pk->it->si4 = sfSprite_create();
    sfSprite_setTexture(pk->it->si4, pk->it->ti4, sfFalse);
    sfSprite_setScale(pk->it->si4, (sfVector2f) {0.3, 0.3});
    init_items2(pk);
}
