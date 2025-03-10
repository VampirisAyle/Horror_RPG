/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** read monster file coord
*/

#include "../../include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char *mretbuff(char *path)
{
    struct stat stt;
    int hitfile = open(path, O_RDONLY);
    char *buff = NULL;
    stat(path, &stt);
    buff = malloc(stt.st_size);
    read(hitfile, buff, stt.st_size);
    close(hitfile);
    return (buff);
}

int mmyread(char *buff, package_t *pk)
{
    int nbr = 0;
    while (buff[pk->en->c] != '\n') {
        if (pk->en->c != 0)
            nbr *= 10;
        nbr += buff[pk->en->c] - 48;
        pk->en->c++;
    }
    return (nbr);
}

void mmyreadfull(char *buff, package_t *pk)
{
    pk->en->x = mmyread(buff, pk);
    pk->en->c++;
    pk->en->y = mmyread(buff, pk);
    pk->en->c++;
    pk->en->c++;
}
