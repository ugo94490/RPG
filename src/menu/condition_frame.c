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

int condition_frame(window_t *win)
{
    static int frame = 60;
    sfSprite *exit = init_button("assets/framerate.png");
    sfVector2f position = {487 * win->scale.x, 294 * win->scale.y};
    int flag = 0;

    sfSprite_setScale(exit, win->scale);
    display_button(exit, position, set_rect(0, 0, 320, 104), win);
    flag = condition_left(win, position.x - 114 * win->scale.x, position.y);
    if (flag == 1)
        frame = less_frame(win, frame);
    flag = condition_right(win, position.x + 330 * win->scale.x, position.y);
    if (flag == 1)
        frame = more_frame(win, frame);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}
