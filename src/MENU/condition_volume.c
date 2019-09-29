/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set volume
*/

#include "main_menu.h"

static void less_volume(window_t *window)
{
    window->volume -= 2.5;
    if (window->volume < 0)
        window->volume = 0;
}

static void more_volume(window_t *window)
{
    window->volume += 2.5;
    if (window->volume > 100)
        window->volume = 100;
}

int condition_volume(window_t *window)
{
    sfSprite *volume = init_button("assets/exit.png");
    sfVector2f position = {487 * window->scale.x, 494 * window->scale.y};
    int flag = 0;

    sfSprite_setScale(volume, window->scale);
    display_button(volume, position, set_rect(0, 0, 320, 104), window);
    flag = condition_left(window, position.x - 114 * window->scale.x, position.y);
    if (flag == 1)
        less_volume(window);
    flag = condition_right(window, position.x + 330 * window->scale.x, position.y);
    if (flag == 1)
        more_volume(window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(volume)));
    sfSprite_destroy(volume);
    return (0);
}
