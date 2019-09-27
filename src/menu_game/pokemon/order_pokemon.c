/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** order_pokemon.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

// static void change_place_pkmn(pkmn_bag_t *pkmn_bag, int chosen)
// {
//     pkmn_list_t *new_head = NULL;
//     pkmn_list_t *tmp = pkmn_bag->param->list_pkmn;

//     for (int i = 1; i < chosen; i += 1)
//         pkmn_bag->param->list_pkmn = pkmn_bag->param->list_pkmn->next;
//     new_head = pkmn_bag->param->list_pkmn;
//     pkmn_bag->param->list_pkmn = tmp;
//     for (int i = 1; i < pkmn_bag->n_slot; i += 1)
//         pkmn_bag->param->list_pkmn = pkmn_bag->param->list_pkmn->next;
// }

// void order_pokemon(pkmn_bag_t *pkmn_bag)
// {
//     static int hit = 0;
//     static int chosen = -1;

//     if (chosen == pkmn_bag->n_slot) {
//         chosen = -1;
//         hit = 0;
//         return ;
//     }
//     if (chosen != pkmn_bag->n_slot && hit == 0) {
//         chosen = pkmn_bag->n_slot;
//         hit = 1;
//         return ;
//     }
//     if (hit == 1 && chosen != pkmn_bag->n_slot) {
//         change_place_pkmn(pkmn_bag, chosen);
//         hit = 0;
//         chosen = -1;
//         pkmn_bag->state = CLOSE;
//     }
// }