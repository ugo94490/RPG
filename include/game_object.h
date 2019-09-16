/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game objects header
*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

enum {GROUND = 0, PLAYER};
static const int ground_width = 32;
static const int ground_height = 32;
static const int character_width = 40;
static const int character_height = 52;
static const sfIntRect standardColRect = {0, 0, 32, 32};

typedef struct anim_s
{
    int nb_rects;
    int baserect;
    int actual_rect;
    int endrect;
    float time_anim;
    clock_sf clock;
    sfIntRect const *rects;
} anim_t;

typedef struct character_s
{
    int status;
    int direction;
    sfVector2f objective;
    anim_t anim;
    sfVector2f pos;
} character_t;

typedef struct ground_s
{
    int type;
    anim_t anim;
    int solid;
    sfVector2f pos;
} ground_t;

typedef struct game_object_list_s
{
    int type;
    int height;
    void *object;
    struct game_object_list_s *next;
} game_object_list_t;



void put_object_in_objects(game_object_list_t **list, void *object,
int type, int height);
void move_objects(game_object_list_t *objects, sfTime time);
void create_character(game_object_list_t **list);
void update_character_status(character_t *character, int status, int direction);
character_t *get_character_in_objects(game_object_list_t *objects);
int check_can_go(character_t *character,
game_object_list_t *list, sfVector2f objective);
void load_overworld(game_object_list_t **list);
void animate_objects(game_object_list_t *list);

#endif
