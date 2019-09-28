/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event for menu
*/

#include "main_menu.h"

int menu_event(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event))
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window->window);
    return (0);
}

sfIntRect set_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

int pause_time(float sec)
{
    sfTime time = sfTime_Zero;
    sfClock *clock = sfClock_create();

    while (1) {
        time = sfClock_getElapsedTime(clock);
        if ((time.microseconds / 1000000.0) > sec)
            break;
    }
    sfClock_destroy(clock);
    return (0);
}

menu_t *init_menu(char *path)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->texture = sfTexture_createFromFile(path, NULL);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    return (menu);
}

int free_menu(menu_t *menu)
{
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->texture);
    free(menu);
    return (0);
}
