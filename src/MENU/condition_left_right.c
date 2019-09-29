/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** left and right button
*/

#include "main_menu.h"

int condition_left(window_t *window, float x, float y)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *left = init_button("assets/bouton_gauche.png");
    sfVector2f position = {x, y};
    int flag = 0;

    sfSprite_setScale(left, window->scale);
    if (vct.x >= x && vct.x <= x + 104 * window->scale.x
    && vct.y >= y && vct.y <= y + 104 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(left, position, set_rect(0, 416, 104, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            flag = 1;
        } else
            display_button(left, position, set_rect(0, 208, 104, 104), window);
    } else
        display_button(left, position, set_rect(0, 0, 104, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(left)));
    sfSprite_destroy(left);
    return (flag);
}

int condition_right(window_t *window, float x, float y)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *right = init_button("assets/bouton_droit.png");
    sfVector2f position = {x, y};
    int flag = 0;

    sfSprite_setScale(right, window->scale);
    if (vct.x >= x && vct.x <= x + 104 * window->scale.x
    && vct.y >= y && vct.y <= y + 104 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(right, position, set_rect(0, 416, 104, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            flag = 1;
        } else
            display_button(right, position, set_rect(0, 208, 104, 104), window);
    } else
        display_button(right, position, set_rect(0, 0, 104, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(right)));
    sfSprite_destroy(right);
    return (flag);
}
