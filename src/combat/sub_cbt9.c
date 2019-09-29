/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt9.c
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

int display_stat(window_t *window, text_t *stat, int lim)
{
    for (int i = 0; i < lim; i++)
        sfRenderWindow_drawText(window->window, stat[i].text, NULL);
    return (0);
}

game_object *display_all(misc_t *misc, window_t *window, sfIntRect rect,
pkmn_list_t *linked)
{
    game_object *sprite;
    sfVector2f position = {340, 30};
    int nb_atk = get_atk(linked, misc->nb);

    display_game(misc->tab, window, 8, 0);
    display_stat(window, misc->stat, 8);
    sprite = create_object(asset_atk[nb_atk], position, rect, window);
    sfSprite_setTextureRect(sprite->sprite, rect);
    return (sprite);
}

void destroy_anim(misc_t *misc, sfClock *clock, window_t *window,
game_object *sprite)
{
    display_game(misc->tab, window, 8, 0);
    display_stat(window, misc->stat, 8);
    destroy_obj(sprite);
    sfClock_destroy(clock);
}

sfIntRect display_end(misc_t *misc, window_t *window, game_object *sprite,
sfIntRect rect)
{
    sfRenderWindow_clear(window->window, sfBlack);
    display_game(misc->tab, window, 3, 0);
    display_game(misc->tab, window, 7, 6);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
    display_game(misc->tab, window, 5, 4);
    display_game(misc->tab, window, 8, 8);
    display_stat(window, misc->stat, 8);
    rect.top += 340;
    rect.top >= 2382 ? rect.left += 605 : 0;
    return (rect);
}

int attack_anim(misc_t *misc, window_t *window, pkmn_list_t *linked)
{
    sfIntRect rect = {0, 0, 605, 340};
    game_object *sprite;
    sfClock *clock;
    sfTime time;

    if (get_atk(linked, misc->nb) == -1)
        return (0);
    sprite = display_all(misc, window, rect, linked);
    clock = sfClock_create();
    while (sfRenderWindow_isOpen(window->window)) {
        time = sfClock_getElapsedTime(clock);
        if (rect.left >= 1210)
            break;
        if (time.microseconds >= 400000)
            1 == 1 ? rect = display_end(misc, window, sprite, rect),
        time = sfClock_restart(clock) : sfClock_restart(clock);
        sfRenderWindow_display(window->window);
    }
    destroy_anim(misc, clock, window, sprite);
    return (0);
}