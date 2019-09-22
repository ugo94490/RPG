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
#include "sounds.h"
#include "systems.h"

typedef struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
}game_object;

struct game_object *create_object(char *sprite, sfVector2f position, sfIntRect rect1);
void destroy_object(struct game_object *obj);
void display_pause(sfRenderWindow *window);
void close_window(sfEvent event, sfRenderWindow *window);
int event(sfRenderWindow *window);
int combat(sfRenderWindow *window, pkmn_list_t *linked);
int my_strlen92(char *str);
void my_revstr(char *str);
int my_int(int nb);
char* my_itoa(int nb, char *nbr);
int display_text(char *base, sfVector2f pos, sfRenderWindow *window);
int my_strlen(char const *str);
