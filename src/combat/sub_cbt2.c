/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt2.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

misc_t *init_misc(window_t *window, game_t *game, npc_t *npc)
{
    misc_t *misc = malloc(sizeof(misc_t));
    sfVector2f pos = {0, 0};

    misc->tab = init_object(window, game->character->pkmns, npc->pkmns);
    misc->clock = sfClock_create();
    misc->stat = change_pos(game->character->pkmns, window, npc->pkmns);
    misc->sprite = sfSprite_create();
    misc->texture = sfTexture_createFromFile("assets/cursor.png", NULL);
    sfSprite_setTexture(misc->sprite, misc->texture, sfTrue);
    sfSprite_setOrigin(misc->sprite, pos);
    return (misc);
}

int death(window_t *window, misc_t *misc, npc_t *npc, game_t *game)
{
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};
    char *str = malloc(sizeof(char));
    int ret = 0;

    *str = 0;
    display_stat(window, misc->stat, 8);
    if (game->character->pkmns->pokemon.health <= 0) {
        str = my_strcat(str, name[game->character->pkmns->pokemon.number]);
        ret = 0;
    }
    else if (npc->pkmns->pokemon.health <= 0) {
        str = my_strcat(str, name[npc->pkmns->pokemon.number]);
        ret = 1;
    }
    str = my_strcat(str, phr[2]);
    display_text(str, pos, window, 0);
    free(str);
    destroy_all(misc);
    return (ret);
}

int ck_hp(game_t *game, npc_t *npc)
{
    if (game->character->pkmns->pokemon.health <= 0)
        return (2);
    if (npc->pkmns->pokemon.health <= 0)
        return (1);
    return (0);
}

int display_combat(window_t *win, game_t *game, npc_t *npc, misc_t *misc)
{
    misc->flag == 12 ? disp_atk_mod(win, npc, misc, game) : 0;
    disp_txt_atk(win, misc->stat, misc);
    return (0);
}

int reload(game_t *game, misc_t *misc, npc_t *npc)
{
    change_text(itoa_dup(game->character->pkmns->pokemon.health),
    &misc->stat[1]);
    change_text(itoa_dup(npc->pkmns->pokemon.health),
    &misc->stat[6]);
    return (0);
}