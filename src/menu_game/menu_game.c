/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_game.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

pkmn_list_t *fill_atk(pkmn_list_t *node)
{
    for (int i = 0; i < NBR_ATKS; i++) {
        node->pokemon.atks[i].number = i;
        node->pokemon.atks[i].power = 100;;
        node->pokemon.atks[i].type = 0;
        node->pokemon.atks[i].spetype = 1;
    }
    return (node);
}

pkmn_list_t *fill(int flag)
{
    pkmn_list_t *node = malloc(sizeof(*node));

    node->pokemon.number = flag;
    node->pokemon.level = 7;
    node->pokemon.health = 100;
    node->pokemon.max_health = 100;
    node->pokemon.xp_to_next_lvl = 3532;
    node->pokemon.speed = 5;
    node->pokemon.physatq = 100;
    node->pokemon.physdef = 75;
    node->pokemon.speatq = 10;
    node->pokemon.spedef = 15;
    node = fill_atk(node);
    return (node);
}

void add_node(pkmn_list_t *node, int flag)
{
    pkmn_list_t *new;
    int i = 0;

    for (i = 0; node->next != NULL; i++)
        node = node->next;
    new = fill(flag);
    node->next = new;
    node = node->next;
    node->next = NULL;
}

pkmn_list_t *init(void)
{
    pkmn_list_t *node;
    int flag = 0;

    node = fill(flag);
    node->next = NULL;
    for (int i = 0; i < 3; i++) {
        add_node(node, flag);
        flag++;
    }
    return (node);
}

static void menu_game_loop(menu_t *menu)
{
    clock_sf time_loop = create_clock();
    param_pkmn_menu_t param;

    param.item = H_POTION;
    param.action = HEAL;
    param.list_pkmn = init();
    while (sfRenderWindow_isOpen(menu->window->window)) {
        analyse_menu_game(menu);
        sfClock_restart(time_loop.clock);
        sfRenderWindow_clear(menu->window->window, sfBlack);
        if (menu->state == NONE)
            display_menu_game(menu);
        if (menu->state == POKEMON) {
            menu_pokemon(menu->window, &param);
            menu->state = NONE;
        }
        sfRenderWindow_display(menu->window->window);
    }
    sfClock_destroy(time_loop.clock);
}

void menu_game(window_t *window)
{
    menu_t *menu = create_menu_game(window);

    if (!menu)
        return ;
    menu_game_loop(menu);
    destroy_menu_game(menu);
}