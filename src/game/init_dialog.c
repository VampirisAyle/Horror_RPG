/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_jeu
*/

#include "../../include/my.h"

void init_dialogend(package_t *pk)
{
    pk->ga->dialoglist[13] = malloc(39 * sizeof(char));
    pk->ga->dialoglist[13] = "Jack:\n-YOU DID IT! THE DOOR IS OPENED!";
    pk->ga->dialoglist[14] = malloc(34 * sizeof(char));
    pk->ga->dialoglist[14] = "Steven:\n*I think I can go now...*";
    pk->ga->dialoglist[15] = malloc(11 * sizeof(char));
    pk->ga->dialoglist[15] = "THE END...";
}

void init_dialogpnj2(package_t *pk)
{
    pk->ga->dialoglist[8] = malloc(120 * sizeof(char));
    pk->ga->dialoglist[8] = "Jack:\n-Yet, he didn't want to find anything. He "
    "wanted to fight.\nYou never make yourself known by looking for papers...";
    pk->ga->dialoglist[9] = malloc(182 * sizeof(char));
    pk->ga->dialoglist[9] = "Jack:\n-Of course, he won every single fight agai"
    "nst the strange creatures which lived here.\nHowever, he wasn't too stron"
    "g to be the winner in front of the last and bigger monster...";
    pk->ga->dialoglist[9] = malloc(106 * sizeof(char));
    pk->ga->dialoglist[9] = "Jack:\n-Sadly, he died even though he would be ab"
    "le to leave this place. The final creature was the key...";
    pk->ga->dialoglist[9] = malloc(111 * sizeof(char));
    pk->ga->dialoglist[9] = "Steven:\n-If I understand, either I find pieces o"
    "f paper, or I fight against horrendous and pitiless creatures.";
    pk->ga->dialoglist[10] = malloc(39 * sizeof(char));
    pk->ga->dialoglist[10] = "Steven:\n-The choice is quickly made...";
    pk->ga->dialoglist[11] = malloc(55 * sizeof(char));
    pk->ga->dialoglist[11] = "Steven:\n-Have a nice evening, thank you for you"
    "r help.";
    pk->ga->dialoglist[12] = malloc(55 * sizeof(char));
    pk->ga->dialoglist[12] = "Jack:\n-Come back alive...";
}

void init_dialogpnj(package_t *pk)
{
    pk->ga->dialoglist[3] = malloc(203 * sizeof(char));
    pk->ga->dialoglist[3] =
    "Jack:\n-It's not me! I swear.\nI told you the mansion of your grandfathe"
    "r isn't normal...\nThe portal needs a key if you want to open it.\nWell, "
    "why did I say that?\nYou know a door needs a key to be open...";
    pk->ga->dialoglist[4] = malloc(70 * sizeof(char));
    pk->ga->dialoglist[4] =
    "Steven:\n-And what do I have to do if I want to get out of this place?";
    pk->ga->dialoglist[5] = malloc(156 * sizeof(char));
    pk->ga->dialoglist[5] = "Jack:\n-I've heard a story about this manor.\nAn o"
    "ld lady confessed to me that a famous and daring knight had tried to disc"
    "over the mystery of this property.";
    pk->ga->dialoglist[6] = malloc(26 * sizeof(char));
    pk->ga->dialoglist[6] = "Steven:\n-Go to the point!";
    pk->ga->dialoglist[7] = malloc(105 * sizeof(char));
    pk->ga->dialoglist[7] = "Jack:\n-He had to look for some pieces of paper t"
    "o find a final one which would reveal where the key was.";
    init_dialogpnj2(pk);
    init_dialogend(pk);
}

void init_dialog(package_t *pk)
{
    pk->ga->dialoglist = malloc(16 * sizeof(char*));
    pk->ga->dialoglist[0] = malloc(140 * sizeof(char));
    pk->ga->dialoglist[0] =
    "      A LONG TIME AGO, A YOUNG MAN NAMED OWEN\n"
    "HAD A GLOOMY PROPERTY WHERE MISTY THINGS HAPPENED.\n"
    "            HE DIED IN GRIME CONDITIONS.";
    pk->ga->dialoglist[1] = malloc(165 * sizeof(char));
    pk->ga->dialoglist[1] =
    "HIS GRANDSON, STEVEN,  WANTED TO KNOW THE\nTRUTH ABOUT THE DEATH OF HIS"
    " GRANDFATHER.\n\n          NEVERTHELESS, TO DO THAT,\n"
    " HE HAD TO GO TO THE ORIGIN OF THE ISSUE...";
    pk->ga->dialoglist[2] = malloc(107 * sizeof(char));
    pk->ga->dialoglist[2] =
    "Steven:\n-Wait... Why did you close the portal?\n"
    "I don't have time for jokes, I have an investigation to do !";
}

void init_txt(package_t *pk)
{
    pk->ga->ccinema = sfClock_create();
    pk->ga->bbg = sfRectangleShape_create();
    pk->ga->dcd = 10000;
    pk->ga->tcinema = sfText_create();
    pk->ga->fcinema = sfFont_createFromFile("sprites/font.ttf");
    sfText_setFont(pk->ga->tcinema, pk->ga->fcinema);
    sfText_setString(pk->ga->tcinema, "test");
    sfText_setPosition(pk->ga->tcinema, (sfVector2f)
    {sfRectangleShape_getPosition(pk->ct->hitbox).x,
    sfRectangleShape_getPosition(pk->ct->hitbox).y});
    sfText_setCharacterSize(pk->ga->tcinema, 60);
    sfText_setFillColor(pk->ga->tcinema, sfColor_fromRGBA(0, 255, 0, 0));
    sfText_setStyle(pk->ga->tcinema, sfTextBold);
    sfRectangleShape_setPosition(pk->ga->bbg, (sfVector2f) {0, 0});
    sfRectangleShape_setSize(pk->ga->bbg, (sfVector2f) {5000, 5000});
    sfRectangleShape_setFillColor(pk->ga->bbg ,sfBlack);
    init_dialog(pk);
    init_dialogpnj(pk);
}
