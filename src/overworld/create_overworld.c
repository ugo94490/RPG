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
#include "overworld_sound.h"

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

static void load_save(game_t *game)
{
    load_npcs("save/actualsave/npcs", &(game->objects));
    game->character = load_character("save/actualsave/characterInfo",
    &(game->objects));
    game->music = load_music(game->character->music);
    read_evts("save/actualsave/tempevts", &(game->evts), 0);
}

static void load_newsave(game_t *game, int gender)
{
    load_npcs("save/newsave/npcs", &(game->objects));
    game->character = load_character("save/newsave/characterInfo",
    &(game->objects));
    game->music = load_music(game->character->music);
    read_evts("save/newsave/tempevts", &(game->evts), 0);
    game->character->type = gender;
}

game_t create_game(int arg, int gender)
{
    game_t game;

    game.view = sfView_create();
    game.objects = NULL;
    game.evts = NULL;
    game.status = 0;
    game.sprites = create_sprites();
    read_evts("maps/permevts", &(game.evts), 1);
    if (arg == 1)
        load_save(&game);
    else
        load_newsave(&game, gender);
    load_map(&(game.objects), game.character->world);
    return (game);
}
