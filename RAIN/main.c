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

void change(sfVertexArray *my_rain, sfVertex vertex)
{
    sfVertex *ver;

    for (size_t i = 0; i < sfVertexArray_getVertexCount(my_rain); i++) {
        ver = sfVertexArray_getVertex(my_rain, i);
        if (i % 4 == 0)
            ver->position.y += 16;
        else
            ver->position.y += 8;
        if (ver->position.y >= 960)
            ver->position.y = 0;
    }
}

void move_snow(sfVertexArray *my_rain, sfVertex vertex)
{
    sfVertex *ver;

    for (size_t i = 0; i < sfVertexArray_getVertexCount(my_rain); i++) {
        ver = sfVertexArray_getVertex(my_rain, i);
        ver->position.y += 8;
        if (ver->position.y >= 960)
            ver->position.y = 0;
    }
}

int rain_misc(sfRenderWindow *window, sfVertexArray *my_rain)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawVertexArray(window, my_rain, NULL);
    event(window);
    sfRenderWindow_display(window);
}

int rain(sfRenderWindow *window)
{
    sfVertexArray *my_rain = sfVertexArray_create();
    sfVector2f position = {0, 0};
    sfVertex vertex = {position, sfBlue, position};
    sfClock *clock = sfClock_create();
    sfTime tim;

    for (int i = 0; i < 400; i++)
        goutte(my_rain, vertex, rand() % 1280, rand() % 960);
    while (sfRenderWindow_isOpen(window)) {
        tim = sfClock_getElapsedTime(clock);
        if (tim.microseconds >= 10000) {
            change(my_rain, vertex);
            tim = sfClock_restart(clock);
        }
        rain_misc(window, my_rain);
    }
    sfVertexArray_destroy(my_rain);
    return (0);
}

int snow(sfRenderWindow *window)
{
    sfVertexArray *my_rain = sfVertexArray_create();
    sfVector2f position = {0, 0};
    sfVertex vertex = {position, sfWhite, position};
    sfClock *clock = sfClock_create();
    sfTime tim;

    for (int i = 0; i < 400; i++)
        flocon(my_rain, vertex, rand() % 1280, rand() % 960);
    while (sfRenderWindow_isOpen(window)) {
        tim = sfClock_getElapsedTime(clock);
        if (tim.microseconds >= 10000) {
            move_snow(my_rain, vertex);
            tim = sfClock_restart(clock);
        }
        rain_misc(window, my_rain);
    }
    sfVertexArray_destroy(my_rain);
    return (0);
}

int main(void)
{
    window_t window = create_window(1280, 960, 32, "COMBAT RPG");

    srand(time(0));
    sfRenderWindow_setFramerateLimit(window.window, 60);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_clear(window.window, sfBlack);
        sfRenderWindow_display(window.window);
        if (sfKeyboard_isKeyPressed(sfKeyR))
            rain(window.window);
        if (sfKeyboard_isKeyPressed(sfKeyS))
            snow(window.window);
        event(window.window);
    }
    sfRenderWindow_destroy(window.window);
    return (0);
}
