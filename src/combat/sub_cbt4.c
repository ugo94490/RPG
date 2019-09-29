/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt4.c
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

text_t *change_pos(pkmn_list_t *node, window_t *window, pkmn_list_t *npc)
{
    text_t *stat = init_txt(window);

    change_text(itoa_dup(node->pokemon.max_health), &stat[0]);
    change_text(itoa_dup(node->pokemon.health), &stat[1]);
    change_text(itoa_dup(node->pokemon.level), &stat[2]);
    change_text(itoa_dup(npc->pokemon.level), &stat[3]);
    change_text(my_strdup(name[npc->pokemon.number]), &stat[4]);
    change_text(my_strdup(name[node->pokemon.number]), &stat[5]);
    change_text(itoa_dup(npc->pokemon.health), &stat[6]);
    change_text(itoa_dup(npc->pokemon.max_health), &stat[7]);
    return (stat);
}

game_object **init_player(window_t *window, int flag)
{
    game_object **tmp = malloc(sizeof(game_object *) * 2);
    sfIntRect rect = {0, 0, 170, 148};
    sfIntRect rect2 = {0, 0, 47, 109};
    sfVector2f pos = {380, 226};
    sfVector2f pos2 = {740, 30};

    tmp[0] = create_object(player[flag], pos, rect, window);
    tmp[1] = create_object("assets/rival_two.png", pos2, rect2, window);
    return (tmp);
}

int disp_sprite(game_object **tab, window_t *window,
game_object **character, npc_t *npc)
{
    display_game(tab, window, 5, 0);
    sfRenderWindow_drawSprite(window->window, character[0]->sprite, NULL);
    if (npc->type != -1)
        sfRenderWindow_drawSprite(window->window, character[1]->sprite, NULL);
    sfRenderWindow_display(window->window);
    return (0);
}

int free_character(game_object **character)
{
    destroy_obj(character[0]);
    destroy_obj(character[1]);
    free(character);
    return (0);
}

int animation(window_t *window, game_object **tab, int flag, npc_t *npc)
{
    game_object **character = init_player(window, flag);
    sfClock *clock = sfClock_create();
    sfTime time;
    int count = 0;
    display_game(tab, window, 5, 0);
    while (count != 5) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds >= 400000) {
            sfRenderWindow_clear(window->window, sfBlack);
            character[0]->rect.left += 173;
            sfSprite_setTextureRect(character[0]->sprite, character[0]->rect);
            disp_sprite(tab, window, character, npc);
            time = sfClock_restart(clock);
            count++;
        }
    }
    sfRenderWindow_clear(window->window, sfBlack);
    free_character(character);
    sfClock_destroy(clock);
    return (0);
}