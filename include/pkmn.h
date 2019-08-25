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
    int xp_to_next_lvl;
    int speed;
    int physatq;
    int physdef;
    int speatq;
    int spedef;
    atk_t atks[4];
} pkmn_t;

#endif
