/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mouvement
*/

#include "../../include/my.h"

int mapcollision(package_t *pk, sfVector2f posi)
{
    if (sfImage_getPixel(pk->ga->ibghb, posi.x, posi.y).g == 255) {
        return (1);
    } else {
        return (0);
    }
}
