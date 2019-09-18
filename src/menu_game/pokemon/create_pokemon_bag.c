/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_pokemon_slot.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static const int SLOT_TOP[] = {600, 450, 450, 450, 450, 450};
static const float POS_X_SLOT[] = {5, 262, 5, 262, 5, 262};
static const float POS_Y_SLOT[] = {0, 18, 107, 125, 214, 232};

// int my_linklen(pkmn_list_t *linked)
// {
//     int i = 0;

//     for (i = 0; linked->next != NULL; i++)
//         linked = linked->next;
//     return (i);
// }

// pkmn_list_t *fill_atk(pkmn_list_t *node)
// {
//     for (int i = 0; i < NBR_ATKS; i++) {
//         node->pokemon.atks[i].number = i;
//         node->pokemon.atks[i].power = 100;;
//         node->pokemon.atks[i].type = 0;
//         node->pokemon.atks[i].spetype = 1;
//     }
//     return (node);
// }

// pkmn_list_t *fill(int flag)
// {
//     pkmn_list_t *node = malloc(sizeof(*node));

//     node->pokemon.number = flag;
//     node->pokemon.level = 7;
//     node->pokemon.health = 100;
//     node->pokemon.max_health = 100;
//     node->pokemon.xp_to_next_lvl = 3532;
//     node->pokemon.speed = 5;
//     node->pokemon.physatq = 100;
//     node->pokemon.physdef = 75;
//     node->pokemon.speatq = 10;
//     node->pokemon.spedef = 15;
//     node = fill_atk(node);
//     return (node);
// }

// void add_node(pkmn_list_t *node, int flag)
// {
//     pkmn_list_t *new;
//     int i = 0;

//     for (i = 0; node->next != NULL; i++)
//         node = node->next;
//     new = fill(flag);
//     node->next = new;
//     node = node->next;
//     node->next = NULL;
// }

// pkmn_list_t *init(void)
// {
//     pkmn_list_t *node;
//     int flag = 0;

//     node = fill(flag);
//     node->next = NULL;
//     for (int i = 0; i < NBR_PKMN; i++) {
//         add_node(node, flag);
//         flag++;
//     }
//     return (node);
// }

pkmn_bag_t *create_pkmn_bag(window_t *window)
{
    pkmn_bag_t *pkmn_bag = malloc(sizeof(*pkmn_bag));

    pkmn_bag->window = window;
    pkmn_bag->img = create_sprite("assets/PokemonMenu.png");
    pkmn_bag->rect.left = 0;
    pkmn_bag->rect.top = 0;
    pkmn_bag->rect.width = 518;
    pkmn_bag->rect.height = 428;
    pkmn_bag->pos.x = 0;
    pkmn_bag->pos.y = 0;
    pkmn_bag->slot = malloc(sizeof(*(pkmn_bag->slot)) * NBR_PKMN);
    pkmn_bag->state = OPEN;
    pkmn_bag->n_pkmn = 6;
    pkmn_bag->n_slot = 1;
    for (int i = 0; i < NBR_PKMN; i += 1) {
        pkmn_bag->slot[i].img = pkmn_bag->img;
        pkmn_bag->slot[i].rect.top = SLOT_TOP[i];
        pkmn_bag->slot[i].rect.left = 258;
        pkmn_bag->slot[i].rect.width = 258;
        pkmn_bag->slot[i].rect.height = 110;
        pkmn_bag->slot[i].pos.x = POS_X_SLOT[i];
        pkmn_bag->slot[i].pos.y = POS_Y_SLOT[i];
        pkmn_bag->slot[i].nbr = i + 1;
    }
    return (pkmn_bag);
}