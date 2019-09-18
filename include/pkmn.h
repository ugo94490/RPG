/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pkmn header
*/

#ifndef PKMN_H
#define PKMN_H

typedef struct atk_s
{
    int number;
    int power;
    int type;
    int spetype;
} atk_t;

typedef struct pkmn_s
{
    int number;
    int level;
    int health;
    int max_health;
    int xp_to_next_lvl;
    int speed;
    int physatq;
    int physdef;
    int speatq;
    int spedef;
    atk_t atks[4];
} pkmn_t;

typedef struct pkmn_list_s
{
    pkmn_t pokemon;
    struct pkmn_list_s *next;
} pkmn_list_t;

static char *name[3] = {"Simiabraz", "Torterra", NULL};

#endif
