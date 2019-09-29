/*
** EPITECH PROJECT, 2019
** main_menu.h
** File description:
** main_menu.h
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
#include "graphics.h"
#include "overworld.h"

typedef struct menu
{
    sfTexture *texture;
    sfSprite *sprite;
} menu_t;

typedef struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} game_object;

sfSprite *init_button(char *buffer);
int display_button(sfSprite *sprite, sfVector2f position, sfIntRect rect
, window_t *window);
int condition_play(window_t *window);
int condition_gear(window_t *window);
menu_t *init_menu(char *path);
int free_menu(menu_t *menu);
int menu_event(window_t *window);
sfIntRect set_rect(int top, int left, int width, int height);
int pause_time(float sec);
int condition_trophy(window_t *window);
int condition_exit(window_t *window);
int condition_howto(window_t *window);
int condition_save(window_t *window);
int condition_gender(window_t *window);
int menu_event(window_t *window);
int display_menu(window_t *window);
int condition_back(window_t *window);
int condition_scale(window_t *window);
int condition_left(window_t *window, float x, float y);
int condition_right(window_t *window, float x, float y);
int config_option(window_t *window);
int condition_frame(window_t *window);
int condition_volume(window_t *window);
void how_to_play(window_t *window);
