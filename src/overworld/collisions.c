/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** collisions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

int box_box_col(sfVector2f box1pos, sfIntRect box1rect,
sfVector2f box2pos, sfIntRect box2rect)
{
    if ((box2pos.x >= (box1pos.x + box1rect.width))
    || ((box2pos.x + box2rect.width) <= box1pos.x)
    || (box2pos.y >= (box1pos.y + box1rect.height))
    || ((box2pos.y + box2rect.height) <= box1pos.y))
        return (0);
    else
        return (1);
}

int check_col_event(sfVector2f pos, int locmap, evt_t event)
{
    if (event.locmap != locmap)
        return (0);
    if (event.trigger == 1 && pos.x == event.pos.x &&
    pos.y == event.pos.y)
        return (1);
    if (event.trigger == 2 && box_box_col(pos,
    standardColRect, event.pos, event.colrect))
        return (1);
    return (0);
}
