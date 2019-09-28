/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button back
*/

#include "main_menu.h"

int condition_back(window_t *window)
{
    int flag = 0;
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/back.png");
    sfVector2f position = {487 * window->scale.x, 800 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= position.x && vct.x <= 825 * window->scale.x
    && vct.y >= position.y && vct.y <= 874 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(1);
            flag = 1;
        } else
            display_button(play, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(play, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (flag);
}
