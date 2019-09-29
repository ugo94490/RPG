/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt3.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

int riposte(npc_t *npc, window_t *window, game_t *game)
{
    int nb = rand() % 3;
    char *str = NULL;
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};

    str = malloc(sizeof(char));
    str[0] = '\0';
    str = my_strcat(str, name[npc->pkmns->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[npc->pkmns->pokemon.atks[nb].number]);
    str = my_strcat(str, phr[1]);
    game->character->pkmns->pokemon.health -= ((npc->pkmns->pokemon.level *
    0.4 + 2) * npc->pkmns->pokemon.atks[3].power * npc->pkmns->pokemon.atq)
    / (npc->pkmns->pokemon.def * 50) + 2;
    if (game->character->pkmns->pokemon.health <= 0)
        game->character->pkmns->pokemon.health = 0;
    pause_time(0.3);
    display_text(str, pos, window, 0);
    free(str);
    return (0);
}

int disp_atk_mod(window_t *window, npc_t *npc, misc_t *misc, game_t *game)
{
    sfRenderWindow_clear(window->window, sfBlack);
    display_game(misc->tab, window, 7, 0);
    display_stat(window, misc->stat, 8);
    riposte(npc, window, game);
    return (0);
}

int disp_txt_atk(window_t *window, text_t *stat, misc_t *misc)
{
    display_stat(window, stat, 8);
    display_cursor(window, misc);
    sfRenderWindow_display(window->window);
    return (0);
}

int check_menu(window_t *window, int menu, game_object **tab)
{
    display_game(tab, window, 7, 0);
    menu = mode(window, menu);
    return (menu);
}

int destroy_all(misc_t *misc)
{
    destroy_tab(misc->tab);
    destroy_font(misc->stat, 8);
    sfClock_destroy(misc->clock);
    sfTexture_destroy(misc->texture);
    sfSprite_destroy(misc->sprite);
    free(misc);
    return (0);
}