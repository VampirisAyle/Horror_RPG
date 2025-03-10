/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** inventory
*/

#include "../../include/my.h"
#include "../../include/struct.h"

sfVector2f coresp_pos6(package_t *pk, sfVector2f pos)
{
    if (pk->iv->cas == 21) {
        pos.x += 1249;
        pos.y += 520;
    } if (pk->iv->cas == 22) {
        pos.x += 1305;
        pos.y += 520;
    } if (pk->iv->cas == 23) {
        pos.x += 1363;
        pos.y += 520;
    } if (pk->iv->cas == 24) {
        pos.x += 1421;
        pos.y += 520;
    } return (pos);
}

sfVector2f coresp_pos5(package_t *pk, sfVector2f pos)
{
    if (pk->iv->cas == 17) {
        pos.x += 1249;
        pos.y += 462;
    } if (pk->iv->cas == 18) {
        pos.x += 1305;
        pos.y += 462;
    } if (pk->iv->cas == 19) {
        pos.x += 1363;
        pos.y += 462;
    } if (pk->iv->cas == 20) {
        pos.x += 1421;
        pos.y += 462;
    } pos = coresp_pos6(pk, pos);
    return (pos);
}

sfVector2f coresp_pos4(package_t *pk, sfVector2f pos)
{
    if (pk->iv->cas == 13) {
        pos.x += 1249;
        pos.y += 405;
    } if (pk->iv->cas == 14) {
        pos.x += 1305;
        pos.y += 405;
    } if (pk->iv->cas == 15) {
        pos.x += 1363;
        pos.y += 405;
    } if (pk->iv->cas == 16) {
        pos.x += 1421;
        pos.y += 405;
    } pos = coresp_pos5(pk, pos);
    return (pos);
}

sfVector2f coresp_pos3(package_t *pk, sfVector2f pos)
{
    if (pk->iv->cas == 9) {
        pos.x += 1249;
        pos.y += 348;
    } if (pk->iv->cas == 10) {
        pos.x += 1305;
        pos.y += 348;
    } if (pk->iv->cas == 11) {
        pos.x += 1363;
        pos.y += 348;
    } if (pk->iv->cas == 12) {
        pos.x += 1421;
        pos.y += 348;
    } pos = coresp_pos4(pk, pos);
    return (pos);
}

sfVector2f coresp_pos2(package_t *pk, sfVector2f pos)
{
    if (pk->iv->cas == 5) {
        pos.x += 1249;
        pos.y += 291;
    } if (pk->iv->cas == 6) {
        pos.x += 1305;
        pos.y += 291;
    } if (pk->iv->cas == 7) {
        pos.x += 1363;
        pos.y += 291;
    } if (pk->iv->cas == 8) {
        pos.x += 1421;
        pos.y += 291;
    } pos = coresp_pos3(pk, pos);
    return (pos);
}
