/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"

void initreaperbox(package_t *pk)
{
    pk->en->reaper->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->reaper->hitbox, (sfVector2f)
    {pk->en->reaper->epos.x + 38, pk->en->reaper->epos.y + 99});
    sfRectangleShape_setSize(pk->en->reaper->hitbox, (sfVector2f) {108, 90});
    sfRectangleShape_setFillColor(pk->en->reaper->hitbox, sfGreen);
    pk->en->reaper->slambox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->reaper->slambox, (sfVector2f)
    {pk->en->reaper->epos.x + 120, pk->en->reaper->epos.y + 35});
    sfRectangleShape_setSize(pk->en->reaper->slambox, (sfVector2f) {198, 165});
    sfRectangleShape_setFillColor(pk->en->reaper->slambox, sfRed);
    pk->en->reaper->reasound = sfSound_create();
    pk->en->reaper->reasound2 = sfSound_create();
    pk->en->reaper->walk1 = sfSoundBuffer_createFromFile
    ("sounds/reaper/walk1.ogg");
    pk->en->reaper->walk2 = sfSoundBuffer_createFromFile
    ("sounds/reaper/walk2.ogg");
    pk->en->reaper->walk3 = sfSoundBuffer_createFromFile
    ("sounds/reaper/walk3.ogg");
    pk->en->reaper->walk4 = sfSoundBuffer_createFromFile
    ("sounds/reaper/walk4.ogg");
}

void initreaper(package_t *pk)
{
    pk->en->reaper = malloc(sizeof(reaper_t));
    pk->en->reaper->epos = (sfVector2f) {1141, 7400};
    pk->en->reaper->srea = sfSprite_create();
    sfSprite_setPosition(pk->en->reaper->srea, pk->en->reaper->epos);
    pk->en->reaper->trea = sfTexture_createFromFile("sprites/Enemy/reaper.png",
    NULL);
    sfSprite_setTexture(pk->en->reaper->srea, pk->en->reaper->trea, sfFalse);
    pk->en->reaper->ssrea = (sfIntRect) {0, 128, 128, 64};
    sfSprite_setTextureRect(pk->en->reaper->srea, pk->en->reaper->ssrea);
    sfSprite_setScale(pk->en->reaper->srea, (sfVector2f){3, 3});
    pk->en->reaper->crea = sfClock_create();
    pk->en->reaper->sit = 0;
    pk->en->reaper->alive = 1;
    pk->en->reaper->pv = 500;
    pk->en->reaper->slam = sfSoundBuffer_createFromFile
    ("sounds/reaper/slam.ogg");
    pk->en->reaper->slamv = sfSoundBuffer_createFromFile
    ("sounds/reaper/slamv.ogg");
    initreaperbox(pk);
}
