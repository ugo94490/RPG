/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu.h
*/

#include "graphics.h"
#include "systems.h"
#include "basics.h"
#include "game_object.h"
#include "my_rpg.h"

static const int NBR_BUTTON = 7;

typedef struct button_s {
    sprite_t img;
    sfIntRect rect;
    sfVector2f pos_img;
    text_t text;
    sfVector2f pos_text;
    int n_button;
} button_t;

typedef struct select_s {
    sprite_t img;
    sfIntRect rect;
    sfVector2f pos_select;
} select_t;

typedef struct menu_s {
    sfVector2f scale;
    window_t *window;
    sprite_t menu_w;
    button_t *buttons;
    select_t select;
    sfIntRect select_rect;
    sfIntRect menu_rect;
    sfVector2f pos_select;
    sfVector2f pos_menu;
    int n_button;
    int state;
} menu_t;

menu_t *create_menu_game(window_t *);
void display_menu_game(menu_t *);
void menu_game(window_t *);
void destroy_menu_game(menu_t *);
void analyse_menu_game(menu_t *);