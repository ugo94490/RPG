/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scale window
*/

#include "main_menu.h"

static void less_scale(window_t *window)
{
    window->scale.x -= 0.1;
    window->scale.y -= 0.1;
    change_mode(window, 1280 * window->scale.x, 960 * window->scale.y, 32);
    sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
}

static void more_scale(window_t *window)
{
    window->scale.x += 0.1;
    window->scale.y += 0.1;
    change_mode(window, 1280 * window->scale.x, 960 * window->scale.y, 32);
    sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
}

int condition_scale(window_t *win)
{
    sfSprite *exit = init_button("assets/play.png");
    sfVector2f position = {487 * win->scale.x, 95 * win->scale.y};
    int flag = 0;

    sfSprite_setScale(exit, win->scale);
    display_button(exit, position, set_rect(0, 0, 320, 104), win);
    flag = condition_left(win, position.x - 114 * win->scale.x, position.y);
    if (flag == 1)
        less_scale(win);
    flag = condition_right(win, position.x + 330 * win->scale.x, position.y);
    if (flag == 1)
        more_scale(win);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}
