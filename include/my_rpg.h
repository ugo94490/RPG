/*
** EPITECH PROJECT, 2019
** my_rpg.h
** File description:
** my_rpg.h
*/

#pragma once

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <time.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"
#include "pkmn.h"
#include "graphics.h"
#include "sounds.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

typedef struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
}game_object;

typedef struct misc_s
{
    game_object **tab;
    sfClock *clock;
    text_t *stat;
    int flag;
    sfSprite *sprite;
    sfTexture *texture;
    int nb;
}misc_t;

struct game_object *create_object(char *sprite, sfVector2f position,
sfIntRect rect1, window_t *window);
void destroy_obj(struct game_object *obj);
void display_pause(window_t *window);
void close_window(sfEvent event, window_t *window);
int event(window_t *window);
int combat(window_t *window, game_t *game, npc_t *npc);
int my_strlen92(char *str);
void my_revstr(char *str);
int my_int(int nb);
char* my_itoa(int nb, char *nbr);
int display_text(char *base, sfVector2f pos, window_t *window, int opt);
int my_strlen(char const *str);
int launch_quest(window_t *window, game_t *game);
