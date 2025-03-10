/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Dynamic light create
*/

#include "../../include/my.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void dlcreate(package_t *pk)
{
    pk->DL->hb = malloc(sizeof(dlighthitbox_t));
    pk->DL->hb->hitbox = sfRectangleShape_create();
    pk->DL->hb->x = pk->DL->x;
    pk->DL->hb->y = pk->DL->y;
    pk->DL->hb->sx = pk->DL->sx;
    pk->DL->hb->sy = pk->DL->sy;
    sfRectangleShape_setPosition(pk->DL->hb->hitbox,
    (sfVector2f) {pk->DL->hb->x, pk->DL->hb->y});
    sfRectangleShape_setSize(pk->DL->hb->hitbox,
    (sfVector2f) {pk->DL->hb->sx, pk->DL->hb->sy});
    sfRectangleShape_setFillColor(pk->DL->hb->hitbox, sfGreen);
    pk->DL->hb->next = NULL;
    pk->DL->hb->prev = NULL;
}

dlighthitbox_t *dlnew(package_t *pk)
{
    dlighthitbox_t *new;
    new = malloc(sizeof(dlighthitbox_t));
    new->hitbox = sfRectangleShape_create();
    new->x = pk->DL->x;
    new->y = pk->DL->y;
    new->sx = pk->DL->sx;
    new->sy = pk->DL->sy;
    new->next = NULL;
    new->prev = pk->DL->hb;
    pk->DL->hb->next = new;
    sfRectangleShape_setPosition(new->hitbox, (sfVector2f) {new->x, new->y});
    sfRectangleShape_setSize(new->hitbox, (sfVector2f) {new->sx, new->sy});
    sfRectangleShape_setFillColor(new->hitbox, sfGreen);
    return (new);
}

void initlightbox(package_t *pk)
{
    char *buff = retbuff(pk);
    pk->opt->light = 45;
    pk->opt->lightof = 0;
    pk->DL->c = 0;

    myreadfull(buff, pk);
    dlcreate(pk);

    while (buff[pk->DL->c] != '\0') {
        myreadfull(buff, pk);
        pk->DL->hb = dlnew(pk);
    }
}
