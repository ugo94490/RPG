/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** animate_ground
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void anim_flower(game_t *game, ground_t *ground, int *height)
{
    (void)game;
    (void)height;
    sub_animate(&(ground->anim));
}

void anim_door(game_t *game, ground_t *ground, int *height)
{
    (void)height;
    ground->anim.endrect = 0;
    if (box_box_col(game->character->pos,
    standardColRect, ground->pos, standardColRect)) {
        ground->anim.endrect = 3;
    }
    if (!(ground->anim.endrect == 3 && ground->anim.actual_rect == 3))
        sub_animate(&(ground->anim));
}

void anim_speherb(game_t *game, ground_t *ground, int *height)
{
    ground->anim.endrect = 0;
    if (box_box_col(game->character->pos,
    standardColRect, ground->pos, standardColRect)) {
        if (ground->pos.y >= game->character->pos.y)
            *height = 5;
        else
            *height = 3;
        ground->anim.endrect = 3;
    }
    else
        *height = 3;
    if (game->character->status == 1 || game->character->status == 2)
        sub_animate(&(ground->anim));
    else
        ground->anim.actual_rect = 0;
}

void noAnimGround(game_t *game, ground_t *ground, int *height)
{
    (void)game;
    (void)ground;
    (void)height;
    return;
}
