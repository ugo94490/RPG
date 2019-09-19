/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_pokemon.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static void display_slot(pkmn_bag_t *pkmn_bag)
{
    for (int i = 0; i < pkmn_bag->n_pkmn; i += 1) {
        if (pkmn_bag->n_slot == pkmn_bag->slot[i].nbr)
            pkmn_bag->slot[i].rect.left = 0;
        else
            pkmn_bag->slot[i].rect.left = 258;
        sfSprite_setTextureRect(pkmn_bag->slot[i].img.sprite,
        pkmn_bag->slot[i].rect);
        sfSprite_setPosition(pkmn_bag->slot[i].img.sprite,
        pkmn_bag->slot[i].pos);
        sfRenderWindow_drawSprite(pkmn_bag->window->window,
        pkmn_bag->slot[i].img.sprite, NULL);
        sfRenderWindow_drawText(pkmn_bag->window->window,
        pkmn_bag->slot[i].pv.text, NULL);
        sfRenderWindow_drawText(pkmn_bag->window->window,
        pkmn_bag->slot[i].m_pv.text, NULL);
    }
}

void display_pokemon_bag(pkmn_bag_t *pkmn_bag)
{
    sfSprite_setTextureRect(pkmn_bag->img.sprite, pkmn_bag->rect);
    sfSprite_setPosition(pkmn_bag->img.sprite, pkmn_bag->pos);
    sfRenderWindow_drawSprite(pkmn_bag->window->window,
    pkmn_bag->img.sprite, NULL);
    display_slot(pkmn_bag);
}