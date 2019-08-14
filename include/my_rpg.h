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

typedef struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
}game_object;

sfRenderWindow *create_window(int width, int height, char *Name, int full);
struct game_object *create_object(char *sprite, sfVector2f position, sfIntRect rect1);
void destroy_object(struct game_object *obj);
void display_pause(sfRenderWindow *window);
void close_window(sfEvent event, sfRenderWindow *window);
int event(sfRenderWindow *window);
