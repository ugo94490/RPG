/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** put_special_grounds.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "basics.h"
#include "game_object.h"
#include "overworld_rects.h"

ground_t *create_mov_herb(int *height, int posx, int posy)
{
    ground_t *ground = malloc(sizeof(ground_t));

    if (ground == NULL)
        return (NULL);
    ground->type = 6;
    ground->anim.nb_rects = 4;
    ground->anim.actual_rect = 0;
    ground->anim.baserect = 0;
    ground->anim.endrect = 0;
    ground->anim.clock = create_clock();
    ground->anim.time_anim = 140000;
    ground->anim.rects = speHerbRects;
    ground->solid = 0;
    ground->pos.x = (float)(32*posx);
    ground->pos.y = (float)(32*posy);
    ground->animfct = &anim_speherb;
    *height = 3;
    return (ground);
}

ground_t *create_door(int *height, int posx, int posy)
{
    ground_t *ground = malloc(sizeof(ground_t));

    if (ground == NULL)
        return (NULL);
    ground->type = 6;
    ground->anim.nb_rects = 4;
    ground->anim.actual_rect = 0;
    ground->anim.baserect = 0;
    ground->anim.endrect = 0;
    ground->anim.clock = create_clock();
    ground->anim.time_anim = 100000;
    ground->solid = 0;
    ground->anim.rects = doorRects;
    ground->pos.x = (float)(32*posx);
    ground->pos.y = (float)(32*posy);
    ground->animfct = &anim_door;
    *height = 3;
    return (ground);
}

ground_t *create_flower(int *height, int posx, int posy)
{
    ground_t *ground = malloc(sizeof(ground_t));

    if (ground == NULL)
        return (NULL);
    ground->type = 6;
    ground->anim.nb_rects = 2;
    ground->anim.actual_rect = 0;
    ground->anim.baserect = 0;
    ground->anim.endrect = 1;
    ground->anim.clock = create_clock();
    ground->anim.time_anim = 400000;
    ground->solid = 0;
    ground->anim.rects = flowerRects;
    ground->pos.x = (float)(32*posx);
    ground->pos.y = (float)(32*posy);
    ground->animfct = &anim_flower;
    *height = 3;
    return (ground);
}

void spe_create_ground_from_char(game_object_list_t **list,
char c, int posx, int posy)
{
    ground_t *(*create_spe_ground[])(int *, int, int) =
        {create_flower, create_mov_herb, create_door};
    int height = 0;
    ground_t *ground = NULL;
    int nb = 0;

    if (c < 'a' || c > 'c')
        return;
    nb = c-'a';
    ground = (create_spe_ground[nb])(&height, posx, posy);
    if (ground != NULL) {
        put_object_in_objects(list, (void *)(ground), GROUND, height);
    }
}

void put_map_in_grounds_spe(game_object_list_t **list, char **map)
{
    for (int y = 0; map[y]; y++)
        for (int x = 0; map[y][x]; x++)
            spe_create_ground_from_char(list, map[y][x], x, y);
}
