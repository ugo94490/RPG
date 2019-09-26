/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game objects header
*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

enum {GROUND = 0, PLAYER, NPC};
static const int ground_width = 32;
static const int ground_height = 32;
static const int character_width = 40;
static const int character_height = 52;
static const sfIntRect standardColRect = {0, 0, 32, 32};
struct game_s;

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

typedef struct item_list_s
{
    int quantity;
    int item;
    struct item_list_s *next;
} item_list_t;

typedef struct character_s
{
    int type;
    int status;
    int world;
    int music;
    int direction;
    sfVector2f objective;
    anim_t anim;
    sfVector2f pos;
    struct pkmn_list_s *pkmns;
    struct item_list_s *items;
} character_t;

typedef struct npc_s
{
    int type;
    int aggro;
    int status;
    int world;
    int direction;
    sfVector2f objective;
    anim_t anim;
    sfVector2f pos;
    char *diag1;
    char *diag2;
    struct pkmn_list_s *pkmns;
    int interact;
} npc_t;

typedef struct ground_s
{
    int type;
    anim_t anim;
    int solid;
    sfVector2f pos;
    void (*animfct)(struct game_s *, struct ground_s *, int *);
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
void move_npc(npc_t *npc, sfTime time);
character_t *create_character(game_object_list_t **list);
void update_character_status(character_t *character, int status, int direction);
void update_npc_status(npc_t *npc, int status, int direction);
character_t *get_character_in_objects(game_object_list_t *objects);
int check_can_go(character_t *character,
game_object_list_t *list, sfVector2f objective);
int check_can_go_np(npc_t *npc, game_object_list_t *list, sfVector2f objective);
void load_map(game_object_list_t **list, int arg);
void noAnimGround(struct game_s *game, ground_t *ground, int *height);
void anim_flower(struct game_s *game, ground_t *ground, int *height);
void anim_door(struct game_s *game, ground_t *ground, int *height);
void anim_speherb(struct game_s *game, ground_t *ground, int *height);
void put_map_in_grounds_spe(game_object_list_t **list, char **map);
void sub_animate(anim_t *anim);
int box_box_col(sfVector2f box1pos, sfIntRect box1rect,
sfVector2f box2pos, sfIntRect box2rect);
void animate_player(character_t *character);
void animate_npc(npc_t *npc);
void destroy_npc(npc_t *npc);
void destroy_ground(ground_t *ground);
void destroy_character(character_t *character);
void destroy_object(game_object_list_t *object);
character_t *load_character(char *path, game_object_list_t **list);
void save_character(char *path, character_t *character);
void save_pkmns(void *file, struct pkmn_list_s *pkmns);
void load_npcs(char *path, struct game_object_list_s **list);
void save_npcs(char *path, game_object_list_t *list);

#endif
