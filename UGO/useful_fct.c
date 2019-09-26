/*
** EPITECH PROJECT, 2019
** useful_fct.c
** File description:
** useful_fct.c
*/

#include "my_rpg.h"

struct game_object *create_object(char *spritesheet, sfVector2f
position, sfIntRect rect1, window_t *window)
{
    game_object *assets = malloc(sizeof(game_object));

    assets->texture = sfTexture_createFromFile(spritesheet, NULL);
    assets->sprite = sfSprite_create();
    sfSprite_setTexture(assets->sprite, assets->texture, sfTrue);
    assets->pos.x = position.x * window->scale.x;
    assets->pos.y = position.y * window->scale.y;
    sfSprite_setScale(assets->sprite, window->scale);
    sfSprite_setPosition(assets->sprite, assets->pos);
    assets->rect = rect1;
    if (assets->sprite == NULL || assets->texture == NULL)
        return (NULL);
    return (assets);
}

void destroy_obj(struct game_object *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    free(obj);
}

void display_pause(window_t *window)
{
    sfSprite *menu = sfSprite_create();
    sfTexture *menu_tex = sfTexture_createFromFile("./img/pause.png", NULL);
    sfVector2f position = {0, 0};

    sfSprite_setTexture(menu, menu_tex, sfTrue);
    sfSprite_setPosition(menu, position);
    sfRenderWindow_drawSprite(window->window, menu, NULL);
    sfRenderWindow_display(window->window);
}

int event(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event))
        close_window(event, window);
    return (0);
}

void close_window(sfEvent event, window_t *window)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window->window);
}
