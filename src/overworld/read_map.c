/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** read_map
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

static void sub_setGroundRect(ground_t *ground, ground_info_t info, int rect)
{
    if (info.type == 1 && info.map == 1)
        ground->anim.rects = objRectsIn[rect];
    if (info.type == 2 && info.map == 1)
        ground->anim.rects = WallRectsIn[rect];
    if (info.type == 3 && info.map == 1)
        ground->anim.rects = heightsRectsIn[rect];
}

static void setGroundRect(ground_t *ground, ground_info_t info, int rect)
{
    if (info.type == 0 && info.map == 0)
        ground->anim.rects = groundRectsOut[rect];
    if (info.type == 1 && info.map == 0)
        ground->anim.rects = objRectsOut[rect];
    if (info.type == 2 && info.map == 0)
        ground->anim.rects = buildRectsOut[rect];
    if (info.type == 3 && info.map == 0)
        ground->anim.rects = heightsRectsOut[rect];
    if (info.type == 4 && info.map == 0)
        ground->anim.rects = solidRectsOut[rect];
    if (info.type == 0 && info.map == 1)
        ground->anim.rects = groundRectsIn[rect];
    if (info.type == 5)
        ground->anim.rects = nocolobjsRects[rect];
    sub_setGroundRect(ground, info, rect);
}

static ground_t *create_ground(game_object_list_t **list,
int rect, ground_info_t info)
{
    ground_t *ground = malloc(sizeof(ground_t));

    if (ground == NULL)
        return (NULL);
    ground->animfct = &noAnimGround;
    ground->type = info.type;
    ground->anim.nb_rects = 1;
    ground->anim.actual_rect = 0;
    ground->anim.time_anim = 0;
    ground->anim.clock.clock = NULL;
    setGroundRect(ground, info, rect);
    ground->solid = info.solid;
    ground->pos = info.pos;
    return (ground);
}

static void create_ground_from_char(game_object_list_t **list,
char c, ground_info_t info)
{
    ground_t *ground = NULL;
    int nb = 0;

    if ((c > 'Z' || c < 'A') && (c > 'z' || c < 'a'))
        return;
    if (c >= 'a' && c <= 'z')
        nb = c-'a';
    if (c >= 'A' && c <= 'Z')
        nb = c-'A'+26;
    if (nb <= info.limit);
    ground = create_ground(list, nb, info);
    if (ground != NULL)
        put_object_in_objects(list, (void *)(ground), GROUND, info.height);
}

void put_map_in_grounds(game_object_list_t **list,
char **map, ground_info_t info)
{
    for (int y = get_nb_words(map) - 1; y >= 0; y--) {
        for (int x = 0; map[y][x]; x++) {
            info.pos.x = x * ground_width;
            info.pos.y = y * ground_height;
            create_ground_from_char(list, map[y][x], info);
        }
    }
}
