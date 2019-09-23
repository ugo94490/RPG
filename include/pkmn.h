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
} atk_t;

static const atk_t atks[4] =
{
    {0, 0},
    {1, 100},
    {2, 50},
    {3, 70}
};

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

static char *name[3] =
{
    "Simiabraz",
    "Torterra",
    NULL
};

static char *atk[1] =
{
    "Hydrocanon"
};

static char *asset_atk[1] =
{
    "../assets/hydrocanon.png"
};

static char *atk_name[4] =
{
    "Charge",
    "Hydrocanon",
    "Ultralaser",
    "OmegaLOL"
};

static char *phr[2] =
{
    " attaque ",
    " !"
};

static const sfVector2f atk_pos[4] =
{
    {342, 536},
    {342, 683},
    {645, 536},
    {645, 683}
};

static const sfVector2f pos_txt[6] =
{
    {880, 328},
    {815, 328},
    {885, 280},
    {535, 141},
    {340, 135},
    {700, 275}
};

static const sfVector2f atk_txt[8] =
{
    {372, 566},
    {372, 713},
    {675, 566},
    {675, 713},
    {524, 622},
    {524, 769},
    {827, 622},
    {827, 769}
};

void load_pkmn(FILE *file, char *line, ssize_t *nread,
struct pkmn_list_s **list);

#endif
