/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** overworld header
*/

#ifndef OVERWORLD_H
#define OVERWORLD_H

static const sfVector2f boxpos = {338, 854};

struct npc_s;

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
    int music;
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
    struct sfMusic *music;
    sfView *view;
    int status;
    sprite_t *sprites;
    window_t *window;
} game_t;

void set_view_params(window_t *window, game_t *game, sfVector2f scale);
void draw_game(window_t *window, game_t *game);
void analyse_event(window_t *window, game_t *game);
void read_evts(char *path, evt_list_t **list, int arg);
int check_col_event(sfVector2f pos, int locmap, evt_t event);
game_t create_game(int arg, int gender);
void unload_map(struct game_object_list_s **objects);
void animate_objects(game_t *game);
void destroy_game(game_t *game);
int display_text(char *base, sfVector2f pos, window_t *window, int opt);
void main_cbt(window_t *window, game_t *game, struct npc_s *npc);
void save_game(game_t *game);
void interact(game_t *game);
void activate_event(game_t *game, evt_list_t *evt);
void display_text_overworld(window_t *window, char *text, game_t *game);
void activate_event(game_t *game, evt_list_t *evt);
void save_evts(evt_list_t *evts);
void analyse_line_evt(char *line, evt_t *evt);
void put_event_in_list(evt_list_t **list, evt_t event, int perm);
evt_t create_basic_event(void);
void sub_save_evts(void *file, evt_list_t *evts);
void temp_loop(window_t *window, sfVector2f *scale, int flag, int opt);

#endif
