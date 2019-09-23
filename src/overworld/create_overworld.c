/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_overworld
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "graphics.h"
#include "systems.h"
#include "sounds.h"
#include "game_object.h"
#include "overworld.h"
#include "overworld_rects.h"

sprite_t *create_sprites(void)
{
    sprite_t *sprites = malloc(sizeof(sprite_t) * 3);

    if (sprites == NULL)
        return (NULL);
    sprites[0] = create_sprite("assets/overworld.png");
    sprites[1] = create_sprite("assets/characters.png");
    sprites[2] = create_sprite("assets/npcs.png");
    return (sprites);
}

game_t create_game(void)
{
    game_t game;

    game.view = sfView_create();
    game.objects = NULL;
    game.evts = NULL;
    load_npcs(&(game.objects));
    game.status = 0;
    game.sprites = create_sprites();
    game.character = load_character("save/actualsave/characterInfo",
    &(game.objects));
    load_map(&(game.objects), game.character->world);
    read_evts("maps/permevts", &(game.evts));
    return (game);
}
