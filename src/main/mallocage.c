/*
** EPITECH PROJECT, 2023
** My_rpg
** File description:
** main init
*/

#include "../../include/my.h"

void mallocage(package_t *pk)
{
    pk->sc = malloc(sizeof(screen_t));
    pk->mn = malloc(sizeof(menu_t));
    pk->ct = malloc(sizeof(charact_t));
    pk->iv = malloc(sizeof(inventory_t));
    pk->DL = malloc(sizeof(Dlight_t));
    pk->ga = malloc(sizeof(game_t));
    pk->pa = malloc(sizeof(pause_t));
    pk->it = malloc(sizeof(items_t));
    pk->opt = malloc(sizeof(option_t));
}

void init_main(package_t *pk)
{
    pk->scene = 0;
    pk->pa->i = 0;
    pk->pa->j = 0;
    pk->pa->k = 0;
    initenemy(pk);
    initlightbox(pk);
    initkick(pk);
    init_charact(pk);
    init_gui(pk);
    init_game(pk);
    init_menu(pk);
    init_inventory(pk);
    init_items(pk);
}
