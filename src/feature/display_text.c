/*
** EPITECH PROJECT, 2019
** MUl_my_rpg_2018
** File description:
** display text
*/

#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "my_rpg.h"
#include "graphics.h"

#define TEXT_COMBAT "assets/text_combat.png"

static setting_t set_setting(sfVector2f pos, window_t *window, int opt)
{
    setting_t set;

    if (opt == 1) {
        set.size = 17 * (0.5 * window->scale.x);
        set.pos.x = pos.x + 20 * (0.5 * window->scale.x);
        set.pos.y = pos.y + 25 * (0.5 * window->scale.y);
    } else {
        set.size = 17 * window->scale.x;
        set.pos.x = pos.x + 20 * window->scale.x;
        set.pos.y = pos.y + 25 * window->scale.y;
    }
    set.window = window->window;
    return set;
}

static game_object *set_spr(sfVector2f pos, window_t *window)
{
    sfIntRect rec = {0, 0, 0, 0};
    game_object *spr = create_object(TEXT_COMBAT, pos, rec, window);

    return spr;
}

static void wait_clock(void)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0;

    while (seconds < 0.5) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
    }
    sfClock_destroy(clock);
}

int display_text(char *base, sfVector2f pos, window_t *window, int opt)
{
    int flag = 0;
    sfVector2f scale = {0.50 * window->scale.x, 0.50 * window->scale.y};
    setting_t set = set_setting(pos, window, opt);
    game_object *spr = set_spr(pos, window);

    set.sprite = spr->sprite;
    if (opt == 1)
        sfSprite_setScale(spr->sprite, scale);
    while (sfRenderWindow_isOpen(window->window) == 1 && flag != 1) {
        sfSprite_setPosition(spr->sprite, pos);
        sfRenderWindow_drawSprite(window->window, spr->sprite, NULL);
        if (flag == 0)
            flag = do_text(base, set, window, opt);
        if (flag == -1)
            break;
    }
    if (opt == 0)
        wait_clock();
    destroy_obj(spr);
    return 0;
}
