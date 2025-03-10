/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save all
*/
#include "../../include/my.h"
#include <stdio.h>

static void mmyreadfulls(char *buff, package_t *pk, int e)
{
    pk->ga->tmpsave = mmyread(buff, pk);
    pk->en->c++;
    if (e == 0)
        pk->en->c++;
}

void savealive(package_t *pk)
{
    pk->ga->alivesave2[0] = pk->en->rats->next->next->alive + 48;
    pk->ga->alivesave2[1] = pk->en->rats->next->alive + 48;
    pk->ga->alivesave2[2] = pk->en->rats->alive + 48;
    pk->ga->alivesave2[3] = pk->en->paragons->next->alive + 48;
    pk->ga->alivesave2[4] = pk->en->paragons->alive + 48;
    pk->ga->alivesave2[5] = pk->en->knights->next->next->alive + 48;
    pk->ga->alivesave2[6] = pk->en->knights->next->alive + 48;
    pk->ga->alivesave2[7] = pk->en->knights->alive + 48;
    pk->ga->alivesave2[8] = pk->en->reaper->alive + 48;
}

void loadalive(package_t *pk)
{
    pk->en->reaper->alive = pk->ga->alivesave % 10;
    pk->en->knights->alive = pk->ga->alivesave % 100 / 10;
    pk->en->knights->next->alive = pk->ga->alivesave % 1000 / 100;
    pk->en->knights->next->next->alive = pk->ga->alivesave % 10000 / 1000;
    pk->en->paragons->alive = pk->ga->alivesave % 100000 / 10000;
    pk->en->paragons->next->alive = pk->ga->alivesave % 1000000 / 100000;
    pk->en->rats->alive = pk->ga->alivesave % 10000000 / 1000000;
    pk->en->rats->next->alive = pk->ga->alivesave % 100000000 / 10000000;
    pk->en->rats->next->next->alive = pk->ga->alivesave % 1000000000
    / 100000000;
}

void loadsave(package_t *pk)
{
    char *buff = mretbuff("src/save/s.txt");
    pk->en->c = 0;
    mmyreadfulls(buff, pk, 1);
    pk->ga->xpsave = pk->ga->tmpsave;
    mmyreadfulls(buff, pk, 0);
    pk->ga->ypsave = pk->ga->tmpsave;
    mmyreadfulls(buff, pk, 0);
    pk->ga->alivesave = pk->ga->tmpsave;
    pk->ct->ppl = (sfVector2f) {pk->ga->xpsave, pk->ga->ypsave};
    sfSprite_setPosition(pk->ct->spl, pk->ct->ppl);
    loadalive(pk);
}
