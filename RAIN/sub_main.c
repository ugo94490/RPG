/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_main.c
*/

#include "my_rpg.h"
#include "graphics.h"

void goutte(sfVertexArray *my_rain, sfVertex vertex, int x, int y)
{
    vertex.position.x = x;
    vertex.position.y = y;
    for (int i = 0; i < 5; i++) {
        sfVertexArray_append(my_rain, vertex);
        vertex.position.y += 1;
    }
}

void flocon(sfVertexArray *my_rain, sfVertex vertex, int x, int y)
{
    vertex.position.x = x;
    vertex.position.y = y;
    for (int i = 0; i < 6; i++) {
        sfVertexArray_append(my_rain, vertex);
        if (i == 1 || i == 2)
            vertex.position.y += 1;
        if (i == 3) {
            vertex.position.y -= 1;
            vertex.position.x -= 1;
        }
        if (i == 4)
            vertex.position.x += 2;
    }
}

void change(sfVertexArray *my_rain, sfIntRect pos)
{
    sfVertex *ver;

    for (size_t i = 0; i < sfVertexArray_getVertexCount(my_rain); i++) {
        ver = sfVertexArray_getVertex(my_rain, i);
        if (i % 4 == 0)
            ver->position.y += 16;
        else
            ver->position.y += 8;
        ver->position.x += 0.5;
        if (ver->position.y >= pos.height)
            ver->position.y -= pos.height - pos.top;
        if (ver->position.x >= pos.width)
            ver->position.x -= pos.width - pos.left;
    }
}