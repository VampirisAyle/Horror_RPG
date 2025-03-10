/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** inventory
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void get_cases_nb6(package_t *pk)
{
    if (pk->iv->mp.x >= 1249 && pk->iv->mp.x <= 1313 &&
    pk->iv->mp.y >= 520 && pk->iv->mp.y <= 584 && CO && ND) {
        pk->iv->cas = 21;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1305 && pk->iv->mp.x <= 1369 &&
    pk->iv->mp.y >= 520 && pk->iv->mp.y <= 584 && CO && ND) {
        pk->iv->cas = 22;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1363 && pk->iv->mp.x <= 1427 &&
    pk->iv->mp.y >= 520 && pk->iv->mp.y <= 584 && CO && ND) {
        pk->iv->cas = 23;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1421 && pk->iv->mp.x <= 1495 &&
    pk->iv->mp.y >= 520 && pk->iv->mp.y <= 584 && CO && ND) {
        pk->iv->cas = 24;
        pk->iv->condition++;
    }
}

void get_cases_nb5(package_t *pk)
{
    if (pk->iv->mp.x >= 1249 && pk->iv->mp.x <= 1313 &&
    pk->iv->mp.y >= 462 && pk->iv->mp.y <= 526 && CO && ND) {
        pk->iv->cas = 17;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1305 && pk->iv->mp.x <= 1369 &&
    pk->iv->mp.y >= 462 && pk->iv->mp.y <= 526 && CO && ND) {
        pk->iv->cas = 18;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1363 && pk->iv->mp.x <= 1427 &&
    pk->iv->mp.y >= 462 && pk->iv->mp.y <= 526 && CO && ND) {
        pk->iv->cas = 19;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1421 && pk->iv->mp.x <= 1495 &&
    pk->iv->mp.y >= 462 && pk->iv->mp.y <= 526 && CO && ND) {
        pk->iv->cas = 20;
        pk->iv->condition++;
    } get_cases_nb6(pk);
}

void get_cases_nb4(package_t *pk)
{
    if (pk->iv->mp.x >= 1249 && pk->iv->mp.x <= 1313 &&
    pk->iv->mp.y >= 405 && pk->iv->mp.y <= 467 && CO && ND) {
        pk->iv->cas = 13;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1305 && pk->iv->mp.x <= 1369 &&
    pk->iv->mp.y >= 405 && pk->iv->mp.y <= 467 && CO && ND) {
        pk->iv->cas = 14;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1363 && pk->iv->mp.x <= 1427 &&
    pk->iv->mp.y >= 405 && pk->iv->mp.y <= 467 && CO && ND) {
        pk->iv->cas = 15;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1421 && pk->iv->mp.x <= 1495 &&
    pk->iv->mp.y >= 405 && pk->iv->mp.y <= 467 && CO && ND) {
        pk->iv->cas = 16;
        pk->iv->condition++;
    } get_cases_nb5(pk);
}

void get_cases_nb3(package_t *pk)
{
    if (pk->iv->mp.x >= 1249 && pk->iv->mp.x <= 1313 &&
    pk->iv->mp.y >= 348 && pk->iv->mp.y <= 420 && CO && ND) {
        pk->iv->cas = 9;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1305 && pk->iv->mp.x <= 1369 &&
    pk->iv->mp.y >= 348 && pk->iv->mp.y <= 420 && CO && ND) {
        pk->iv->cas = 10;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1363 && pk->iv->mp.x <= 1427 &&
    pk->iv->mp.y >= 348 && pk->iv->mp.y <= 420 && CO && ND) {
        pk->iv->cas = 11;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1421 && pk->iv->mp.x <= 1495 &&
    pk->iv->mp.y >= 348 && pk->iv->mp.y <= 420 && CO && ND) {
        pk->iv->cas = 12;
        pk->iv->condition++;
    } get_cases_nb4(pk);
}

void get_cases_nb2(package_t *pk)
{
    if (pk->iv->mp.x >= 1249 && pk->iv->mp.x <= 1313 &&
    pk->iv->mp.y >= 291 && pk->iv->mp.y <= 363 && CO && ND) {
        pk->iv->cas = 5;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1305 && pk->iv->mp.x <= 1369 &&
    pk->iv->mp.y >= 291 && pk->iv->mp.y <= 363 && CO && ND) {
        pk->iv->cas = 6;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1363 && pk->iv->mp.x <= 1427 &&
    pk->iv->mp.y >= 291 && pk->iv->mp.y <= 363 && CO && ND) {
        pk->iv->cas = 7;
        pk->iv->condition++;
    } if (pk->iv->mp.x >= 1421 && pk->iv->mp.x <= 1495 &&
    pk->iv->mp.y >= 291 && pk->iv->mp.y <= 363 && CO && ND) {
        pk->iv->cas = 8;
        pk->iv->condition++;
    } get_cases_nb3(pk);
}
