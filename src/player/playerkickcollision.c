/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player kick
*/

#include "../../include/my.h"

static void collireaper(package_t *pk, sfFloatRect pbounds)
{
    sfFloatRect ebounds = sfRectangleShape_getGlobalBounds(
    pk->en->reaper->hitbox);
    if (pk->en->reaper->pv > 0 && sfFloatRect_intersects(&pbounds,
    &ebounds, NULL))
        pk->en->reaper->pv -= 10;
}

static void colliknight(package_t *pk, sfFloatRect pbounds, int c)
{
    while (c == 0) {
        sfFloatRect ebounds = sfRectangleShape_getGlobalBounds(
        pk->en->knights->hitbox);
        if (pk->en->knights->pv > 0 && sfFloatRect_intersects(&pbounds,
        &ebounds, NULL))
            pk->en->knights->pv -= 10;
        if (pk->en->knights->next == NULL)
            c = 1;
        else
            pk->en->knights = pk->en->knights->next;
    }
    while (pk->en->knights->prev != NULL)
        pk->en->knights = pk->en->knights->prev;
}

static void collirat(package_t *pk, sfFloatRect pbounds, int c)
{
    while (c == 0) {
        sfFloatRect ebounds = sfRectangleShape_getGlobalBounds(
        pk->en->rats->hitbox);
        if (pk->en->rats->pv > 0 && sfFloatRect_intersects(&pbounds,
        &ebounds, NULL))
            pk->en->rats->pv -= 10;
        if (pk->en->rats->next == NULL)
            c = 1;
        else
            pk->en->rats = pk->en->rats->next;
    }
    while (pk->en->rats->prev != NULL)
        pk->en->rats = pk->en->rats->prev;
}

static void colliparagon(package_t *pk, sfFloatRect pbounds, int c)
{
    while (c == 0) {
        sfFloatRect ebounds = sfRectangleShape_getGlobalBounds(
        pk->en->paragons->hitbox);
        if (pk->en->paragons->pv > 0 && sfFloatRect_intersects(&pbounds,
        &ebounds, NULL))
            pk->en->paragons->pv -= 10;
        if (pk->en->paragons->next == NULL)
            c = 1;
        else
            pk->en->paragons = pk->en->paragons->next;
    }
    while (pk->en->paragons->prev != NULL)
        pk->en->paragons = pk->en->paragons->prev;
}

void kickcollision(package_t *pk)
{
    int c = 0;
    sfFloatRect pbounds = sfRectangleShape_getGlobalBounds(pk->ct->kickbox);
    colliparagon(pk, pbounds, c);
    collirat(pk, pbounds, c);
    colliknight(pk, pbounds, c);
    collireaper(pk, pbounds);
}
