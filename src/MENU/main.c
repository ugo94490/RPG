/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu.c
*/

#include "main_menu.h"

int main(int ac, char **av, char **env)
{
    sfVector2f scale = {1, 1};
    window_t window = create_window(1280 * scale.x, 960 * scale.y, 32,
    "poukiman");

    (void) ac;
    (void) av;
    (void) env;
    window.scale = scale;
    display_menu(&window);
    sfRenderWindow_destroy(window.window);
}
