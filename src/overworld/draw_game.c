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

void draw_ground(window_t *window, sfVector2f scale,
sprite_t sprite, ground_t *ground)
{
    sfSprite_setTextureRect(sprite.sprite,
    ground->anim.rects[ground->anim.actual_rect]);
    sfSprite_setPosition(sprite.sprite, ground->pos);
    sfRenderWindow_drawSprite(window->window, sprite.sprite, NULL);
}

void draw_character(window_t *window, sfVector2f scale,
sprite_t sprite, character_t *character)
{
    sfVector2f vector0 = {0, 0};
    sfVector2f origin = {character_width-ground_width,
    character_height-ground_height};

    sfSprite_setOrigin(sprite.sprite, origin);
    sfSprite_setTextureRect(sprite.sprite,
    character->anim.rects[character->anim.actual_rect]);
    sfSprite_setPosition(sprite.sprite, character->pos);
    sfRenderWindow_drawSprite(window->window, sprite.sprite, NULL);
    sfSprite_setOrigin(sprite.sprite, vector0);
}

void draw_objects(window_t *window, sfVector2f scale, game_t *game, int level)
{
    game_object_list_t *save = game->objects;

    while (game->objects != NULL) {
        if (game->objects->height == level && game->objects->type == GROUND)
            draw_ground(window, scale, game->sprites[0],
            (ground_t *)(game->objects->object));
        if (game->objects->height == level &&game->objects->type == PLAYER)
            draw_character(window, scale, game->sprites[1],
            (character_t *)(game->objects->object));
        game->objects = game->objects->next;
    }
    game->objects = save;
}

void draw_game(window_t *window, sfVector2f scale, game_t *game)
{
    sfRenderWindow_clear(window->window, sfBlack);
    for (int i = 0; i <= 5; i++)
        draw_objects(window, scale, game, i);
    sfRenderWindow_display(window->window);
}
