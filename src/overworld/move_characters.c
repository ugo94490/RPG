/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move characters
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

static void check_evt_trigger(game_t *game, sfVector2f pos, int locmap)
{
    evt_list_t *save = game->evts;

    while (game->evts != NULL) {
        if (check_col_event(pos, locmap, game->evts->event) == 1)
            activate_event(game, game->evts);
        game->evts = game->evts->next;
    }
    game->evts = save;
}

static void set_pos_to_objective(game_t *game, character_t *character)
{
    character->pos = character->objective;
    character->status = 0;
    check_evt_trigger(game, character->pos, character->world);
}

static void sub_move_character(game_t *game, character_t *character,
float speed, sfTime time)
{
    if (character->direction == 1) {
        character->pos.y += speed * time.microseconds/1000000;
        if (character->pos.y >= character->objective.y)
            set_pos_to_objective(game, character);
    }
    if (character->direction == 2) {
        character->pos.x += speed * time.microseconds/1000000;
        if (character->pos.x >= character->objective.x)
            set_pos_to_objective(game, character);
    }
    if (character->direction == 3) {
        character->pos.y -= speed * time.microseconds/1000000;
        if (character->pos.y <= character->objective.y)
            set_pos_to_objective(game, character);
    }
    if (character->direction == 4) {
        character->pos.x -= speed * time.microseconds/1000000;
        if (character->pos.x <= character->objective.x)
            set_pos_to_objective(game, character);
    }
}

void move_character(game_t *game, character_t *character, sfTime time)
{
    float speed = 0;

    if (character->status == 0)
        return;
    if (character->status == 1)
        speed = 100.0;
    if (character->status == 2)
        speed = 250.0;
    if (character->status == 1 || character->status == 2)
        sub_move_character(game, character, speed, time);
}

void move_objects(game_t *game,
game_object_list_t *objects, sfTime time)
{
    while (objects != NULL) {
        if (objects->type == PLAYER)
            move_character(game, (character_t *)(objects->object), time);
        if (objects->type == NPC)
            move_npc((npc_t *)(objects->object), time);
        objects = objects->next;
    }
}
