/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** header for text
*/

#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

typedef struct txt_s {
    int flag;
    char *str;
    char *tmp;
    sfText *text;
    sfFont *font;
    sfEvent event;
    float seconds;
    sfClock *clock;
} txt_t;

typedef struct setting_s {
    int size;
    sfVector2f pos;
    sfSprite *sprite;
    sfRenderWindow *window;
} setting_t;

#endif
