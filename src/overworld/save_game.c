/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_game
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

void save_game(game_t *game)
{
    save_character("save/actualsave/characterInfo", game->character);
    save_npcs("save/actualsave/npcs", game->objects);
    save_evts(game->evts);
    save_quests(game->character->quests);
}
