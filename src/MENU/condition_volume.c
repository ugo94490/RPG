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

int condition_volume(window_t *win)
{
    sfSprite *volume = init_button("assets/exit.png");
    sfVector2f position = {487 * win->scale.x, 494 * win->scale.y};
    int flag = 0;

    sfSprite_setScale(volume, win->scale);
    display_button(volume, position, set_rect(0, 0, 320, 104), win);
    flag = condition_left(win, position.x - 114 * win->scale.x, position.y);
    if (flag == 1)
        less_volume(win);
    flag = condition_right(win, position.x + 330 * win->scale.x, position.y);
    if (flag == 1)
        more_volume(win);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(volume)));
    sfSprite_destroy(volume);
    return (0);
}
