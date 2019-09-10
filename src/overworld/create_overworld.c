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

void create_character(game_object_list_t **list)
{
    character_t *character = malloc(sizeof(character_t));

    character->status = 0;
    character->direction = 1;
    character->anim.rects = girl_rects;
    character->anim.nb_rects = 30;
    character->anim.baserect = 1;
    character->anim.actual_rect = 0;
    character->anim.endrect = 0;
    character->anim.time_anim = 0;
    character->anim.clock = create_clock();
    character->pos.x = 640;
    character->pos.y = 640;
    put_object_in_objects(list, (void *)(character), PLAYER, 4);
}

sprite_t *create_sprites(void)
{
    sprite_t *sprites = malloc(sizeof(sprite_t) * 2);

    sprites[0] = create_sprite("assets/outdoors.png");
    sprites[1] = create_sprite("assets/girl.png");
    return (sprites);
}

game_t create_game(void)
{
    game_t game;

    game.view = sfView_create();
    game.objects = NULL;
    game.sprites = create_sprites();
    load_overworld(&(game.objects));
    create_character(&(game.objects));
    return (game);
}
