/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"

void initenemy(package_t *pk)
{
    pk->en = malloc(sizeof(enemy_t));

    initreaper(pk);
    initknights(pk);
    initrats(pk);
    initparagons(pk);
}

void enemyloop(package_t *pk)
{
    reaperloop(pk);
    knightloop(pk);
    ratloop(pk);
    paragonloop(pk);
}
