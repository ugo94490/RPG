/*
** EPITECH PROJECT, 2019
** bouton_tools.c
** File description:
** bouton_tools.c
*/

#include "main_menu.h"

sfSprite *init_button(char *buffer)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(buffer, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

int display_button(sfSprite *sprite, sfVector2f position, sfIntRect
rect, window_t *window)
{
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window->window, sprite, NULL);
    return (0);
}
