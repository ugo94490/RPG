/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_npcs
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

static void sub_sub_save_npc(FILE * file, char *nbr, npc_t *npc)
{
    fwrite("aggro:", 1, 6, file);
    nbr = my_itoa(npc->aggro, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    if (npc->diag1 != NULL) {
        fwrite("diag1:", 1, 6, file);
        fwrite(npc->diag1, 1, my_strlen(npc->diag1), file);
        fwrite("\n", 1, 1, file);
    }
    if (npc->diag2 != NULL) {
        fwrite("diag2:", 1, 6, file);
        fwrite(npc->diag2, 1, my_strlen(npc->diag2), file);
        fwrite("\n", 1, 1, file);
    }
    fwrite("interact:", 1, 9, file);
    nbr = my_itoa(npc->interact, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

static void sub_save_npc(FILE *file, char *nbr, npc_t *npc)
{
    fwrite("type:", 1, 5, file);
    nbr = my_itoa(npc->type, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("posx:", 1, 5, file);
    nbr = my_itoa(npc->pos.x, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("posy:", 1, 5, file);
    nbr = my_itoa(npc->pos.y, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("world:", 1, 6, file);
    nbr = my_itoa(npc->world, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("direction:", 1, 10, file);
    nbr = my_itoa(npc->direction, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

static void save_npc(FILE *file, char *nbr, npc_t *npc)
{
    fwrite("-npc\n", 1, 5, file);
    sub_save_npc(file, nbr, npc);
    sub_sub_save_npc(file, nbr, npc);
    save_pkmns((void *)(file), npc->pkmns);
    fwrite("\n", 1, 1, file);
}

static void sub_save_npcs(FILE *file, char *nbr, game_object_list_t *list)
{
    if (list && list->next)
        sub_save_npcs(file, nbr, list->next);
    if (list && list->type == NPC)
        save_npc(file, nbr, (npc_t *)(list->object));
}

void save_npcs(char *path, game_object_list_t *list)
{
    FILE *file = fopen(path, "w");
    char *nbr = malloc(sizeof(char) * 20);
    char *cpy = nbr;

    if (file == NULL || nbr == NULL)
        return;
    sub_save_npcs(file, nbr, list);
    fclose(file);
    free(cpy);
}
