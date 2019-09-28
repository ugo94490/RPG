/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_events_overword_header
*/

#ifndef EVT_OVERWORLD_H
#define EVT_OVERWORLD_H

void move_right(game_t *game);
void move_left(game_t *game);
void move_up(game_t *game);
void move_down(game_t *game);
void move_npc_left(game_t *game, npc_t *npc);
void move_npc_down(game_t *game, npc_t *npc);
void move_npc_up(game_t *game, npc_t *npc);
void move_npc_right(game_t *game, npc_t *npc);

#endif
