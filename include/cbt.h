/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** header for cbt
*/

#ifndef CBT_H
#define CBT_H

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

int pause_time(float sec);

game_object *init_hud(char *path, int x, int y, window_t *window);
game_object *init_choice(char *path, window_t *window);
game_object *init_little(char *path, int x, int y, window_t *window);
game_object *display_all(misc_t *misc, window_t *window, sfIntRect rect,
pkmn_list_t *linked);

void destroy_anim(misc_t *misc, sfClock *clock, window_t *window,
game_object *sprite);
void add_bag(sfVector2f *prev, sfVector2f *position,
int flag, window_t *window);
void add_attack(sfVector2f *prev, sfVector2f *position,
int flag, window_t *window);

int display_cursor(window_t *win, misc_t *misc);
int bag(game_object *sp, sfClock *clk, window_t *window);
int attack(game_object *sp, sfClock *clk, window_t *window);
int next_mode(window_t *win, int flag, int ret, sfVector2i vct);
int mode(window_t *win, int flag);
int destroy_font(text_t *stat, int lim);
int cancel(window_t *window);
int display_game(game_object **tab, window_t *window, int pos, int start);
int attack_box(pkmn_list_t *linked, window_t *window,
int nb, game_object **tab);
int get_atk(pkmn_list_t *linked, int nb);
int display_stat(window_t *window, text_t *stat, int lim);

sfIntRect display_end(misc_t *misc, window_t *window, game_object *sprite,
sfIntRect rect);

int attack_anim(misc_t *misc, window_t *window, pkmn_list_t *linked);

misc_t init_atk(game_object **tab, text_t *stat);

int attack_one(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);
int attack_two(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);
int attack_three(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);
int attack_four(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);

int detect_one(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);
int detect_two(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);

int launch(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);

char *itoa_dup(int nb);

game_object **init_box(pkmn_list_t *linked, window_t *window);

int destroy_tab(game_object **tab);
int display_box(game_object **box, window_t *window);
int misc_atk(misc_t *misc, game_object **box, window_t *window,
game_object *atk);
text_t *init_name(pkmn_list_t *linked, window_t *window);
int destroy_atkhud(text_t *name_pow, game_object **box, game_object *atk,
int flag);
int disp_txt(window_t *window, text_t *stat, text_t *name_pow);
int atk_hud(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc);
game_object **init_object(window_t *window, pkmn_list_t *pkm, pkmn_list_t *npc);
int check_flag(misc_t *misc, window_t *win,
pkmn_list_t *linked, pkmn_list_t *npc);

text_t *init_txt(window_t *window);

text_t *change_pos(pkmn_list_t *node, window_t *window, pkmn_list_t *npc);

game_object **init_player(window_t *window, int flag);

int disp_sprite(game_object **tab, window_t *window,
game_object **character, npc_t *npc);

int free_character(game_object **character);

int animation(window_t *window, game_object **tab, int flag, npc_t *npc);

int riposte(npc_t *npc, window_t *window, game_t *game);

int disp_atk_mod(window_t *window, npc_t *npc, misc_t *misc, game_t *game);

int disp_txt_atk(window_t *window, text_t *stat, misc_t *misc);

int check_menu(window_t *window, int menu, game_object **tab);

int destroy_all(misc_t *misc);

misc_t *init_misc(window_t *window, game_t *game, npc_t *npc);

int death(window_t *window, misc_t *misc, npc_t *npc, game_t *game);

int ck_hp(game_t *game, npc_t *npc);

int display_combat(window_t *win, game_t *game, npc_t *npc, misc_t *misc);

int reload(game_t *game, misc_t *misc, npc_t *npc);

pkmn_list_t *nx_p(game_t *game, misc_t *misc, window_t *window);

pkmn_list_t *npc_p(npc_t *npc, misc_t *misc, window_t *window);

int combat(window_t *win, game_t *gm, npc_t *npc);

int my_linklen(pkmn_list_t *linked);

void free_linked(pkmn_list_t **linked, pkmn_list_t *tmp);

int choose_level(game_t *game);

npc_t *init_rand(game_t *game);

int free_savage(npc_t *npc);

void set_music(sfMusic *music);


#endif
