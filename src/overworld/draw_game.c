/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw game
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void draw_ground(window_t *window,
sprite_t sprite, ground_t *ground)
{
    sfVector2f temppos = {ground->pos.x * window->scale.x,
    ground->pos.y * window->scale.y};

    sfSprite_setScale(sprite.sprite, window->scale);
    sfSprite_setTextureRect(sprite.sprite,
    ground->anim.rects[ground->anim.actual_rect]);
    sfSprite_setPosition(sprite.sprite, temppos);
    sfRenderWindow_drawSprite(window->window, sprite.sprite, NULL);
}

void draw_character(window_t *window,
sprite_t sprite, character_t *character)
{
    sfVector2f temppos = {character->pos.x * window->scale.x,
    character->pos.y * window->scale.y};
    sfVector2f vector0 = {0, 0};
    sfVector2f origin = {16, 32};

    sfSprite_setOrigin(sprite.sprite, origin);
    sfSprite_setScale(sprite.sprite, window->scale);
    sfSprite_setTextureRect(sprite.sprite,
    character->anim.rects[character->anim.actual_rect]);
    sfSprite_setPosition(sprite.sprite, temppos);
    sfRenderWindow_drawSprite(window->window, sprite.sprite, NULL);
    sfSprite_setOrigin(sprite.sprite, vector0);
}

void draw_npc(window_t *window,
sprite_t sprite, npc_t *npc, int world)
{
    sfVector2f temppos = {npc->pos.x * window->scale.x,
    npc->pos.y * window->scale.y};
    sfVector2f vector0 = {0, 0};
    sfVector2f origin = {16, 32};

    if (npc->world != world)
        return;
    sfSprite_setOrigin(sprite.sprite, origin);
    sfSprite_setScale(sprite.sprite, window->scale);
    sfSprite_setTextureRect(sprite.sprite,
    npc->anim.rects[npc->anim.actual_rect]);
    sfSprite_setPosition(sprite.sprite, temppos);
    sfRenderWindow_drawSprite(window->window, sprite.sprite, NULL);
    sfSprite_setOrigin(sprite.sprite, vector0);
}

int check_if_draw(game_object_list_t *object, character_t *character, int level)
{
    sfVector2f pos;

    if (object->height != level)
        return (0);
    if (object->type == GROUND)
        pos = (((ground_t *)(object->object))->pos);
    if (object->type == NPC)
        pos = (((npc_t *)(object->object))->pos);
    if (object->type == PLAYER)
        return (1);
    if (pos.x > character->pos.x + 400 || pos.x < character->pos.x - 400 ||
    pos.y > character->pos.y + 300 || pos.y < character->pos.y - 300)
        return (0);
    return (1);
}

void draw_objects(window_t *window, game_t *game, int level)
{
    game_object_list_t *save = game->objects;

    while (game->objects != NULL) {
        while (game->objects->next != NULL && check_if_draw(game->objects,
        game->character, level) == 0)
            game->objects = game->objects->next;
        if (game->objects->height != level)
            break;
        if (game->objects->type == GROUND)
            draw_ground(window, game->sprites[0],
            (ground_t *)(game->objects->object));
        if (game->objects->type == PLAYER)
            draw_character(window, game->sprites[1],
            (character_t *)(game->objects->object));
        if (game->objects->type == NPC)
            draw_npc(window, game->sprites[2],
            (npc_t *)(game->objects->object), game->character->world);
        game->objects = game->objects->next;
    }
    game->objects = save;
}

void draw_game(window_t *window, game_t *game)
{
    sfRenderWindow_clear(window->window, sfBlack);
    for (int i = 0; i <= 5; i++)
        draw_objects(window, game, i);
    sfRenderWindow_display(window->window);
}
