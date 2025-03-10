/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** initialise all enemies
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"

void enemyalive2(package_t *pk)
{
    int c = 0;
    while (c != 1) {
        pk->en->rats->alive = 1;
        if (pk->en->rats->next != NULL)
            pk->en->rats = pk->en->rats->next;
        else
            c = 1;
    } while (pk->en->rats->prev != NULL)
        pk->en->rats = pk->en->rats->prev;
}

void enemyalive(package_t *pk)
{
    int c = 0;
    pk->en->reaper->alive = 1;
    while (c != 1) {
        pk->en->knights->alive = 1;
        if (pk->en->knights->next != NULL)
            pk->en->knights = pk->en->knights->next;
        else
            c = 1;
    } while (pk->en->knights->prev != NULL)
        pk->en->knights = pk->en->knights->prev;
    c = 0;
    while (c != 1) {
        pk->en->paragons->alive = 1;
        if (pk->en->paragons->next != NULL)
            pk->en->paragons = pk->en->paragons->next;
        else
            c = 1;
    } while (pk->en->paragons->prev != NULL)
        pk->en->paragons = pk->en->paragons->prev;
    enemyalive2(pk);
}

int enemydead3(package_t *pk)
{
    int c = 0;
    int nd = 0;
    while (c != 1 && nd == 0) {
        if (pk->en->rats->alive == 1)
            nd++;
        if (pk->en->rats->next != NULL)
            pk->en->rats = pk->en->rats->next;
        else
            c = 1;
    } while (pk->en->rats->prev != NULL)
        pk->en->rats = pk->en->rats->prev;
    if (nd != 0)
        return (1);
    else
        return (0);
}

int enemydead2(package_t *pk)
{
    int c = 0;
    int nd = 0;
    while (c != 1 && nd == 0) {
        if (pk->en->paragons->alive == 1)
            nd++;
        if (pk->en->paragons->next != NULL)
            pk->en->paragons = pk->en->paragons->next;
        else
            c = 1;
    } while (pk->en->paragons->prev != NULL)
        pk->en->paragons = pk->en->paragons->prev;
    if (nd != 0)
        return (1);
    else
        return (0);
}

int enemydead(package_t *pk)
{
    int c = 0;
    int nd = 0;
    if (pk->en->reaper->alive == 1)
        return (1);
    while (c != 1 && nd == 0) {
        if (pk->en->knights->alive == 1)
            nd++;
        if (pk->en->knights->next != NULL)
            pk->en->knights = pk->en->knights->next;
        else
            c = 1;
    } while (pk->en->knights->prev != NULL)
        pk->en->knights = pk->en->knights->prev;
    if (nd != 0 || enemydead2(pk) != 0 || enemydead3(pk) != 0)
        return (1);
    else
        return (0);
}
