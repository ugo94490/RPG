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

character_t *create_character(game_object_list_t **list)
{
    character_t *character = malloc(sizeof(character_t));

    character->status = 0;
    character->direction = 1;
    character->anim.rects = girl_rects;
    character->anim.nb_rects = 30;
    character->anim.baserect = 0;
    character->anim.actual_rect = 0;
    character->anim.endrect = 0;
    character->anim.time_anim = 0;
    character->anim.clock = create_clock();
    character->pos.x = 640;
    character->pos.y = 640;
    character->world = 0;
    put_object_in_objects(list, (void *)(character), PLAYER, 4);
    return (character);
}

sprite_t *create_sprites(void)
{
    sprite_t *sprites = malloc(sizeof(sprite_t) * 3);

    sprites[0] = create_sprite("assets/outdoors.png");
    sprites[1] = create_sprite("assets/characters.png");
    sprites[2] = create_sprite("assets/npcs.png");
    return (sprites);
}

void create_barry(game_object_list_t **list)
{
    npc_t *barry = malloc(sizeof(npc_t));

    barry->type = 0;
    barry->aggro = 0;
    barry->status = 0;
    barry->world = 0;
    barry->direction = 0;
    barry->pos.x = 608;
    barry->pos.y = 576;
    barry->objective.x = 608;
    barry->objective.y = 576;
    barry->anim.rects = barry_rects;
    barry->anim.nb_rects = 16;
    barry->anim.baserect = 0;
    barry->anim.actual_rect = 0;
    barry->anim.endrect = 0;
    barry->anim.time_anim = 0;
    barry->anim.clock = create_clock();
    put_object_in_objects(list, (void *)(barry), NPC, 4);
}

game_t create_game(void)
{
    game_t game;

    game.view = sfView_create();
    game.objects = NULL;
    game.evts = NULL;
    game.character = create_character(&(game.objects));
    create_barry(&(game.objects));
    game.status = 0;
    game.sprites = create_sprites();
    load_map(&(game.objects), game.character->world);
    read_evts("maps/permevts", &(game.evts));
    return (game);
}
