/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** choose if you want to load a new or the old save
*/

#include "main_menu.h"

static int condition_new(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *exit = init_button("assets/new_save.png");
    sfVector2f position = {866 * window->scale.x, 480 * window->scale.y};

    sfSprite_setScale(exit, window->scale);
    if (vct.x >= position.x && vct.x <= 1186 * window->scale.x
    && vct.y >= position.y && vct.y <= 584 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(exit, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.1);
            condition_gender(window);
        } else
            display_button(exit, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(exit, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}

static int condition_actual(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/load_save.png");
    sfVector2f position = {94 * window->scale.x, 480 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= position.x && vct.x <= 414 * window->scale.x
    && vct.y >= position.y && vct.y <= 584 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.1);
            temp_loop(window, 1, 0);
        } else
            display_button(play, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(play, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (0);
}

int condition_save(window_t *window)
{
    menu_t *menu = init_menu("assets/menu.jpg");

    while (sfRenderWindow_isOpen(window->window)) {
        sfSprite_setScale(menu->sprite, window->scale);
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        condition_actual(window);
        condition_new(window);
        if (condition_back(window) == 1)
            break;
        menu_event(window);
        sfRenderWindow_display(window->window);
    }
    return (free_menu(menu));
}
