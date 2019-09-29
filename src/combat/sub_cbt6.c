/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt6.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

int destroy_tab(game_object **tab)
{
    for (int i = 0; tab[i]; i++)
        destroy_obj(tab[i]);
    free(tab);
    return (0);
}

int display_box(game_object **box, window_t *window)
{
    for (int i = 0; box[i]; i++)
        sfRenderWindow_drawSprite(window->window, box[i]->sprite, NULL);
    return (0);
}

int misc_atk(misc_t *misc, game_object **box, window_t *window,
game_object *atk)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, atk->sprite, NULL);
    display_game(misc->tab, window, 7, 1);
    display_box(box, window);
    display_cursor(window, misc);
    event(window);
    return (0);
}

text_t *init_name(pkmn_list_t *linked, window_t *window)
{
    text_t *stat = malloc(sizeof(text_t) * 9);
    int size = 15 * window->scale.x;
    sfVector2f tmp = {0, 0};
    sfVector2f tmp2 = {0, 0};

    for (int i = 0; i < 4; i++) {
        tmp.x = atk_txt[i].x * window->scale.x;
        tmp.y = atk_txt[i].y * window->scale.y;
        tmp2.x = atk_txt[i + 4].x * window->scale.x;
        tmp2.y = atk_txt[i + 4].y * window->scale.y;
        stat[i] = create_text(atk_name[linked->pokemon.atks[i].number],
        "assets/classic.ttf", size, tmp);
        stat[i + 4] = create_text(itoa_dup(linked->pokemon.atks[i].power),
        "assets/classic.ttf", size, tmp2);
        sfText_setFillColor(stat[i].text, sfBlack);
        sfText_setFillColor(stat[i + 4].text, sfBlack);
    }
    return (stat);
}

int destroy_atkhud(text_t *name_pow, game_object **box, game_object *atk,
int flag)
{
    destroy_font(name_pow, 9 - 1);
    destroy_tab(box);
    destroy_obj(atk);
    return (flag);
}