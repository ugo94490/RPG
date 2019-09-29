/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fn_item.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

char *my_score(int nb);

static void heal(game_t *game, pkmn_bag_t *pkmn_bag, int stuff)
{
    pkmn_list_t *tmp = NULL;
    char *buff = NULL;

    tmp = game->character->pkmns;
    for (int i = 1; i < pkmn_bag->n_slot; i += 1)
        game->character->pkmns = game->character->pkmns->next;
    if (game->character->pkmns->pokemon.health ==
    game->character->pkmns->pokemon.max_health) {
        game->character->pkmns = tmp;
        return;
    }
    for (int i = 0; i < stuff &&
        game->character->pkmns->pokemon.health <
        game->character->pkmns->pokemon.max_health; i += 1)
        game->character->pkmns->pokemon.health += 1;
    buff = my_score(game->character->pkmns->pokemon.health);
    change_text(buff, &pkmn_bag->slot[pkmn_bag->n_slot - 1].pv);
    game->character->pkmns = tmp;
}

static void revive(game_t *game, pkmn_bag_t *pkmn_bag)
{
    pkmn_list_t *tmp = NULL;
    char *buff = NULL;

    tmp = game->character->pkmns;
    for (int i = 1; i < pkmn_bag->n_slot; i += 1)
        game->character->pkmns = game->character->pkmns->next;
    if (game->character->pkmns->pokemon.health ==
    game->character->pkmns->pokemon.max_health) {
        game->character->pkmns = tmp;
        return;
    }
    if (game->character->pkmns->pokemon.health == 0) {
        game->character->pkmns->pokemon.health = 50;
        buff = my_score(game->character->pkmns->pokemon.health);
        change_text(buff, &pkmn_bag->slot[pkmn_bag->n_slot - 1].pv);
    }
    game->character->pkmns = tmp;
}

void fn_item(game_t *game, pkmn_bag_t *pkmn_bag)
{
    if (pkmn_bag->item == POTION || pkmn_bag->item == S_POTION
        || pkmn_bag->item == H_POTION)
        heal(game, pkmn_bag, pkmn_bag->item);
    if (pkmn_bag->item == REVIVE)
        revive(game, pkmn_bag);
}