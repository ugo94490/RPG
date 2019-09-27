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
#include "pkmn.h"
#include "my_rpg.h"
#include "overworld.h"

static const int topIcon[] = {0, 70, 128, 190, 240, 320, 380};
static const float posIconY[] = {509, 562, 600, 640, 672, 735, 784};
static const float posTextY[] = {522, 570, 615, 661, 707, 752, 797};

static const int SLOT_TOP[] = {600, 450, 450, 450, 450, 450};
static const float POS_X_SLOT[] = {5, 262, 5, 262, 5, 262};
static const float POS_Y_SLOT[] = {0, 18, 107, 125, 214, 232};

static const int NBR_PKMN = 6;
static const int NBR_ATKS = 4;
static const int NBR_BUTTON = 7;
static const int WINDOW_WIDTH = 1280;
static const int WINDOW_HEIGHT = 960;
static const int OPEN = 1;
static const int CLOSE = 0;

enum ITEM {
    NO = -1,
    POTION = 20,
    S_POTION = 50,
    H_POTION = 200,
    REVIVE = 30,
};

enum ACTION {
    ORDER,
    HEAL,
    SWITCH,
};

enum SUB_MENU {
    NONE = -1,
    POKEDEX,
    POKEMON,
    BAG,
    SAVE,
    SETTINGS,
    BADGES,
    QUIT
};

typedef struct param_pkmn_menu_s {
    pkmn_list_t *list_pkmn;
    int action;
    int item;
} param_pkmn_menu_t;

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

typedef struct pkmn_slot_s {
    sprite_t img;
    sfIntRect rect;
    sfVector2f pos;
    text_t pv;
    text_t m_pv;
    int nbr;
} pkmn_slot_t;

typedef struct pkmn_bag_s {
    window_t *window;
    sprite_t img;
    sfIntRect rect;
    sfVector2f pos;
    pkmn_slot_t *slot;
    int state;
    int n_pkmn;
    int n_slot;
} pkmn_bag_t;

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

/* Menu Pause */
void menu_game(game_t *, window_t *);
void display_menu_game(game_t *, menu_t *);
void analyse_menu_game(game_t *, menu_t *);
void destroy_menu_game(menu_t *);
menu_t *create_menu_game(window_t *);

/* Menu Pokemon */
void menu_pokemon(window_t *, game_t *);
void display_pokemon_bag(pkmn_bag_t *, game_t *);
void analyse_pokemon_bag(pkmn_bag_t *);
void destroy_pokemon_bag(pkmn_bag_t *);
pkmn_bag_t *create_pkmn_bag(window_t *, game_t *);