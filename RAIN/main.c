/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
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

void change(sfVertexArray *my_rain, sfVector2f pos1, sfVector2f pos2)
{
    sfVertex *ver;

    for (size_t i = 0; i < sfVertexArray_getVertexCount(my_rain); i++) {
        ver = sfVertexArray_getVertex(my_rain, i);
        if (i % 4 == 0)
            ver->position.y += 16;
        else
            ver->position.y += 8;
        ver->position.x += 0.5;
        if (ver->position.y >= pos2.y)
            ver->position.y -= pos2.y - pos1.y;
        if (ver->position.x >= pos2.x)
            ver->position.x -= pos2.x - pos1.x;
    }
}

void move_snow(sfVertexArray *my_rain, sfVector2f pos1, sfVector2f pos2)
{
    sfVertex *ver;

    for (size_t i = 0; i < sfVertexArray_getVertexCount(my_rain); i++) {
        ver = sfVertexArray_getVertex(my_rain, i);
        ver->position.y += 5;
        ver->position.x += 1;
        if (ver->position.y >= pos2.y)
            ver->position.y -= pos2.y - pos1.y;
        if (ver->position.x >= pos2.x)
            ver->position.x -= pos2.x - pos1.x;
    }
}

int rain_misc(window_t window, sfVertexArray *my_rain, int ret,
sfVector2f pos1, sfVector2f pos2)
{
    sfRenderWindow_clear(window.window, sfYellow);
    sfRenderWindow_drawVertexArray(window.window, my_rain, NULL);
    if (ret == 2)
        move_snow(my_rain, pos1, pos2);
    else
        change(my_rain, pos1, pos2);
    event(&window);
    sfRenderWindow_display(window.window);
    return (0);
}

void init_rain(sfVertexArray *my_rain, sfVertex vertex, sfVector2f pos1,
sfVector2f pos2)
{
    for (int i = 0; i < 400; i++)
        goutte(my_rain, vertex, rand() % (int)(pos2.x - pos1.x) + pos1.x,
        (rand() % (int)(pos2.y - pos1.y)) + pos1.y);
}

void init_snow(sfVertexArray *my_rain, sfVertex vertex, sfVector2f pos1,
sfVector2f pos2)
{
    for (int i = 0; i < 400; i++)
        flocon(my_rain, vertex, (rand() % (int)(pos2.x - pos1.x)) + pos1.x,
        (rand() % (int)(pos2.y - pos1.y)) + pos1.y);
}

int main(void)
{
    window_t window = create_window(1280, 960, 32, "COMBAT RPG");
    sfVertexArray *my_rain = sfVertexArray_create();
    sfVector2f pos1 = {100, 100};
    sfVector2f pos2 = {1000, 800};
    sfVertex vertex = {pos1, sfWhite, pos1};
    sfClock *clock = sfClock_create();
    sfTime tim;
    int toggle = 0;

    srand(time(0));
    sfRenderWindow_setFramerateLimit(window.window, 60);
    while (sfRenderWindow_isOpen(window.window)) {
        if (toggle == 0) {
            sfVertexArray_clear(my_rain);
            vertex.color = sfWhite;
            init_snow(my_rain, vertex, pos1, pos2);
            toggle = 2;
        }
        if (toggle == 1) {
            sfVertexArray_clear(my_rain);
            vertex.color = sfBlue;
            init_rain(my_rain, vertex, pos1, pos2);
            toggle = 3;
        }
        if (sfKeyboard_isKeyPressed(sfKeyR))
            toggle = 0;
        if (sfKeyboard_isKeyPressed(sfKeyS))
            toggle = 1;
        tim = sfClock_getElapsedTime(clock);
        if (tim.microseconds >= 10000) {
            rain_misc(window, my_rain, toggle, pos1, pos2);
            tim = sfClock_restart(clock);
        }
    }
    sfVertexArray_destroy(my_rain);
    sfRenderWindow_destroy(window.window);
    return (0);
}
