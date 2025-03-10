/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Dynamic light create
*/

#include "../../include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char *retbuff(package_t *pk)
{
    struct stat stt;
    int hitfile = open("src/dynamic_light/hitcoord.txt", O_RDONLY);
    char *buff = NULL;
    stat("src/dynamic_light/hitcoord.txt", &stt);
    buff = malloc(stt.st_size);
    read(hitfile, buff, stt.st_size);
    pk->DL->lighcd = sfClock_create();
    return (buff);
}

static int myread(char *buff, package_t *pk)
{
    int nbr = 0;
    while (buff[pk->DL->c] != '\n') {
        if (pk->DL->c != 0)
            nbr *= 10;
        nbr += buff[pk->DL->c] - 48;
        pk->DL->c++;
    }
    return (nbr);
}

void myreadfull(char *buff, package_t *pk)
{
    pk->DL->x = myread(buff, pk);
    pk->DL->c++;
    pk->DL->y = myread(buff, pk);
    pk->DL->c++;
    pk->DL->sx = myread(buff, pk);
    pk->DL->c++;
    pk->DL->sy = myread(buff, pk);
    pk->DL->c++;
    pk->DL->c++;
}
