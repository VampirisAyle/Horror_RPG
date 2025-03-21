/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** blabla
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct.h"

#pragma once
void my_putchar(char c);
int my_putnbr(int nb);
int my_putnbru(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_putfloat(float value);
void conv_octal(int n);
void conv_hexamin(int n);
void conv_hexamaj(int n);
void conv_bin(int n);
int my_atoi(char *str);
char *my_itoa(int nbr);
int my_printf(char const *format, ...);
void showadress(void *n);
char **my_strtowoa(char *str);
void init_menu(package_t *pk);
void menu(package_t *pk);
void button_quit(package_t *pk);
void button_options(package_t *pk);
void button_credits(package_t *pk);
void button_lg(package_t *pk);
void button_ns(package_t *pk);
void wclose(package_t *pk);
void init_charact(package_t *pk);
void init_gui(package_t *pk);
void pv(package_t *pk);
void moveright(package_t *pk);
void movetop(package_t *pk);
void moveleft(package_t *pk);
void movedown(package_t *pk);
void for_mouvement(package_t *pk);
void init_inventory(package_t *pk);
void draw_inventory(package_t *pk);
void staticplayer(package_t *pk);
void playermove(package_t *pk);
void dlight(int r, int nbr, sfVector2f opos, package_t *pk);
void playerwalk(package_t *pk);
void draw_inventory2(package_t *pk);
sfVector2f inter3(sfVector2f mp, sfVector2f pos);
void init_game(package_t *pk);
void game(package_t *pk);
void ppause(package_t *pk);
void init_pause(package_t *pk);
void backgame(package_t *pk);
void backmenu(package_t *pk);
void click_case(package_t *pk);
void get_cases_nb2(package_t *pk);
sfVector2f coresp_pos2(package_t *pk, sfVector2f pos);
void initlightbox(package_t *pk);
char *retbuff(package_t *pk);
void myreadfull(char *buff, package_t *pk);
int lineintersectsrec(sfVector2f Start, sfVector2f End, package_t *pk);
void event_pause(package_t *pk);
void init_items(package_t *pk);
void init_main(package_t *pk);
void mallocage(package_t *pk);
char *mretbuff(char *path);
void mmyreadfull(char *buff, package_t *pk);
int mmyread(char *buff, package_t *pk);
void initenemy(package_t *pk);
void enemyloop(package_t *pk);
void initreaper(package_t *pk);
void reaperloop(package_t *pk);
void mvreaper(package_t *pk);
void slmreaper(package_t *pk);
void printreaper(package_t *pk);
void reaperloopstat1(package_t *pk);
void reaperloopstat2(package_t *pk);
void reaperloopstat3(package_t *pk);
void initknights(package_t *pk);
void knightloop(package_t *pk);
void mvknight(package_t *pk);
void printknights(package_t *pk);
void knightloopstat0(package_t *pk);
void knightloopstat1(package_t *pk);
void knightloopstat2(package_t *pk);
void knightloopstat3(package_t *pk);
void initrats(package_t *pk);
void ratloop(package_t *pk);
void mvrat(package_t *pk);
void printrats(package_t *pk);
void ratloopstat0(package_t *pk);
void ratloopstat1(package_t *pk);
void ratloopstat2(package_t *pk);
void ratloopstat3(package_t *pk);
void initparagons(package_t *pk);
void paragonloop(package_t *pk);
void mvparagon(package_t *pk);
void printparagons(package_t *pk);
void paragonloopstat0(package_t *pk);
void paragonloopstat1(package_t *pk);
void paragonloopstat2(package_t *pk);
void paragonloopstat3(package_t *pk);
void check_items(package_t *pk);
void change_position(package_t *pk);
void init_talk(package_t *pk);
void kickstatcheck(package_t *pk);
void initkick(package_t *pk);
void kickcheck(package_t *pk);
void kickevent(package_t *pk);
void kick1(package_t *pk);
void kick2(package_t *pk);
void kick3(package_t *pk);
void kick4(package_t *pk);
void kickcollision(package_t *pk);
void dgpv(package_t *pk);
int mapcollision(package_t *pk, sfVector2f posi);
void scene_2(package_t *pk);
void scene_3(package_t *pk);
void scene_4(package_t *pk);
void musicloop(package_t *pk);
void cinem(package_t *pk);
void init_txt(package_t *pk);
void init_options(package_t *pk);
int enemydead(package_t *pk);
void enemyalive(package_t *pk);
void savealive(package_t *pk);
void loadsave(package_t *pk);
void save(package_t *pk);
char *fnewfile(package_t *pk, char *savex, char *savey, char *newfile);
int nbrleng(int nbr);
void options_button(package_t *pk);
void button_high(package_t *pk);
void button_med(package_t *pk);
void button_low(package_t *pk);
void button_off(package_t *pk);
void button_gs(package_t *pk);
void button_ls(package_t *pk);
void use_p(package_t *pk);
void pltp2(package_t *pk, sfFloatRect phb, sfFloatRect tpb3);
void cinem4(package_t *pk);
void init_options_pause(package_t *pk);
void button_opt(package_t *pk);
void pause_high(package_t *pk);
void pause_med(package_t *pk);
void pause_low(package_t *pk);
void pause_off(package_t *pk);
void pause_gs(package_t *pk);
void endreset(package_t *pk);
void dead(package_t *pk);
