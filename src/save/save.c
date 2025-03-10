/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save all
*/
#include "../../include/my.h"
#include <stdio.h>

int nbrleng(int nbr)
{
    int c = 0;
    while (nbr != 0) {
        nbr /= 10;
        c++;
    }
    return (c + 1);
}

char *fnewfile(package_t *pk, char *savex, char *savey, char *newfile)
{
    int c = 0;
    for (int c2 = 0; savex[c2] != '\0'; c2++) {
        newfile[c] = savex[c2];
        c++;
    } newfile[c] = '\n';
    c++;
    for (int c2 = 0; savey[c2] != '\0'; c2++) {
        newfile[c] = savey[c2];
        c++;
    } newfile[c] = '\n';
    newfile[c + 1] = '\n';
    c += 2;
    for (int c2 = 0; pk->ga->alivesave2[c2] != '\0'; c2++) {
        newfile[c] = pk->ga->alivesave2[c2];
        c++;
    } newfile[c] = '\n';
    newfile[c + 1] = '\0';
    return (newfile);
}

char *inttochar(char *save, int s)
{
    int c = 0;
    while (s != 0) {
        save[c] = s % 10 + 48;
        save[c + 1] = '\0';
        c++;
        s /= 10;
    }
    save = my_revstr(save);
    return (save);
}

void save(package_t *pk)
{
    if (pk->ga->save == 1) {
        FILE *sfile = fopen("src/save/s.txt", "w");
        int sx = pk->ct->ppl.x;
        char *savex = malloc(nbrleng(sx) * sizeof(char));
        int sy = pk->ct->ppl.y;
        char *savey = malloc(nbrleng(sy) * sizeof(char));
        char *newfile = malloc((my_strlen(savex) + 2 + my_strlen(savey) + 2 +
        my_strlen(pk->ga->alivesave2) + 2) * sizeof(char));
        savealive(pk);
        savex = inttochar(savex, sx);
        savey = inttochar(savey, sy);
        newfile = fnewfile(pk, savex, savey, newfile);
        fwrite(newfile, 1, my_strlen(newfile), sfile);
        pk->ga->save = 2;
        fclose(sfile);
    }
}
