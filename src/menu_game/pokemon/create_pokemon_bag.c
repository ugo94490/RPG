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

static int my_linklen(pkmn_list_t *linked)
{
    int i = 0;

    for (i = 0; linked != NULL; i++)
        linked = linked->next;
    return (i);
}

static void set_slot_position(pkmn_bag_t *pkmn_bag, int i, sfVector2f *pos_txt)
{
    pkmn_bag->slot[i].img = pkmn_bag->img;
    pkmn_bag->slot[i].rect.top = SLOT_TOP[i];
    pkmn_bag->slot[i].rect.left = 258;
    pkmn_bag->slot[i].rect.width = 258;
    pkmn_bag->slot[i].rect.height = 110;
    pkmn_bag->slot[i].pos.x = POS_X_SLOT[i];
    pkmn_bag->slot[i].pos.y = POS_Y_SLOT[i];
    pos_txt->x = POS_X_SLOT[i] + 135;
    pos_txt->y = POS_Y_SLOT[i] + 75;
    pkmn_bag->slot[i].nbr = i + 1;
}

static void create_slot(pkmn_bag_t *pkmn_bag, game_t *game)
{
    sfVector2f pos_txt;
    char *tmp = NULL;

    pkmn_bag->n_slot = 1;
    for (int i = 0; i < pkmn_bag->n_pkmn; i += 1) {
        set_slot_position(pkmn_bag, i, &pos_txt);
        tmp = my_score(game->character->pkmns->pokemon.health);
        pkmn_bag->slot[i].pv = create_text(tmp, "assets/Pokemon Solid.ttf",
        15, pos_txt);
        sfText_setColor(pkmn_bag->slot[i].pv.text, sfBlack);
        free(tmp);
        tmp = my_score(game->character->pkmns->pokemon.max_health);
        pos_txt.x = POS_X_SLOT[i] + 200;
        pos_txt.y = POS_Y_SLOT[i] + 75;
        pkmn_bag->slot[i].m_pv = create_text(tmp, "assets/Pokemon Solid.ttf",
        15, pos_txt);
        sfText_setColor(pkmn_bag->slot[i].m_pv.text, sfBlack);
        game->character->pkmns = game->character->pkmns->next;
        free(tmp);
    }
}

static void set_up_basic(pkmn_bag_t *pkmn_bag)
{
    pkmn_bag->rect.left = 0;
    pkmn_bag->rect.top = 0;
    pkmn_bag->rect.width = 518;
    pkmn_bag->rect.height = 428;
    pkmn_bag->pos.x = 0;
    pkmn_bag->pos.y = 0;
    pkmn_bag->n_slot = 0;
}

pkmn_bag_t *create_pkmn_bag(window_t *window, game_t *game, int item)
{
    pkmn_bag_t *pkmn_bag = malloc(sizeof(*pkmn_bag));
    pkmn_list_t *tmp = NULL;

    tmp = game->character->pkmns;
    pkmn_bag->window = window;
    pkmn_bag->img = create_sprite("assets/PokemonMenu.png");
    set_up_basic(pkmn_bag);
    pkmn_bag->slot = malloc(sizeof(*(pkmn_bag->slot)) * NBR_PKMN);
    pkmn_bag->state = OPEN;
    pkmn_bag->n_pkmn = my_linklen(game->character->pkmns);
    game->character->pkmns = tmp;
    create_slot(pkmn_bag, game);
    game->character->pkmns = tmp;
    pkmn_bag->item = item;
    return (pkmn_bag);
}
