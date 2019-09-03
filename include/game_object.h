/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game objects header
*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

typedef struct anim_s
{
    int nb_rects;
    int actual_rect;
    float time_anim;
    clock_sf clock;
    sfIntRect const *rects;
} anim_t;

typedef struct ground_s
{
    int type;
    anim_t animate;
    int solid;
    sfVector2f pos;
    sfIntRect rect;
} ground_t;

typedef struct game_object_list_s
{
    int type;
    void *object;
    game_object_list_t *next;
} game_object_list_t;

#endif
