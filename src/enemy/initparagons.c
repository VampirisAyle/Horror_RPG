/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"

void nextinitparagonbox(paragon_t *next)
{
    next->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(next->hitbox, (sfVector2f)
    {next->parpos.x + 48, next->parpos.y + 114});
    sfRectangleShape_setSize(next->hitbox, (sfVector2f) {96, 75});
    sfRectangleShape_setFillColor(next->hitbox, sfGreen);
    next->slambox = sfRectangleShape_create();
    sfRectangleShape_setPosition(next->slambox, (sfVector2f)
    {next->parpos.x + 54, next->parpos.y + 18});
    sfRectangleShape_setSize(next->slambox, (sfVector2f) {141, 177});
    sfRectangleShape_setFillColor(next->slambox, sfRed);
    next->taunt = sfSoundBuffer_createFromFile("sounds/paragon/taunt.ogg");
    next->slam1 = sfSoundBuffer_createFromFile("sounds/paragon/slam1.ogg");
    next->parsound = sfSound_create();
}

void nextinitparagons(package_t *pk)
{
    paragon_t *next = malloc(sizeof(paragon_t));
    next->parpos = (sfVector2f) {pk->en->x, pk->en->y};
    next->spar = sfSprite_create();
    sfSprite_setPosition(next->spar, next->parpos);
    next->tpar = sfTexture_createFromFile("sprites/Enemy/paragon.png",
    NULL);
    sfSprite_setTexture(next->spar, next->tpar, sfFalse);
    next->sspar = (sfIntRect) {0, 256, 64, 64};
    sfSprite_setTextureRect(next->spar, next->sspar);
    sfSprite_setScale(next->spar, (sfVector2f){3, 3});
    next->cpar = sfClock_create();
    next->sit = 0;
    next->alive = 1;
    next->pv = 100;
    next->cd = 150000;
    next->prev = pk->en->paragons;
    next->next = NULL;
    nextinitparagonbox(next);
    pk->en->paragons->next = next;
    pk->en->paragons = pk->en->paragons->next;
}

void firstinitparagonbox(package_t *pk)
{
    pk->en->paragons->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->paragons->hitbox, (sfVector2f)
    {pk->en->paragons->parpos.x + 48, pk->en->paragons->parpos.y + 114});
    sfRectangleShape_setSize(pk->en->paragons->hitbox, (sfVector2f) {96, 75});
    sfRectangleShape_setFillColor(pk->en->paragons->hitbox, sfGreen);
    pk->en->paragons->slambox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->paragons->slambox, (sfVector2f)
    {pk->en->paragons->parpos.x + 54, pk->en->paragons->parpos.y + 18});
    sfRectangleShape_setSize(pk->en->paragons->slambox,
    (sfVector2f) {141, 177});
    sfRectangleShape_setFillColor(pk->en->paragons->slambox, sfRed);
    pk->en->paragons->taunt = sfSoundBuffer_createFromFile
    ("sounds/paragon/taunt.ogg");
    pk->en->paragons->slam1 = sfSoundBuffer_createFromFile
    ("sounds/paragon/slam1.ogg");
    pk->en->paragons->parsound = sfSound_create();
}

void firstinitparagons(package_t *pk)
{
    pk->en->paragons = malloc(sizeof(paragon_t));
    pk->en->paragons->parpos = (sfVector2f) {pk->en->x, pk->en->y};
    pk->en->paragons->spar = sfSprite_create();
    sfSprite_setPosition(pk->en->paragons->spar, pk->en->paragons->parpos);
    pk->en->paragons->tpar = sfTexture_createFromFile
    ("sprites/Enemy/paragon.png", NULL);
    sfSprite_setTexture(pk->en->paragons->spar, pk->en->paragons->tpar,
    sfFalse);
    pk->en->paragons->sspar = (sfIntRect) {0, 256, 64, 64};
    sfSprite_setTextureRect(pk->en->paragons->spar, pk->en->paragons->sspar);
    sfSprite_setScale(pk->en->paragons->spar, (sfVector2f){3, 3});
    pk->en->paragons->cpar = sfClock_create();
    pk->en->paragons->sit = 0;
    pk->en->paragons->alive = 1;
    pk->en->paragons->pv = 100;
    pk->en->paragons->cd = 150000;
    pk->en->paragons->next = NULL;
    pk->en->paragons->prev = NULL;
    firstinitparagonbox(pk);
}

void initparagons(package_t *pk)
{
    char *buff = mretbuff("src/enemy/paragons_coord.txt");
    pk->en->c = 0;
    pk->en->x = 0;
    pk->en->y = 0;
    mmyreadfull(buff, pk);
    firstinitparagons(pk);
    while (buff[pk->en->c] != '\0') {
        mmyreadfull(buff, pk);
        nextinitparagons(pk);
    }
    while (pk->en->paragons->prev != NULL)
        pk->en->paragons = pk->en->paragons->prev;
}
