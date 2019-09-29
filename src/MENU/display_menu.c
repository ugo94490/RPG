/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu.c
*/

#include "main_menu.h"

static int menu(window_t *window)
{
    menu_t *menu = init_menu("assets/menu.jpg");

    sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
    while (sfRenderWindow_isOpen(window->window)) {
        sfSprite_setScale(menu->sprite, window->scale);
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        condition_howto(window);
        condition_play(window);
        condition_option(window);
        condition_trophy(window);
        condition_exit(window);
        menu_event(window);
        sfRenderWindow_display(window->window);
    }
    return (free_menu(menu));
}

static sfIntRect animation(menu_t *menu, sfClock *clock, sfIntRect rect)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    if (time.microseconds >= 40000) {
        rect.left += 1280;
        if (rect.left >= 8960) {
            rect.left = 0;
            rect.top += 960;
        }
        if (rect.left >= 6400 && rect.top >= 7680) {
            rect.left = 0;
            rect.top = 0;
        }
        sfSprite_setTextureRect(menu->sprite, rect);
        time = sfClock_restart(clock);
    }
    return (rect);
}

static int cinematic(window_t *window)
{
    menu_t *menu = init_menu("assets/intro.png");
    sfClock *clock = sfClock_create();
    sfIntRect rect = {0, 0, 1280, 960};

    sfSprite_setScale(menu->sprite, window->scale);
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        rect = animation(menu, clock, rect);
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        menu_event(window);
        sfRenderWindow_display(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            break;
    }
    sfClock_destroy(clock);
    return (free_menu(menu));
}

int display_menu(window_t *window)
{
    cinematic(window);
    menu(window);
    return 0;
}
