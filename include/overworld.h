/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** overworld header
*/

#ifndef OVERWORLD_H
#define OVERWORLD_H

typedef struct evt_s
{
    int type;
    sfVector2f pos;
    sfIntRect colrect;
    int locmap;
    int trigger;
    sfVector2f dest;
    int destmap;
    int direction;
    int proba;
    int item;
    int quantity;
} evt_t;

typedef struct evt_list_s
{
    int perm;
    evt_t event;
    struct evt_list_s *next;
} evt_list_t;

typedef struct game_s
{
    struct game_object_list_s *objects;
    struct evt_list_s *evts;
    struct character_s *character;
    sfView *view;
    int status;
    sprite_t *sprites;
} game_t;

void set_view_params(window_t *window, game_t *game, sfVector2f scale);
void draw_game(window_t *window, game_t *game);
void analyse_event(window_t *window, game_t *game);
void read_evts(char *path, evt_list_t **list);
int check_col_event(sfVector2f pos, int locmap, evt_t event);
game_t create_game(void);
void unload_map(struct game_object_list_s **objects);
void animate_objects(game_t *game);
void load_npcs(struct game_object_list_s **list);
void destroy_game(game_t *game);

#endif
