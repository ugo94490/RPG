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

int condition_scale(window_t *window)
{
    sfSprite *exit = init_button("assets/play.png");
    sfVector2f position = {487 * window->scale.x, 190 * window->scale.y};
    int flag = 0;

    sfSprite_setScale(exit, window->scale);
    display_button(exit, position, set_rect(0, 0, 320, 104), window);
    flag = condition_left(window, position.x - 114 * window->scale.x, position.y);
    if (flag == 1)
        less_scale(window);
    flag = condition_right(window, position.x + 330 * window->scale.x, position.y);
    if (flag == 1)
        more_scale(window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}
