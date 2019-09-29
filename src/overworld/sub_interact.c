/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_interact
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

void destroy_quest(quest_list_t **quests, int nb)
{
    quest_list_t *save = *quests;
    quest_list_t *save2 = NULL;

    while (*quests != NULL && (*quests)->next != NULL) {
        if ((*quests)->number == nb) {
            save2 = (*quests)->next->next;
            free((*quests)->next->text);
            free((*quests)->next);
            (*quests)->next = save2;
        }
        else
            *quests = (*quests)->next;
    }
    *quests = save;
    if (*quests != NULL && (*quests)->number == nb) {
        *quests = (*quests)->next;
        free(save->text);
        free(save);
    }
}

void set_npc_direction_interact(character_t *character, npc_t *npc)
{
    if (character->direction == 1)
        npc->direction = 3;
    if (character->direction == 2)
        npc->direction = 4;
    if (character->direction == 3)
        npc->direction = 1;
    if (character->direction == 4)
        npc->direction = 2;
}

void aggro(game_t *game, npc_t *npc)
{
    if (npc && npc->diag2)
        display_text_overworld(game->window, npc->diag2, game);
    main_cbt(game->window, game, npc);
}

void get_quest_shoes(game_t *game, npc_t *npc)
{
    if (npc->diag1)
        display_text_overworld(game->window, npc->diag1, game);
    free(npc->diag1);
    put_quest_in_list(my_strdup("trouver les chaussures de courses et parler"
    " au professeur sorbier"), 1, &(game->character->quests));
    npc->diag1 = my_strdup("Va, comme dit le slogan, "
    "allez plus vite avec LShift !");
    npc->interact = 2;
}
