/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt11.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"
#include "cbt.h"

int attack(game_object *sp, sfClock *clk, window_t *window)
{
    sfTime time;
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    (prev.x <= 1 * window->scale.x) ? toggle = 0 : 0;
    (prev.x >= 1.04 * window->scale.x) ? toggle = 1 : 0;
    if (time.microseconds >= 50000) {
        if (toggle == 0)
            add_attack(&prev, &position, 0, window);
        if (toggle == 1)
            add_attack(&prev, &position, 1, window);
        time = sfClock_restart(clk);
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window->window, sp->sprite, NULL);
    return (0);
}

int bag(game_object *sp, sfClock *clk, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(clk);
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    (prev.x <= 1 * window->scale.x) ? toggle = 0 : 0;
    (prev.x >= 1.04 * window->scale.x) ? toggle = 1 : 0;
    if (time.microseconds >= 50000) {
        if (toggle == 0)
            add_bag(&prev, &position, 0, window);
        if (toggle == 1)
            add_bag(&prev, &position, 1, window);
        time = sfClock_restart(clk);
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window->window, sp->sprite, NULL);
    return (0);
}

int display_cursor(window_t *win, misc_t *misc)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f pos1 = {pos.x, pos.y};

    sfSprite_setPosition(misc->sprite, pos1);
    sfRenderWindow_drawSprite(win->window, misc->sprite, NULL);
    return (0);
}

int next_mode(window_t *win, int flag, int ret, sfVector2i vct)
{
    if (vct.x >= 548 * win->scale.x && vct.x <= 730 * win->scale.x
    && vct.y >= 842 * win->scale.y && vct.y <= 948 * win->scale.y) {
        ret = 3;
        if (sfMouse_isButtonPressed(sfMouseLeft) && flag != 6) {
            pause_time(0.3);
            ret = 5;
        }
    }
    return (ret);
}

int mode(window_t *win, int flag)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(win->window);
    int ret = 0;

    if (vct.x >= 343 * win->scale.x && vct.x <= 936 * win->scale.x &&
    vct.y >= 537 * win->scale.y && vct.y <= 812 * win->scale.x) {
        ret = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            pause_time(0.3) == 0 ? ret = 6 : 0;
    }
    (vct.x >= 340 * win->scale.x && vct.x <= 522 * win->scale.x && vct.y >=
    823 * win->scale.y && vct.y <= 929 * win->scale.y) ? ret = 2 : 0;
    ret = next_mode(win, flag, ret, vct);
    (vct.x >= 756 * win->scale.x && vct.x <= 938 * win->scale.x && vct.y >=
    823 * win->scale.y && vct.y <= 929 * win->scale.y) ? ret = 4 : 0;
    return (ret);
}