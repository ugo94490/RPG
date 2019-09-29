/*
** EPITECH PROJECT, 2019
** menu_button.c
** File description:
** menu_button.c
*/

#include "main_menu.h"
#include "overworld.h"

int condition_trophy(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/trophée.png");
    sfVector2f position = {1230 * window->scale.x, 886 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= position.x && vct.x <= 1280 * window->scale.x
    && vct.y >= position.y && vct.y <= 960 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 50, 50, 74), window);
            sfRenderWindow_display(window->window);
            pause_time(1);
        } else
            display_button(play, position, set_rect(0, 50, 50, 74), window);
    } else
        display_button(play, position, set_rect(0, 0, 50, 74), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (0);
}

int condition_exit(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *exit = init_button("assets/exit.png");
    sfVector2f position = {866 * window->scale.x, 480 * window->scale.y};

    sfSprite_setScale(exit, window->scale);
    if (vct.x >= position.x && vct.x <= 1186 * window->scale.x
    && vct.y >= position.y && vct.y <= 584 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(exit, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            sfRenderWindow_close(window->window);
        } else
            display_button(exit, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(exit, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(exit)));
    sfSprite_destroy(exit);
    return (0);
}

int condition_play(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/play.png");
    sfVector2f position = {94 * window->scale.x, 480 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= position.x && vct.x <= 414 * window->scale.x
    && vct.y >= position.y && vct.y <= 584 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            condition_save(window);
        } else
            display_button(play, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(play, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (0);
}

int condition_howto(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/howto.png");
    sfVector2f position = {487 * window->scale.x, 10 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= position.x && vct.x <= 825 * window->scale.x
    && vct.y >= position.y && vct.y <= 116 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(1);
        } else
            display_button(play, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(play, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (0);
}

/* int condition_gear(window_t *window) */
/* { */
/*     sfVector2i vct = sfMouse_getPositionRenderWindow(window->window); */
/*     sfSprite *play = init_button("assets/gear.png"); */
/*     sfVector2f position = {0 * window->scale.x, 910 * window->scale.y}; */

/*     sfSprite_setScale(play, window->scale); */
/*     if (vct.x >= 0 && vct.x <= 50 * window->scale.x */
/*     && vct.y >= position.y && vct.y <= 960 * window->scale.y) { */
/*         if (sfMouse_isButtonPressed(sfMouseLeft)) { */
/*             display_button(play, position, set_rect(0, 50, 50, 50), window); */
/*         } else */
/*             display_button(play, position, set_rect(0, 50, 50, 50), window); */
/*     } else */
/*         display_button(play, position, set_rect(0, 0, 50, 50), window); */
/*     sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play))); */
/*     sfSprite_destroy(play); */
/*     return (0); */
/* } */

int condition_option(window_t *window)
{
    int flag = 0;
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    sfSprite *play = init_button("assets/options.png");
    sfVector2f position = {487 * window->scale.x, 800 * window->scale.y};

    sfSprite_setScale(play, window->scale);
    if (vct.x >= position.x && vct.x <= 825 * window->scale.x
    && vct.y >= position.y && vct.y <= 904 * window->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_button(play, position, set_rect(0, 870, 320, 104), window);
            sfRenderWindow_display(window->window);
            pause_time(0.15);
            config_option(window);
        } else
            display_button(play, position, set_rect(0, 435, 320, 104), window);
    } else
        display_button(play, position, set_rect(0, 0, 320, 104), window);
    sfTexture_destroy((sfTexture *)(sfSprite_getTexture(play)));
    sfSprite_destroy(play);
    return (flag);
}
