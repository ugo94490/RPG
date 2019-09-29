/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_activate_event
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"
#include "overworld_evt.h"
#include "my_rpg.h"

void teleport(game_t *game, evt_t event)
{
    unload_map(&(game->objects));
    game->character->world = event.destmap;
    game->character->objective = event.dest;
    game->character->pos = event.dest;
    if (event.direction > 0)
        game->character->direction = event.direction;
    load_map(&(game->objects), event.destmap);
}

void aggro_evt(game_t *game, evt_t event)
{
    int random = rand() % 100;

    if (random < event.proba)
        main_cbt(game->window, game, NULL);
}

void heal_pkmns(game_t *game)
{
    pkmn_list_t *pkmns = game->character->pkmns;

    display_text_overworld(game->window,
    "Vos pokemons ont ete soignes.", game);
    while (pkmns) {
	pkmns->pokemon.health = pkmns->pokemon.max_health;
        pkmns = pkmns->next;
    }
}
