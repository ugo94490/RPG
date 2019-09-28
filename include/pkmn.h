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

static atk_t atks[4] =
{
    {0, 20},
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

static char *name[13] =
{
    "Ouisticram",
    "Tiplouf",
    "Tortipouss",
    "Chimpenfeu",
    "Prinplouf",
    "Boskerra",
    "Simiabraz",
    "Pingoleon",
    "Torterra",
    "Dialga",
    "Palkia",
    "Arceus",
    NULL
};

static char *atk[3] =
{
    "Hydrocanon",
    "Ultralaser",
    NULL
};

static char *asset_atk[2] =
{
    "assets/hydrocanon.png",
    "assets/ultralaser.png"
};

static char *front_pkm[12] =
{
    "assets/front/ouisticram.png",
    "assets/front/tiplouf.png",
    "assets/front/tortipouss.png",
    "assets/front/chimpenfeu.png",
    "assets/front/prinplouf.png",
    "assets/front/boskerra.png",
    "assets/front/simiabraz.png",
    "assets/front/pingoleon.png",
    "assets/front/torterra.png",
    "assets/front/dialga.png",
    "assets/front/palkia.png",
    "assets/front/arceus.png"
};

static char *back_pkm[12] =
{
    "assets/back/ouisticram.png",
    "assets/back/tiplouf.png",
    "assets/back/tortipouss.png",
    "assets/back/chimpenfeu.png",
    "assets/back/prinplouf.png",
    "assets/back/boskerra.png",
    "assets/back/simiabraz.png",
    "assets/back/pingoleon.png",
    "assets/back/torterra.png",
    "assets/back/dialga.png",
    "assets/back/palkia.png",
    "assets/back/arceus.png"
};

static char *atk_name[4] =
{
    "Charge",
    "Hydrocanon",
    "Ultralaser",
    "OmegaLOL"
};

static char *phr[3] =
{
    " attaque ",
    " !",
    " est K.O !"
};

static sfVector2f atk_pos[4] =
{
    {342, 536},
    {342, 683},
    {645, 536},
    {645, 683}
};

static sfVector2f pos_txt[8] =
{
    {880, 328},
    {815, 328},
    {885, 280},
    {535, 141},
    {340, 135},
    {700, 275},
    {355, 165},
    {415, 165}
};

static sfVector2f atk_txt[8] =
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
void load_item(FILE *file, char *line, ssize_t *nread,
struct item_list_s **list);

#endif
