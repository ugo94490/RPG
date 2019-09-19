/*
** EPITECH PROJECT, 2019
** CGraphical programming
** File description:
** window_functions
*/

#include <SFML/Graphics.h>
#include "graphics.h"

window_t create_window(int resx, int resy, int colours, char *title)
{
    window_t window;
    sfVideoMode mode = {resx, resy, colours};

    window.mode = mode;
    window.title = title;
    window.window = sfRenderWindow_create(window.mode, title,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window.window, 60);
    sfRenderWindow_setMouseCursorVisible(window.window, sfTrue);
    window.scale.x = 1;
    window.scale.y = 1;
    return (window);
}

void change_mode(window_t *window, int resx, int resy, int colours)
{
    window->mode.width = resx;
    window->mode.height = resy;
    window->mode.bitsPerPixel = colours;
    sfRenderWindow_destroy(window->window);
    window->window = sfRenderWindow_create(window->mode,
    window->title, sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
}
