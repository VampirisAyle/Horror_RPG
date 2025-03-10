/*
** EPITECH PROJECT, 2023
** inter.c
** File description:
** inter
*/

#include "../../include/my.h"
#include "../../include/struct.h"

sfVector2f inter6(sfVector2f mp, sfVector2f pos)
{
    if (mp.x >= 1249 && mp.x <= 1313 && mp.y >= 520 && mp.y <= 584) {
        pos.x += 1249 + 8;
        pos.y += 520 + 8;
    } if (mp.x >= 1305 && mp.x <= 1369 && mp.y >= 520 && mp.y <= 584) {
        pos.x += 1305 + 8;
        pos.y += 520 + 8;
    } if (mp.x >= 1363 && mp.x <= 1427 && mp.y >= 520 && mp.y <= 584) {
        pos.x += 1363 + 8;
        pos.y += 520 + 8;
    } if (mp.x >= 1421 && mp.x <= 1495 && mp.y >= 520 && mp.y <= 584) {
        pos.x += 1421 + 8;
        pos.y += 520 + 8;
    } return (pos);
}

sfVector2f inter5(sfVector2f mp, sfVector2f pos)
{
    if (mp.x >= 1249 && mp.x <= 1313 && mp.y >= 462 && mp.y <= 526) {
        pos.x += 1249 + 8;
        pos.y += 462 + 8;
    } if (mp.x >= 1305 && mp.x <= 1369 && mp.y >= 462 && mp.y <= 526) {
        pos.x += 1305 + 8;
        pos.y += 462 + 8;
    } if (mp.x >= 1363 && mp.x <= 1427 && mp.y >= 462 && mp.y <= 526) {
        pos.x += 1363 + 8;
        pos.y += 462 + 8;
    } if (mp.x >= 1421 && mp.x <= 1495 && mp.y >= 462 && mp.y <= 526) {
        pos.x += 1421 + 8;
        pos.y += 462 + 8;
    } pos = inter6(mp, pos);
    return (pos);
}

sfVector2f inter4(sfVector2f mp, sfVector2f pos)
{
    if (mp.x >= 1249 && mp.x <= 1313 && mp.y >= 405 && mp.y <= 467) {
        pos.x += 1249 + 8;
        pos.y += 405 + 8;
    } if (mp.x >= 1305 && mp.x <= 1369 && mp.y >= 405 && mp.y <= 467) {
        pos.x += 1305 + 8;
        pos.y += 405 + 8;
    } if (mp.x >= 1363 && mp.x <= 1427 && mp.y >= 405 && mp.y <= 467) {
        pos.x += 1363 + 8;
        pos.y += 405 + 8;
    } if (mp.x >= 1421 && mp.x <= 1495 && mp.y >= 405 && mp.y <= 467) {
        pos.x += 1421 + 8;
        pos.y += 405 + 8;
    } pos = inter5(mp, pos);
    return (pos);
}

sfVector2f inter3(sfVector2f mp, sfVector2f pos)
{
    if (mp.x >= 1363 && mp.x <= 1427 && mp.y >= 348 && mp.y <= 420) {
        pos.x += 1363 + 8;
        pos.y += 348 + 8;
    } if (mp.x >= 1421 && mp.x <= 1495 && mp.y >= 348 && mp.y <= 420) {
        pos.x += 1421 + 8;
        pos.y += 348 + 8;
    } pos = inter4(mp, pos);
    return (pos);
}
