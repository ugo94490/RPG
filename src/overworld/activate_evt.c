/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** activate_evts
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"
#include "overworld_evt.h"
#include "my_rpg.h"
#include "overworld_sound.h"
#include "basics.h"
#include "items.h"

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

void add_item(item_list_t **list, int qty, item_t item)
{
    item_list_t *cpy = *list;

    while (cpy) {
        if (cpy->item.number == item.number) {
            cpy->quantity += qty;
            return;
        }
        cpy = cpy->next;
    }
    put_item_in_list(list, item, qty);
}

void get_item(game_t *game, evt_t event)
{
    char *str = malloc(sizeof(char));
    char *nbr = malloc(sizeof(char) * 12);
    char *cpy = nbr;

    if (nbr == NULL || str == NULL)
        return;
    add_item(&(game->character->items), event.quantity,
    itemsdef[event.item]);
    str[0] = '\0';
    nbr = my_itoa(event.quantity, nbr);
    str = my_strcat(str, "vous avez obtenu ");
    str = my_strcat(str, nbr);
    str = my_strcat(str, " ");
    str = my_strcat(str, itemnames[event.item]);
    my_strlen(str);
    display_text_overworld(game->window, str, game);
    free(cpy);
    free(str);
}

void activate_event(game_t *game, evt_list_t *evt)
{
    if (evt->event.type == 1)
        teleport(game, evt->event);
    if (evt->event.type == 2)
        heal_pkmns(game);
    if (evt->event.type == 3)
        get_item(game, evt->event);
    if (evt->perm == 0) {
        evt->event.type = 0;
        evt->perm = 1;
    }
    change_music(evt->event.music, &(game->music),
    &(game->character->music));
}
