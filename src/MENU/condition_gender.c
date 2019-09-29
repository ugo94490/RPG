/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** choose save
*/

#include "main_menu.h"

static int condition_boy_one(window_t *window, sfVector2f *scale)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/skin_one.png");
    sfVector2f position = {94 * window->scale.x, 280 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= position.x && vct.x <= 414 * window->scale.x
    && vct.y >= position.y && vct.y <= 384 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            temp_loop(window, scale, 0, 2);
        } else
            display_button(play, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(play, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (0);
}

static int condition_boy_two(window_t *window, sfVector2f *scale)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *exit = init_button("assets/skin_two.png");
    sfVector2f position = {94 * window->scale.x, 580 * window->scale.y};

    sfSprite_setScale(exit, window->scale);
    if (vct.x >= position.x && vct.x <= 414 * window->scale.x
    && vct.y >= position.y && vct.y <= 684 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(exit, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            temp_loop(window, scale, 0, 3);
        } else
            display_button(exit, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(exit, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}

static int condition_girl_one(window_t *window, sfVector2f *scale)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *exit = init_button("assets/skin_three.png");
    sfVector2f position = {866 * window->scale.x, 280 * window->scale.y};

    sfSprite_setScale(exit, window->scale);
    if (vct.x >= position.x && vct.x <= 1186 * window->scale.x
    && vct.y >= position.y && vct.y <= 384 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(exit, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            temp_loop(window, scale, 0, 0);
        } else
            display_button(exit, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(exit, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}

static int condition_girl_two(window_t *window, sfVector2f *scale)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *exit = init_button("assets/skin_four.png");
    sfVector2f position = {866 * window->scale.x, 580 * window->scale.y};

    sfSprite_setScale(exit, window->scale);
    if (vct.x >= position.x && vct.x <= 1186 * window->scale.x
    && vct.y >= position.y && vct.y <= 684 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(exit, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            temp_loop(window, scale, 0, 1);
        } else
            display_button(exit, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(exit, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}

int condition_gender(window_t *window, sfVector2f *scale)
{
    menu_t *menu = init_menu("assets/menu.jpg");

    sfSprite_setScale(menu->sprite, window->scale);
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        condition_boy_one(window, scale);
        condition_girl_one(window, scale);
        condition_boy_two(window, scale);
        condition_girl_two(window, scale);
        if (condition_back(window) == 1)
            break;
        menu_event(window);
        sfRenderWindow_display(window->window);
    }
    return (free_menu(menu));
}
