/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set frame
*/

#include "main_menu.h"

static int less_frame(window_t *window, int frame)
{
    frame -= 10;
    if (frame <= 0)
        frame = 10;
    sfRenderWindow_setFramerateLimit(window->window, frame);
    return frame;
}

static int more_frame(window_t *window, int frame)
{
    frame += 10;
    if (frame >= 120)
        frame = 120;
    sfRenderWindow_setFramerateLimit(window->window, frame);
    return frame;
}

int condition_frame(window_t *window)
{
    static int frame = 60;
    sfSprite *exit = init_button("assets/options.png");
    sfVector2f position = {487 * window->scale.x, 294 * window->scale.y};
    int flag = 0;

    sfSprite_setScale(exit, window->scale);
    display_button(exit, position, set_rect(0, 0, 320, 104), window);
    flag = condition_left(window, position.x - 114 * window->scale.x, position.y);
    if (flag == 1)
        frame = less_frame(window, frame);
    flag = condition_right(window, position.x + 330 * window->scale.x, position.y);
    if (flag == 1)
        frame = more_frame(window, frame);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}
