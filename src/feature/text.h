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

typedef struct text_s {
    int flag;
    char *str;
    char *tmp;
    sfText *text;
    sfFont *font;
    sfEvent event;
    float seconds;
    sfClock *clock;
} text_t;

#endif
