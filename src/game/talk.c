/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** story_telling
*/

#include "../../include/my.h"

void init_talk(package_t *pk)
{
    pk->ga->sto = sfRectangleShape_create();
    sfRectangleShape_setSize(pk->ga->sto, (sfVector2f) {1885, 250});
    sfRectangleShape_setPosition(pk->ga->sto, (sfVector2f) {3500, 3500});
    sfRectangleShape_setFillColor(pk->ga->sto, (sfColor) {128, 128, 128, 255});
    sfRectangleShape_setOutlineThickness(pk->ga->sto, (float) {5});
    sfRectangleShape_setOutlineColor(pk->ga->sto, sfWhite);
    pk->ga->talk = sfText_create();
    pk->ga->font = sfFont_createFromFile("sprites/font.ttf");
    sfText_setFont(pk->ga->talk, pk->ga->font);
    sfText_setFillColor(pk->ga->talk, sfBlack);
    sfText_setPosition(pk->ga->talk, (sfVector2f) {3520,3520});
}
