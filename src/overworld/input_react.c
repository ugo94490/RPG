/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** input_react
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void move_right(window_t *window, game_t *game)
{
    int newstatus = 1;
    character_t *character = get_character_in_objects(game->objects);
    sfVector2f newobjective = {character->pos.x + ground_width,
    character->pos.y};

    if (character->status != 0)
        return;
    character->direction = 2;
    if (check_can_go(character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    character->objective = newobjective;
    update_character_status(character, newstatus, 2);
}

void move_left(window_t *window, game_t *game)
{
    int newstatus = 1;
    character_t *character = get_character_in_objects(game->objects);
    sfVector2f newobjective = {character->pos.x - ground_width,
    character->pos.y};

    if (character->status != 0)
        return;
    character->direction = 4;
        if (check_can_go(character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    character->objective = newobjective;
    update_character_status(character, newstatus, 4);
}

void move_up(window_t *window, game_t *game)
{
    int newstatus = 1;
    character_t *character = get_character_in_objects(game->objects);
    sfVector2f newobjective = {character->pos.x,
    character->pos.y - ground_height};

    if (character->status != 0)
        return;
    character->direction = 3;
    if (check_can_go(character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    character->objective = newobjective;
    update_character_status(character, newstatus, 3);
}

void move_down(window_t *window, game_t *game)
{
    int newstatus = 1;
    character_t *character = get_character_in_objects(game->objects);
    sfVector2f newobjective = {character->pos.x,
    character->pos.y + ground_height};

    if (character->status != 0)
        return;
    character->direction = 1;
    if (check_can_go(character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    character->objective = newobjective;
    update_character_status(character, newstatus, 1);
}
