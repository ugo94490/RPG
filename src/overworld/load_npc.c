/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_npcs
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "overworld_rects.h"
#include "basics.h"
#include "pkmn.h"

npc_t *create_base_npc(void)
{
    npc_t *npc = malloc(sizeof(npc_t));
    sfVector2f basevector = {0, 0};
    anim_t baseanim = {16, 0, 0, 0, 0};

    if (npc == NULL)
        return (NULL);
    npc->type = 0;
    npc->status = 0;
    npc->aggro = 0;
    npc->direction = 0;
    npc->diag1 = NULL;
    npc->diag2 = NULL;
    npc->pos = basevector;
    npc->world = 0;
    npc->anim = baseanim;
    npc->anim.rects = barry_rects;
    npc->anim.clock = create_clock();
    npc->pkmns = NULL;
    npc->interact = 0;
    return (npc);
}

void analyse_line_npc(char *line, npc_t *npc)
{
    char **words = my_str_to_word_array(line, ":\n");

    if (get_nb_words(words) < 2)
        return (free_word_array(words));
    my_strcmp(words[0], "type") == 1 ? npc->type = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "world") == 1 ? npc->world = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "diag1") == 1 ? npc->diag1 = my_strdup(words[1]) : 0;
    my_strcmp(words[0], "diag2") == 1 ? npc->diag2 = my_strdup(words[1]) : 0;
    my_strcmp(words[0], "aggro") == 1 ? npc->type = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "interact") == 1 ?
    npc->interact = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "direction") == 1 ?
    npc->direction = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "posx") == 1 ? npc->pos.x = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "posy") == 1 ? npc->pos.y = my_getnbr(words[1]) : 0;
    free_word_array(words);
}

void load_npc(FILE *file, char *line, game_object_list_t **list, ssize_t *nread)
{
    npc_t *npc = create_base_npc();
    size_t size = 0;

    if (npc == NULL)
        return;
    do {
        *nread = getline(&line, &size, file);
        if (*nread == -1)
            break;
        line[*nread-1] = '\0';
        if (my_strcmp(line, "-pkmn") == 1)
            load_pkmn(file, line, nread, &(npc->pkmns));
        analyse_line_npc(line, npc);
    } while (*nread != -1 && my_strcmp(line, "-npc") != 1);
    npc->anim.rects = pnjRects[npc->type];
    npc->objective = npc->pos;
    put_object_in_objects(list, (void *)(npc), NPC, 3);
    if (line != NULL)
        free(line);
}

void load_npcs(char *path, game_object_list_t **list)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t size = 0;
    ssize_t nread = 0;

    if (file == NULL)
        return;
    do {
        nread = getline(&line, &size, file);
        if (nread == -1)
            break;
        else if (nread > 0)
            line[nread-1] = '\0';
         while (nread > 0 && my_strcmp(line, "-npc") == 1)
            load_npc(file, line, list, &nread);
    } while (nread != -1);
    if (line != NULL)
        free(line);
    fclose(file);
}
