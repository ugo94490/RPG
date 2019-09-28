/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pkmn header
*/

#ifndef PKMN_H
#define PKMN_H

#include "graphics.h"

#define NB_ATK 4

struct item_list_s;

typedef struct atk_s
{
    int number;
    int power;
} atk_t;

typedef struct pkmn_s
{
    int number;
    int level;
    int health;
    int max_health;
    int xp_to_next_lvl;
    int atq;
    int def;
    atk_t atks[4];
} pkmn_t;

typedef struct pkmn_list_s
{
    pkmn_t pokemon;
    struct pkmn_list_s *next;
} pkmn_list_t;

void load_pkmn(FILE *file, char *line, ssize_t *nread,
struct pkmn_list_s **list);
void load_item(FILE *file, char *line, ssize_t *nread,
struct item_list_s **list);

#endif
