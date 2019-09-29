/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt12.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"
#include "cbt.h"

game_object *init_hud(char *path, int x, int y, window_t *window)
{
    sfVector2f position = {x, y};
    sfIntRect rect = {0, 203, 256, 203};
    game_object *hud = create_object(path, position, rect, window);

    return (hud);
}

game_object *init_choice(char *path, window_t *window)
{
    sfIntRect rect = {0, 90, 216, 90};
    sfVector2f position = {340, 535};
    game_object *choice = create_object(path, position, rect, window);

    return (choice);
}

game_object *init_little(char *path, int x, int y, window_t *window)
{
    sfIntRect rect = {0, 44, 78, 44};
    sfVector2f position = {x, y};
    game_object *choice = create_object(path, position, rect, window);

    return (choice);
}

void add_attack(sfVector2f *prev, sfVector2f *position,
int flag, window_t *window)
{
    if (flag == 0) {
        position->x -= 0.47 * window->scale.x;
        position->y -= 0.25 * window->scale.y;
        prev->x += 0.002 * window->scale.x;
        prev->y += 0.002 * window->scale.y;
    }
    if (flag == 1) {
        position->x += 0.47 * window->scale.x;
        position->y += 0.25 * window->scale.y;
        prev->x -= 0.002 * window->scale.x;
        prev->y -= 0.002 * window->scale.y;
    }
}

void add_bag(sfVector2f *prev, sfVector2f *position, int flag, window_t *window)
{
    if (flag == 0) {
        position->x -= 0.35 * window->scale.x;
        position->y -= 0.25 * window->scale.y;
        prev->x += 0.003 * window->scale.x;
        prev->y += 0.003 * window->scale.y;
    }
    if (flag == 1) {
        position->x += 0.35 * window->scale.x;
        position->y += 0.25 * window->scale.y;
        prev->x -= 0.003 * window->scale.x;
        prev->y -= 0.003 * window->scale.y;
    }
}