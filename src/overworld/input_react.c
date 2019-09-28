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
    sfVector2f newobjective = {game->character->pos.x + ground_width,
        game->character->pos.y};

    if (game->character->status != 0)
        return;
    game->character->direction = 2;
    if (check_can_go(game->character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    game->character->objective = newobjective;
    update_character_status(game->character, newstatus, 2);
}

void move_left(window_t *window, game_t *game)
{
    int newstatus = 1;
    sfVector2f newobjective = {game->character->pos.x - ground_width,
        game->character->pos.y};

    if (game->character->status != 0)
        return;
    game->character->direction = 4;
    if (check_can_go(game->character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    game->character->objective = newobjective;
    update_character_status(game->character, newstatus, 4);
}

void move_up(window_t *window, game_t *game)
{
    int newstatus = 1;
    sfVector2f newobjective = {game->character->pos.x,
        game->character->pos.y - ground_height};

    if (game->character->status != 0)
        return;
    game->character->direction = 3;
    if (check_can_go(game->character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    game->character->objective = newobjective;
    update_character_status(game->character, newstatus, 3);
}

void move_down(window_t *window, game_t *game)
{
    int newstatus = 1;
    sfVector2f newobjective = {game->character->pos.x,
        game->character->pos.y + ground_height};

    if (game->character->status != 0)
        return;
    game->character->direction = 1;
    if (check_can_go(game->character, game->objects, newobjective) == 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        newstatus = 2;
    game->character->objective = newobjective;
    update_character_status(game->character, newstatus, 1);
}
