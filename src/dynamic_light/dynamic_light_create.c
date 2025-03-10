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

void lightpart2(package_t *pk, sfVector2f opos, sfVector2f slpos,
sfVector2f lpos)
{
    sfVertex start = {.position = opos, .color = sfTransparent};
    sfVertex end = {.position = lpos};
    sfVertex sstart = {.position = slpos, .color = sfBlack};
    double x = (start.position.x - end.position.x) / 50;
    double y = (start.position.y - end.position.y) / 50;
    while (pk->opt->lightof == 0
    && lineintersectsrec(start.position, end.position, pk)) {
        end.position.x += x;
        end.position.y += y;
    }
    sfVertex send = {.position = end.position, .color =
    sfColor_fromRGBA(0, 0, 0, 230)};
    sfVertex point = {.position = end.position, .color =
    sfColor_fromRGBA(0, 0, 0, 230)};
    sfVertexArray_append(pk->DL->LVA, point);
    sfVertexArray_append(pk->DL->SLVA, sstart);
    sfVertexArray_append(pk->DL->SLVA, send);
}

void dlight(int r, int nbr, sfVector2f opos, package_t *pk)
{
    long double dgr = 360 / nbr;
    double radians = 0;
    int r2 = r * 4;
    pk->DL->LVA = sfVertexArray_create();
    pk->DL->SLVA = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(pk->DL->LVA, sfTriangleFan);
    sfVertexArray_setPrimitiveType(pk->DL->SLVA, sfTriangleStrip);
    sfVertex center = {.position = opos, .color = sfTransparent};
    sfVertexArray_append(pk->DL->LVA, center);
    for (int c = 0; c != nbr + 1; c++){
        radians = (dgr * c) * (3.14159265358979323846 / 180);
        sfVector2f lpos = {opos.x +
        (cosl(radians) * r), opos.y + (sinl(radians) * r)};
        sfVector2f slpos = {opos.x +
        (cosl(radians) * r2), opos.y + (sinl(radians) * r2)};
        lightpart2(pk, opos, slpos, lpos);
    }
}
