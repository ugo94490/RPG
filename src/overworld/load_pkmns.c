/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_pkmns
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "pkmn.h"
#include "basics.h"

void put_pkmn_in_list(pkmn_list_t **list, pkmn_t pkmn)
{
    pkmn_list_t *element = malloc(sizeof(pkmn_list_t));

    if (element == NULL)
        return;
    element->next = *list;
    element->pokemon = pkmn;
    *list = element;
}

pkmn_t create_basic_pkmn(void)
{
    pkmn_t pkmn = {0, 1, 0, 0, 0, 0, 0};

    pkmn.atks[0] = atks[0];
    pkmn.atks[1] = atks[0];
    pkmn.atks[2] = atks[0];
    pkmn.atks[3] = atks[0];
    return (pkmn);
}

void analyse_line_pkmn(char *line, pkmn_t *pkmn)
{
    char **words = my_str_to_word_array(line, ": \n");

    if (get_nb_words(words) < 2)
        return (free_word_array(words));
    if (my_strcmp(words[0], "number") == 1)
        pkmn->number = my_getnbr(words[1]);
    if (my_strcmp(words[0], "level") == 1)
        pkmn->level = my_getnbr(words[1]);
    if (my_strcmp(words[0], "health") == 1)
        pkmn->health = my_getnbr(words[1]);
    if (my_strcmp(words[0], "max_health") == 1)
        pkmn->max_health = my_getnbr(words[1]);
    if (my_strcmp(words[0], "xp_to_next_lvl") == 1)
        pkmn->xp_to_next_lvl = my_getnbr(words[1]);
    if (my_strcmp(words[0], "atq") == 1)
        pkmn->atq = my_getnbr(words[1]);
    if (my_strcmp(words[0], "def") == 1)
        pkmn->def = my_getnbr(words[1]);
    if (my_strcmp(words[0], "atk1") == 1)
        pkmn->atks[0] = atks[my_getnbr(words[1])];
    if (my_strcmp(words[0], "atk2") == 1)
        pkmn->atks[1] = atks[my_getnbr(words[1])];
    if (my_strcmp(words[0], "atk3") == 1)
        pkmn->atks[2] = atks[my_getnbr(words[1])];
    if (my_strcmp(words[0], "atk4") == 1)
        pkmn->atks[3] = atks[my_getnbr(words[1])];
    free_word_array(words);
}

void load_pkmn(FILE *file, char *line, ssize_t *nread, pkmn_list_t **list)
{
    pkmn_t pkmn = create_basic_pkmn();
    size_t size = 0;

     do {
        *nread = getline(&line, &size, file);
        if (*nread == -1)
            break;
        line[*nread-1] = '\0';
        analyse_line_pkmn(line, &pkmn);
    } while (*nread != -1 && line[0] != '\0');
    if (line != NULL)
        free(line);
    put_pkmn_in_list(list, pkmn);
}
