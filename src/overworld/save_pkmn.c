/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_pkmn
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
#include "pkmn.h"

static void save_pkmn_atks(FILE *file, char *nbr, pkmn_t pkmn)
{
    fwrite("atk1:", 1, 5, file);
    nbr = my_itoa(pkmn.atks[0].number, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("atk2:", 1, 5, file);
    nbr = my_itoa(pkmn.atks[1].number, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("atk3:", 1, 5, file);
    nbr = my_itoa(pkmn.atks[2].number, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("atk4:", 1, 5, file);
    nbr = my_itoa(pkmn.atks[3].number, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

static void sub_save_pkmn(FILE *file, char *nbr, pkmn_t pkmn)
{
    nbr = my_itoa(pkmn.health, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("max_health:", 1, 11, file);
    nbr = my_itoa(pkmn.max_health, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("xp_to_next_lvl:", 1, 15, file);
    nbr = my_itoa(pkmn.xp_to_next_lvl, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("atq:", 1, 4, file);
    nbr = my_itoa(pkmn.atq, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("def:", 1, 4, file);
    nbr = my_itoa(pkmn.def, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

void save_pkmn(FILE *file, pkmn_t pkmn)
{
    char *nbr = malloc(sizeof(char) * 20);
    char *cpy = nbr;

    if (nbr == NULL || file == NULL)
        return;
    fwrite("-pkmn\n", 1, 6, file);
    fwrite("number:", 1, 7, file);
    nbr = my_itoa(pkmn.number, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("level:", 1, 6, file);
    nbr = my_itoa(pkmn.level, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("health:", 1, 7, file);
    sub_save_pkmn(file, nbr, pkmn);
    save_pkmn_atks(file, nbr, pkmn);
    fwrite("\n", 1, 1, file);
    free(cpy);
}

void save_pkmns(void *file, pkmn_list_t *pkmns)
{
    if (pkmns != NULL && pkmns->next != NULL)
        save_pkmns(file, pkmns->next);
    if (pkmns != NULL)
        save_pkmn((FILE *)(file), pkmns->pokemon);
}
