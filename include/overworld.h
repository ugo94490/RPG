/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** overworld header
*/

#ifndef OVERWORLD_H
#define OVERWORLD_H

typedef struct game_s
{
    game_object_list_t *objects;
    sfView *view;
    sprite_t *sprites;
} game_t;

void set_view_params(window_t *window, game_t *game, sfVector2f scale);
void draw_game(window_t *window, sfVector2f scale, game_t *game);
void analyse_event(window_t *window, game_t *game);
game_t create_game(void);

#endif
