/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** misc
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

character_t *get_character_in_objects(game_object_list_t *objects)
{
    character_t *character = NULL;

    while (objects != NULL && character == NULL) {
        if (objects->type == PLAYER)
            character = (character_t *)(objects->object);
    }
    return (character);
}

void update_character_status(character_t *character, int status, int direction)
{
    if (direction != 0)
        character->direction = direction;
    character->status = status;
}

void set_view_params(window_t *window, game_t *game, sfVector2f scale)
{
    character_t *player = get_character_in_objects(game->objects);
    sfVector2f viewSize = {1280*scale.x/2, 960*scale.y/2};
    sfVector2f temppos = {(player->pos.x+character_width/2)*scale.x,
    (player->pos.y+character_height/6)*scale.y};

    sfView_setCenter(game->view, temppos);
    sfView_setSize(game->view, viewSize);
    sfRenderWindow_setView(window->window, game->view);
}
