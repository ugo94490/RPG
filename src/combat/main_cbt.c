/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"
#include "cbt.h"

int choose_level(game_t *game)
{
    int nb = rand() % 6;
    int op = rand() % 2;

    if (op == 1)
        return (game->character->pkmns->pokemon.level + nb);
    else
        return (game->character->pkmns->pokemon.level - nb);
    return (0);
}

npc_t *init_rand(game_t *game)
{
    npc_t *npc = malloc(sizeof(*npc));

    if (npc == NULL)
        return (NULL);
    npc->type = -1;
    npc->pkmns = malloc(sizeof(pkmn_list_t));
    npc->pkmns->next = NULL;
    npc->pkmns->pokemon.number = rand() % 17;
    npc->pkmns->pokemon.level = choose_level(game);
    npc->pkmns->pokemon.xp_to_next_lvl = 0;
    npc->pkmns->pokemon.atq = 100 * (npc->pkmns->pokemon.level / 80) + 10;
    npc->pkmns->pokemon.def = 100 * (npc->pkmns->pokemon.level / 90) + 10;
    npc->pkmns->pokemon.max_health = ((0.90 + 2) * 60 + (20 / 4) + 100)
    * npc->pkmns->pokemon.level / 100 + 10;
    npc->pkmns->pokemon.health = npc->pkmns->pokemon.max_health;
    for (int i = 0; i < 4; i++) {
        npc->pkmns->pokemon.atks[i] = atks[rand() % NB_ATK];
    }
    return (npc);
}

int free_savage(npc_t *npc)
{
    free(npc->pkmns);
    free(npc);
    return (0);
}

void set_music(sfMusic *music)
{
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}

void main_cbt(window_t *window, game_t *game, npc_t *npc)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(window->window);
    sfMusic *music = sfMusic_createFromFile("assets/battle.ogg");
    int toggle = 0;

    if (npc == NULL) {
        npc = init_rand(game);
        toggle = 1;
    }
    sfMusic_stop(game->music);
    set_music(music);
    sfRenderWindow_setView(window->window, default_view);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    combat(window, game, npc);
    sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
    sfRenderWindow_setView(window->window, game->view);
    if (toggle == 1)
        free_savage(npc);
    sfMusic_stop(music);
    sfMusic_destroy(music);
    sfMusic_play(game->music);
}
