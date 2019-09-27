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

static char *my_score(int nb)
{
    int size_str = 1;
    int power = 1;
    int i = 0;
    char *str = NULL;

    while ((nb / power) >= 10) {
        power *= 10;
        size_str = size_str + 1;
    }
    str = malloc(sizeof(char) * (size_str + 1));
    while (power >= 10) {
        str[i] = (nb / power) + '0';
        nb = nb - (nb / power) * power;
        power = power / 10;
        i = i + 1;
    }
    str[i] = nb % 10 + '0';
    str[i + 1] = '\0';
    return (str);
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
        tmp = my_score(game->character->pkmns->pokemon.health);
        pos_txt.x = POS_X_SLOT[i] + 200;
        pos_txt.y = POS_Y_SLOT[i] + 75;
        pkmn_bag->slot[i].m_pv = create_text(tmp, "assets/Pokemon Solid.ttf",
        15, pos_txt);
        sfText_setColor(pkmn_bag->slot[i].m_pv.text, sfBlack);
        game->character->pkmns = game->character->pkmns->next;
        free(tmp);
    }
}

pkmn_bag_t *create_pkmn_bag(window_t *window, game_t *game, int item)
{
    pkmn_bag_t *pkmn_bag = malloc(sizeof(*pkmn_bag));
    pkmn_list_t *tmp = NULL;
    pkmn_list_t *tmp_l = malloc(sizeof(pkmn_list_t));

    tmp_l->pokemon.health = 10;
    tmp_l->pokemon.max_health = 100;
    tmp_l->next = malloc(sizeof(pkmn_list_t));
    tmp_l->next->pokemon.health = 75;
    tmp_l->next->pokemon.max_health = 100;
    tmp_l->next->next = malloc(sizeof(pkmn_list_t));
    tmp_l->next->next->pokemon.health = 95;
    tmp_l->next->next->pokemon.max_health = 100;
    tmp_l->next->next->next = malloc(sizeof(pkmn_list_t));
    tmp_l->next->next->next->pokemon.health = 5;
    tmp_l->next->next->next->pokemon.max_health = 100;
    tmp_l->next->next->next->next = NULL;
    game->character->pkmns = tmp_l;
    tmp = game->character->pkmns;
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
    pkmn_bag->n_pkmn = my_linklen(game->character->pkmns);
    game->character->pkmns = tmp;
    create_slot(pkmn_bag, game);
    game->character->pkmns = tmp;
    pkmn_bag->item = item;
    return (pkmn_bag);
}