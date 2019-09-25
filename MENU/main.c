/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu.c
*/

#include "main_menu.h"

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

sfIntRect set_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

int free_menu(menu_t *menu)
{
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->texture);
    free(menu);
    return (0);
}

int menu_event(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event))
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window->window);
    return (0);
}

int menu(window_t *window)
{
    menu_t *menu = init_menu("../assets/menu.jpg");

    sfSprite_setScale(menu->sprite, window->scale);
    sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        condition_howto(window);
        condition_play(window);
        condition_gear(window);
        condition_trophy(window);
        condition_exit(window);
        menu_event(window);
        sfRenderWindow_display(window->window);
    }
    return (free_menu(menu));
}

sfIntRect animation(menu_t *menu, sfClock *clock, sfIntRect rect)
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

int cinematic(window_t *window)
{
    menu_t *menu = init_menu("../assets/intro.png");
    sfClock *clock = sfClock_create();
    sfIntRect rect = {0, 0, 1280, 960};

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

int main(int ac, char **av, char **env)
{
    sfVector2f scale = {1, 1};
    //sfVector2f scale = {0.5, 0.5};
    window_t window = create_window(1280 * scale.x, 960 * scale.y, 32, "poukiman");

    (void) ac;
    (void) av;
    (void) env;
    window.scale = scale;
    cinematic(&window);
    menu(&window);
    sfRenderWindow_destroy(window.window);
}
