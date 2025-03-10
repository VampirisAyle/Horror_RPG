/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"

void nextinitratbox(rat_t *next)
{
    next->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(next->hitbox, (sfVector2f)
    {next->ratpos.x + 15, next->ratpos.y + 51});
    sfRectangleShape_setSize(next->hitbox, (sfVector2f) {69, 45});
    sfRectangleShape_setFillColor(next->hitbox, sfGreen);
    next->slambox = sfRectangleShape_create();
    sfRectangleShape_setPosition(next->slambox, (sfVector2f)
    {next->ratpos.x + 15, next->ratpos.y + 51});
    sfRectangleShape_setSize(next->slambox, (sfVector2f) {90, 45});
    sfRectangleShape_setFillColor(next->slambox, sfRed);
    next->laugh = sfSoundBuffer_createFromFile("sounds/rat/laugh.ogg");
    next->slam1 = sfSoundBuffer_createFromFile("sounds/rat/slam1.ogg");
    next->ratsound = sfSound_create();
}

void nextinitrats(package_t *pk)
{
    rat_t *next = malloc(sizeof(rat_t));
    next->ratpos = (sfVector2f) {pk->en->x, pk->en->y};
    next->srat = sfSprite_create();
    sfSprite_setPosition(next->srat, next->ratpos);
    next->trat = sfTexture_createFromFile("sprites/Enemy/rat.png",
    NULL);
    sfSprite_setTexture(next->srat, next->trat, sfFalse);
    next->ssrat = (sfIntRect) {0, 64, 32, 32};
    sfSprite_setTextureRect(next->srat, next->ssrat);
    sfSprite_setScale(next->srat, (sfVector2f){3, 3});
    next->crat = sfClock_create();
    next->sit = 0;
    next->alive = 1;
    next->pv = 50;
    next->cd = 150000;
    next->prev = pk->en->rats;
    next->next = NULL;
    nextinitratbox(next);
    pk->en->rats->next = next;
    pk->en->rats = pk->en->rats->next;
}

void firstinitratbox(package_t *pk)
{
    pk->en->rats->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->rats->hitbox, (sfVector2f)
    {pk->en->rats->ratpos.x + 15, pk->en->rats->ratpos.y + 51});
    sfRectangleShape_setSize(pk->en->rats->hitbox, (sfVector2f) {69, 45});
    sfRectangleShape_setFillColor(pk->en->rats->hitbox, sfGreen);
    pk->en->rats->slambox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->rats->slambox, (sfVector2f)
    {pk->en->rats->ratpos.x + 15, pk->en->rats->ratpos.y + 51});
    sfRectangleShape_setSize(pk->en->rats->slambox, (sfVector2f) {90, 45});
    sfRectangleShape_setFillColor(pk->en->rats->slambox, sfRed);
    pk->en->rats->laugh = sfSoundBuffer_createFromFile("sounds/rat/laugh.ogg");
    pk->en->rats->slam1 = sfSoundBuffer_createFromFile("sounds/rat/slam1.ogg");
    pk->en->rats->ratsound = sfSound_create();
    sfSound_setVolume(pk->en->rats->ratsound, 50);
}

void firstinitrats(package_t *pk)
{
    pk->en->rats = malloc(sizeof(rat_t));
    pk->en->rats->ratpos = (sfVector2f) {pk->en->x, pk->en->y};
    pk->en->rats->srat = sfSprite_create();
    sfSprite_setPosition(pk->en->rats->srat, pk->en->rats->ratpos);
    pk->en->rats->trat = sfTexture_createFromFile("sprites/Enemy/rat.png",
    NULL);
    sfSprite_setTexture(pk->en->rats->srat, pk->en->rats->trat, sfFalse);
    pk->en->rats->ssrat = (sfIntRect) {0, 64, 32, 32};
    sfSprite_setTextureRect(pk->en->rats->srat, pk->en->rats->ssrat);
    sfSprite_setScale(pk->en->rats->srat, (sfVector2f){3, 3});
    pk->en->rats->crat = sfClock_create();
    pk->en->rats->sit = 0;
    pk->en->rats->alive = 1;
    pk->en->rats->pv = 50;
    pk->en->rats->cd = 150000;
    pk->en->rats->next = NULL;
    pk->en->rats->prev = NULL;
    firstinitratbox(pk);
}

void initrats(package_t *pk)
{
    char *buff = mretbuff("src/enemy/rats_coord.txt");
    pk->en->c = 0;
    pk->en->x = 0;
    pk->en->y = 0;
    mmyreadfull(buff, pk);
    firstinitrats(pk);
    while (buff[pk->en->c] != '\0') {
        mmyreadfull(buff, pk);
        nextinitrats(pk);
    }
    while (pk->en->rats->prev != NULL)
        pk->en->rats = pk->en->rats->prev;
}
