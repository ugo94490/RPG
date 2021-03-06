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

static void sub_display_slot(pkmn_bag_t *pkmn_bag, int i, sfVector2f temppos)
{
    sfSprite_setTextureRect(pkmn_bag->slot[i].img.sprite,
    pkmn_bag->slot[i].rect);
    sfSprite_setPosition(pkmn_bag->slot[i].img.sprite,
    pkmn_bag->slot[i].pos);
    sfSprite_setScale(pkmn_bag->slot[i].img.sprite, pkmn_bag->window->scale);
    sfRenderWindow_drawSprite(pkmn_bag->window->window,
    pkmn_bag->slot[i].img.sprite, NULL);
    pkmn_bag->slot[i].pv.pos.x = temppos.x + (POS_X_SLOT[i] - 243 + 125)
    * pkmn_bag->window->scale.x;
    pkmn_bag->slot[i].pv.pos.y = temppos.y + (POS_Y_SLOT[i] - 225 + 75)
    * pkmn_bag->window->scale.y;
    sfText_setPosition(pkmn_bag->slot[i].pv.text,
    pkmn_bag->slot[i].pv.pos);
    pkmn_bag->slot[i].m_pv.pos.x = temppos.x + (POS_X_SLOT[i] - 243 + 200)
    * pkmn_bag->window->scale.x;
    pkmn_bag->slot[i].m_pv.pos.y = temppos.y + (POS_Y_SLOT[i] - 225 + 75)
    * pkmn_bag->window->scale.y;
    sfText_setPosition(pkmn_bag->slot[i].m_pv.text,
    pkmn_bag->slot[i].m_pv.pos);
}

static void display_slot(pkmn_bag_t *pkmn_bag, game_t *game, sfVector2f temppos)
{
    for (int i = 0; i < pkmn_bag->n_pkmn; i += 1) {
        if (pkmn_bag->n_slot == pkmn_bag->slot[i].nbr)
            pkmn_bag->slot[i].rect.left = 0;
        else
            pkmn_bag->slot[i].rect.left = 258;
        pkmn_bag->slot[i].pos.x = temppos.x + (POS_X_SLOT[i] - 250)
        * game->window->scale.x;
        pkmn_bag->slot[i].pos.y = temppos.y + (POS_Y_SLOT[i] - 225)
        * pkmn_bag->window->scale.y;
        sub_display_slot(pkmn_bag, i, temppos);
        sfText_setCharacterSize(pkmn_bag->slot[i].pv.text, 15
        * pkmn_bag->window->scale.x);
        sfText_setCharacterSize(pkmn_bag->slot[i].m_pv.text, 15
        * pkmn_bag->window->scale.x);
        sfRenderWindow_drawText(pkmn_bag->window->window,
        pkmn_bag->slot[i].pv.text, NULL);
        sfRenderWindow_drawText(pkmn_bag->window->window,
        pkmn_bag->slot[i].m_pv.text, NULL);
    }
}

void display_pokemon_bag(pkmn_bag_t *pkmn_bag, game_t *game)
{
    sfVector2f temppos = {(game->character->pos.x + character_width / 2)
        * game->window->scale.x, (game->character->pos.y +
        character_height / 6) * game->window->scale.y};

    sfSprite_setTextureRect(pkmn_bag->img.sprite, pkmn_bag->rect);
    sfSprite_setScale(pkmn_bag->img.sprite, pkmn_bag->window->scale);
    pkmn_bag->pos.x = temppos.x - (250 * pkmn_bag->window->scale.x);
    pkmn_bag->pos.y = temppos.y - (225 * pkmn_bag->window->scale.y);
    sfSprite_setPosition(pkmn_bag->img.sprite, pkmn_bag->pos);
    sfRenderWindow_drawSprite(pkmn_bag->window->window,
    pkmn_bag->img.sprite, NULL);
    display_slot(pkmn_bag, game, temppos);
}
