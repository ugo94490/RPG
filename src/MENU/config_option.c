/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** config option
*/

#include "main_menu.h"

int config_option(window_t *window)
{
    menu_t *menu = init_menu("assets/menu.jpg");

    while (sfRenderWindow_isOpen(window->window)) {
        sfSprite_setScale(menu->sprite, window->scale);
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        condition_scale(window);
        condition_frame(window);
        if (condition_back(window) == 1)
            break;
        menu_event(window);
        sfRenderWindow_display(window->window);
    }
    return (free_menu(menu));
}
