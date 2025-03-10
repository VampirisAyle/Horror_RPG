/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"

void nextinitknightbox(knight_t *next)
{
    next->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(next->hitbox, (sfVector2f)
    {next->knipos.x + 33, next->knipos.y + 28});
    sfRectangleShape_setSize(next->hitbox, (sfVector2f) {45, 66});
    sfRectangleShape_setFillColor(next->hitbox, sfGreen);
    next->slambox = sfRectangleShape_create();
    sfRectangleShape_setPosition(next->slambox, (sfVector2f)
    {next->knipos.x + 33, next->knipos.y + 28});
    sfRectangleShape_setSize(next->slambox, (sfVector2f) {100, 66});
    sfRectangleShape_setFillColor(next->slambox, sfRed);
    next->walk1 = sfSoundBuffer_createFromFile("sounds/knight/walk1.ogg");
    next->walk2 = sfSoundBuffer_createFromFile("sounds/knight/walk2.ogg");
    next->slam1 = sfSoundBuffer_createFromFile("sounds/knight/slam1.ogg");
    next->slam2 = sfSoundBuffer_createFromFile("sounds/knight/slam2.ogg");
    next->slam3 = sfSoundBuffer_createFromFile("sounds/knight/slam3.ogg");
    next->ksound = sfSound_create();
}

void nextinitknights(package_t *pk)
{
    knight_t *next = malloc(sizeof(knight_t));
    next->knipos = (sfVector2f) {pk->en->x, pk->en->y};
    next->skni = sfSprite_create();
    sfSprite_setPosition(next->skni, next->knipos);
    next->tkni = sfTexture_createFromFile("sprites/Enemy/knight.png",
    NULL);
    sfSprite_setTexture(next->skni, next->tkni, sfFalse);
    next->sskni = (sfIntRect) {0, 64, 64, 32};
    sfSprite_setTextureRect(next->skni, next->sskni);
    sfSprite_setScale(next->skni, (sfVector2f){3, 3});
    next->ckni = sfClock_create();
    next->sit = 0;
    next->alive = 1;
    next->pv = 100;
    next->cd = 150000;
    next->prev = pk->en->knights;
    next->next = NULL;
    nextinitknightbox(next);
    pk->en->knights->next = next;
    pk->en->knights = pk->en->knights->next;
}

void firstinitknightbox(package_t *pk)
{
    pk->en->knights->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->knights->hitbox, (sfVector2f)
    {pk->en->knights->knipos.x + 33, pk->en->knights->knipos.y + 28});
    sfRectangleShape_setSize(pk->en->knights->hitbox, (sfVector2f) {45, 66});
    sfRectangleShape_setFillColor(pk->en->knights->hitbox, sfGreen);
    pk->en->knights->slambox = sfRectangleShape_create();
    sfRectangleShape_setPosition(pk->en->knights->slambox, (sfVector2f)
    {pk->en->knights->knipos.x + 33, pk->en->knights->knipos.y + 28});
    sfRectangleShape_setSize(pk->en->knights->slambox, (sfVector2f) {100, 66});
    sfRectangleShape_setFillColor(pk->en->knights->slambox, sfRed);
    pk->en->knights->walk1 = sfSoundBuffer_createFromFile
    ("sounds/knight/walk1.ogg");
    pk->en->knights->walk2 = sfSoundBuffer_createFromFile
    ("sounds/knight/walk2.ogg");
    pk->en->knights->slam1 = sfSoundBuffer_createFromFile
    ("sounds/knight/slam1.ogg");
    pk->en->knights->slam2 = sfSoundBuffer_createFromFile
    ("sounds/knight/slam2.ogg");
    pk->en->knights->ksound = sfSound_create();
}

void firstinitknights(package_t *pk)
{
    pk->en->knights = malloc(sizeof(knight_t));
    pk->en->knights->knipos = (sfVector2f) {pk->en->x, pk->en->y};
    pk->en->knights->skni = sfSprite_create();
    sfSprite_setPosition(pk->en->knights->skni, pk->en->knights->knipos);
    pk->en->knights->tkni = sfTexture_createFromFile("sprites/Enemy/knight.png",
    NULL);
    sfSprite_setTexture(pk->en->knights->skni, pk->en->knights->tkni, sfFalse);
    pk->en->knights->sskni = (sfIntRect) {0, 64, 64, 32};
    sfSprite_setTextureRect(pk->en->knights->skni, pk->en->knights->sskni);
    sfSprite_setScale(pk->en->knights->skni, (sfVector2f){3, 3});
    pk->en->knights->ckni = sfClock_create();
    pk->en->knights->sit = 0;
    pk->en->knights->alive = 1;
    pk->en->knights->pv = 100;
    pk->en->knights->cd = 150000;
    pk->en->knights->next = NULL;
    pk->en->knights->prev = NULL;
    pk->en->knights->slam3 = sfSoundBuffer_createFromFile
    ("sounds/knight/slam3.ogg");
    firstinitknightbox(pk);
}

void initknights(package_t *pk)
{
    char *buff = mretbuff("src/enemy/knights_coord.txt");
    pk->en->c = 0;
    pk->en->x = 0;
    pk->en->y = 0;
    mmyreadfull(buff, pk);
    firstinitknights(pk);
    while (buff[pk->en->c] != '\0') {
        mmyreadfull(buff, pk);
        nextinitknights(pk);
    }
    while (pk->en->knights->prev != NULL)
        pk->en->knights = pk->en->knights->prev;
}
