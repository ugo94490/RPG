/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt.c
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

pkmn_list_t *nx_p(game_t *game, misc_t *misc, window_t *window)
{
    sfVector2f pos = {420, 218};
    sfIntRect rect = {0, 0, 0, 0};

    sfSprite_destroy(misc->tab[7]->sprite);
    sfTexture_destroy(misc->tab[7]->texture);
    free(misc->tab[7]);
    misc->tab[7] =
    create_object(back_pkm[game->character->pkmns->next->pokemon.number],
    pos, rect, window);
    change_text(my_strdup(name[game->character->pkmns->next->pokemon.number]),
    &misc->stat[5]);
    change_text(itoa_dup(game->character->pkmns->next->pokemon.max_health),
    &misc->stat[0]);
    change_text(itoa_dup(game->character->pkmns->next->pokemon.health),
    &misc->stat[1]);
    change_text(itoa_dup(game->character->pkmns->next->pokemon.level),
    &misc->stat[2]);
    return (game->character->pkmns->next);
}

pkmn_list_t *npc_p(npc_t *npc, misc_t *misc, window_t *window)
{
    sfVector2f pos = {720, 85};
    sfIntRect rect = {0, 0, 0, 0};

    sfSprite_destroy(misc->tab[6]->sprite);
    sfTexture_destroy(misc->tab[6]->texture);
    free(misc->tab[6]);
    misc->tab[6] =
    create_object(front_pkm[npc->pkmns->next->pokemon.number],
    pos, rect, window);
    change_text(my_strdup(name[npc->pkmns->next->pokemon.number]),
    &misc->stat[4]);
    change_text(itoa_dup(npc->pkmns->next->pokemon.max_health),
    &misc->stat[7]);
    change_text(itoa_dup(npc->pkmns->next->pokemon.health),
    &misc->stat[6]);
    change_text(itoa_dup(npc->pkmns->next->pokemon.level),
    &misc->stat[3]);
    return (npc->pkmns->next);
}

int combat(window_t *win, game_t *gm, npc_t *npc)
{
    misc_t *misc = init_misc(win, gm, npc);

    misc->flag = 0;
    animation(win, misc->tab, gm->character->type, npc);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        misc->flag = check_menu(win, misc->flag, misc->tab);
        misc->flag = check_flag(misc, win, gm->character->pkmns, npc->pkmns);
        event(win);
        reload(gm, misc, npc);
        if (misc->flag == 84)
            break;
        if ((ck_hp(gm, npc) == 1 && npc->pkmns->next == NULL) ||
            (ck_hp(gm, npc) == 2 && gm->character->pkmns->next == NULL))
            return (death(win, misc, npc, gm));
        ck_hp(gm, npc) == 2 ? gm->character->pkmns = nx_p(gm, misc, win) : 0;
        ck_hp(gm, npc) == 1 ? npc->pkmns = npc_p(npc, misc, win) : 0;
        display_combat(win, gm, npc, misc);
    }
    return (destroy_all(misc));
}

int my_linklen(pkmn_list_t *linked)
{
    int i = 0;

    if (linked == NULL)
        return (0);
    for (i = 0; linked->next != NULL; i++)
        linked = linked->next;
    return (i);
}

void free_linked(pkmn_list_t **linked, pkmn_list_t *tmp)
{
    int i = 0;

    (*linked) = tmp;
    for (i = 0; (*linked)->next != NULL; i++) {
        (*linked) = (*linked)->next;
    }
    free((*linked));
    (*linked) = NULL;
}