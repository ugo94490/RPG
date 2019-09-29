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
#include "my_rpg.h"

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

int loop(txt_t *text, setting_t set, int cpt, int opt);
int do_text(char *base, setting_t set, window_t *window, int opt);
int check_cpt(txt_t *text, int cpt, sfRenderWindow *window, sfSprite *sprite);

txt_t set_text(txt_t *text, setting_t set, char *base);

void display(sfText *text, char *str, sfRenderWindow *window, sfSprite *sprite);

char *set_to_base(char *str, char *save);

#endif
