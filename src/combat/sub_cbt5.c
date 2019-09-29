/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt5.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"
#include "cbt.h"

int disp_txt(window_t *window, text_t *stat, text_t *name_pow)
{
    display_stat(window, stat, 8);
    display_stat(window, name_pow, 9 - 1);
    return (0);
}

int atk_hud(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    game_object *atk = init_hud("assets/pp_hud.png", 338, 480, window);
    game_object **box = init_box(linked, window);
    text_t *name_pow = init_name(linked, window);
    int ret = 0;
    static int mode = 0;
    while (sfRenderWindow_isOpen(window->window)) {
        mode = cancel(window);
        if (mode == 1) {
            mode = 0;
            break;
        }
        misc_atk(misc, box, window, atk);
        disp_txt(window, misc->stat, name_pow);
        if (launch(window, linked, misc, npc) == 1) {
            ret = 12;
            break;
        }
        sfRenderWindow_display(window->window);
    }
    return (destroy_atkhud(name_pow, box, atk, ret));
}

game_object **init_object(window_t *window, pkmn_list_t *pkm, pkmn_list_t *npc)
{
    game_object **tab = malloc(sizeof(game_object *) * 13);
    sfVector2f pos = {420, 218};
    sfVector2f pos2 = {720, 85};
    sfIntRect rect = {0, 0, 0, 0};

    tab[0] = init_hud("assets/attack_hud.png", 338, 480, window);
    tab[8] = init_choice("assets/game_menu.png", window);
    tab[1]= init_hud("assets/combat_screen.png", 338, 0, window);
    tab[3] = init_hud("assets/text_combat.png", 338, 374, window);
    tab[2] = init_hud("assets/cercle.png", 338, 204, window);
    tab[5] = init_hud("assets/opponent_life.png", 338, 123, window);
    tab[4] = init_hud("assets/my_life.png", 659, 263, window);
    tab[9] = init_little("assets/m_sel.png", 341, 825, window);
    tab[10] = init_little("assets/m_sel.png", 549, 844, window);
    tab[11] = init_little("assets/m_sel.png", 757, 825, window);
    tab[6] = create_object(front_pkm[npc->pokemon.number], pos2, rect, window);
    tab[7] = create_object(back_pkm[pkm->pokemon.number], pos, rect, window);
    tab[12] = NULL;
    return (tab);
}

int check_flag(misc_t *misc, window_t *win,
pkmn_list_t *linked, pkmn_list_t *npc)
{
    if (misc->flag == 1)
        attack(misc->tab[8], misc->clock, win);
    if (misc->flag == 2)
        bag(misc->tab[9], misc->clock, win);
    if (misc->flag == 3)
        bag(misc->tab[10], misc->clock, win);
    if (misc->flag == 4)
        bag(misc->tab[11], misc->clock, win);
    if (misc->flag == 5)
        return (84);
    if (misc->flag == 6) {
        return (atk_hud(win, linked, misc, npc));
    }
    return (misc->flag);
}

text_t *init_txt(window_t *window)
{
    text_t *stat = malloc(sizeof(text_t) * 8);
    int size = 15 * window->scale.x;
    sfVector2f tmp = {0, 0};

    for (int i = 0; i < 8; i++) {
        tmp.x = pos_txt[i].x * window->scale.x;
        tmp.y = pos_txt[i].y * window->scale.y;
        stat[i] = create_text("init", "assets/classic.ttf", size, tmp);
        sfText_setFillColor(stat[i].text, sfBlack);
    }
    return (stat);
}