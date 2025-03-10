/*
** EPITECH PROJECT, 2022
** main
** File description:
** main function
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include <stdio.h>
#include <stdlib.h>


void scene_1(package_t *pk)
{
    sfView_setCenter(pk->ct->view,
    (sfVector2f) {pk->ct->ppl.x + 75, pk->ct->ppl.y + 52});
    sfRenderWindow_setView(pk->sc->window, pk->ct->view);
    backgame(pk);
    game(pk);
    sfRenderWindow_setView(pk->sc->window, pk->ga->gui);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ct->sfo, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ct->sca, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ct->sst, NULL);
    sfRenderWindow_drawSprite(pk->sc->window, pk->ct->spv, NULL);
    sfRenderWindow_setView(pk->sc->window, pk->pa->pa);
}

void wclose(package_t *pk)
{
    if (pk->sc->event.type == sfEvtClosed)
        sfRenderWindow_close(pk->sc->window);
}

sfRenderWindow *cmywindow(int x, int y, int px, char *title)
{
    sfVideoMode videomode = {x, y, px};
    return (sfRenderWindow_create(videomode, title, sfResize | sfClose, NULL));
}

void create_window(package_t *pk)
{
    pk->sc->window = cmywindow(1920, 1080, 32, "My_rpg");
    while (sfRenderWindow_isOpen(pk->sc->window)) {
        sfRenderWindow_display(pk->sc->window);
        sfRenderWindow_clear(pk->sc->window, sfBlack);
        if (pk->scene == 0) {
            backmenu(pk);
            menu(pk);
        } if (pk->scene == 2)
            scene_1(pk);
        if (pk->scene == 1)
            scene_2(pk);
        if (pk->scene == 3)
            scene_3(pk);
        if (pk->scene == 4)
            scene_4(pk);
    }
    sfRenderWindow_destroy(pk->sc->window);
}

int main(void)
{
    package_t *pk = malloc(sizeof(package_t));
    mallocage(pk);
    init_main(pk);
    create_window(pk);
    return 0;
}
