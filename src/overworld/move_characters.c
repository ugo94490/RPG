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

void set_pos_to_objective(character_t *character)
{
    character->pos = character->objective;
    character->status = 0;
}

void sub_move_character(character_t *character, float speed, sfTime time)
{
    if (character->direction == 1) {
        character->pos.y += speed * time.microseconds/1000000;
        if (character->pos.y >= character->objective.y)
            set_pos_to_objective(character);
    }
    if (character->direction == 2) {
        character->pos.x += speed * time.microseconds/1000000;
        if (character->pos.x >= character->objective.x)
            set_pos_to_objective(character);
    }
    if (character->direction == 3) {
        character->pos.y -= speed * time.microseconds/1000000;
        if (character->pos.y <= character->objective.y)
            set_pos_to_objective(character);
    }
    if (character->direction == 4) {
        character->pos.x -= speed * time.microseconds/1000000;
        if (character->pos.x <= character->objective.x)
            set_pos_to_objective(character);
    }
}

void move_character(character_t *character, sfTime time)
{
    float speed = 0;

    if (character->status == 0)
        return;
    if (character->status == 1)
        speed = 100.0;
    if (character->status == 2)
        speed = 250.0;
    if (character->status == 1 || character->status == 2)
        sub_move_character(character, speed, time);
}

void move_objects(game_object_list_t *objects, sfTime time)
{
    while (objects != NULL) {
        if (objects->type == PLAYER)
            move_character((character_t *)(objects->object), time);
        objects = objects->next;
    }
}
