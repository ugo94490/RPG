/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt8.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

misc_t init_atk(game_object **tab, text_t *stat)
{
    misc_t misc;

    misc.tab = tab;
    misc.stat = stat;
    return (misc);
}

int attack_one(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[0].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[0].number, misc->tab);
    misc->nb = 0;
    attack_anim(misc, window, linked);
    return (1);
}

int attack_two(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[1].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[1].number, misc->tab);
    misc->nb = 1;
    attack_anim(misc, window, linked);
    return (1);
}

int attack_three(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[2].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[2].number, misc->tab);
    misc->nb = 2;
    attack_anim(misc, window, linked);
    return (1);
}

int attack_four(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[3].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[3].number, misc->tab);
    misc->nb = 3;
    attack_anim(misc, window, linked);
    return (1);
}