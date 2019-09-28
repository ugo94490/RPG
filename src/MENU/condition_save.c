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
    sfSprite *exit = init_button("assets/play.png");
    sfVector2f position = {866 * window->scale.x, 480 * window->scale.y};

    sfSprite_setScale(exit, window->scale);
    if (vct.x >= 866 && vct.x <= 1186 && vct.y >= 480 && vct.y <= 584) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(exit, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(1);
            condition_gender(window);
        } else
            display_button(exit, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(exit, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}

static int condition_actual(window_t *window, sfVector2f *scale, game_t *game)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/play.png");
    sfVector2f position = {94 * window->scale.x, 480 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= 94 && vct.x <= 414 && vct.y >= 480 && vct.y <= 584) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(1);
            temp_loop(window, scale, game);
        } else
            display_button(play, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(play, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (0);
}

int condition_save(window_t *window, sfVector2f *scale, game_t *game)
{
    menu_t *menu = init_menu("assets/menu.jpg");

    sfSprite_setScale(menu->sprite, window->scale);
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        condition_actual(window, scale, game);
        condition_new(window);
        if (condition_back(window) == 1)
            break;
        menu_event(window);
        sfRenderWindow_display(window->window);
    }
    return (free_menu(menu));
}
