/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_pokemon_bag.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

void fn_item(pkmn_bag_t * pkmn_bag);
void switch_pokemon(pkmn_bag_t *pkmn_bag);

static void analyse_keyboard_pkmn_bag_game(pkmn_bag_t *pkmn_bag)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        pkmn_bag->state = CLOSE;
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
        pkmn_bag->n_slot + 1 <= pkmn_bag->n_pkmn)
        pkmn_bag->n_slot += 1;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && pkmn_bag->n_slot - 1 >= 1)
        pkmn_bag->n_slot -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && pkmn_bag->n_slot + 2 <=
        pkmn_bag->n_pkmn)
        pkmn_bag->n_slot += 2;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && pkmn_bag->n_slot - 2 >= 1)
        pkmn_bag->n_slot -= 2;
}

static void analyse_pos_mouse_pkmn_bag_game(pkmn_bag_t *pkmn_bag)
{
    sfVector2i pMouse =
    sfMouse_getPositionRenderWindow(pkmn_bag->window->window);

    for (int i = 0; i < pkmn_bag->n_pkmn; i += 1)
        if ((float)pMouse.x >= pkmn_bag->slot[i].pos.x &&
        (float)pMouse.x <= pkmn_bag->slot[i].pos.x +
        pkmn_bag->slot[i].rect.width && (float)pMouse.y >=
        pkmn_bag->slot[i].pos.y && (float)pMouse.y
        <= pkmn_bag->slot[i].pos.y + pkmn_bag->slot[i].rect.height) {
            pkmn_bag->n_slot = pkmn_bag->slot[i].nbr;
            break;
        }
}

void analyse_pokemon_bag(pkmn_bag_t *pkmn_bag)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(pkmn_bag->window->window, &event)) {
        if (event.type == sfEvtKeyPressed)
            analyse_keyboard_pkmn_bag_game(pkmn_bag);
        if (event.type == sfEvtClosed)
            pkmn_bag->state = QUIT;
        analyse_pos_mouse_pkmn_bag_game(pkmn_bag);
    }
}