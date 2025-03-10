/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Dynamic light create
*/

#include "../../include/my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

int suorin(int nbr1, int nbr2)
{
    if (nbr1 < nbr2)
        return (1);
    else
        return (-1);
}

intersect_t setinter(sfVector2f Start, sfVector2f End)
{
    intersect_t inter;
    inter.x0 = (int)Start.x;
    inter.y0 = (int)Start.y;
    inter.x1 = (int)End.x;
    inter.y1 = (int)End.y;
    inter.dx = abs(inter.x1 - inter.x0);
    inter.dy = abs(inter.y1 - inter.y0);
    inter.sx = suorin(inter.x0, inter.x1);
    inter.sy = suorin(inter.y0, inter.y1);
    inter.err = inter.dx - inter.dy;
    return (inter);
}

int checkallbox(package_t *pk, int x, int y)
{
    int c = 0;
    while (pk->DL->hb->prev != NULL)
        pk->DL->hb = pk->DL->hb->prev;
    while (c == 0) {
        sfFloatRect bounds = sfRectangleShape_getGlobalBounds(
        pk->DL->hb->hitbox);
        if (sfFloatRect_intersects(&bounds, &(sfFloatRect){(float)x,
        (float)y, 1, 1}, NULL)) {
            return (1);
        }
        if (pk->DL->hb->next != NULL)
            pk->DL->hb = pk->DL->hb->next;
        else
            c++;
    }
    return (0);
}

int lineintersectsrec(sfVector2f Start, sfVector2f End, package_t *pk)
{
    intersect_t si = setinter(Start, End);

    while (si.x0 != si.x1 || si.y0 != si.y1) {
        if (checkallbox(pk, si.x0, si.y0) == 1)
            return (1);
        int e2 = 2 * si.err;
        if (e2 > -si.dy) {
            si.err -= si.dy;
            si.x0 += si.sx;
        }
        if (e2 < si.dx) {
            si.err += si.dx;
            si.y0 += si.sy;
        }
    }
    return (0);
}
