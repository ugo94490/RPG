/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** header for pokedex
*/

#ifndef POKEDEX_H
#define POKEDEX_H

#include "my_rpg.h"
#include "graphics.h"
#include "basics.h"

static char *front_pkm[20] =
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
    "assets/front/etourmi.png",
    "assets/front/etouraptor.png",
    "assets/front/keunotor.png",
    "assets/front/castorno.png",
    "assets/front/lixy.png",
    "assets/front/luxray.png",
    "assets/front/charkos.png",
    "assets/front/bastiodon.png",
    "assets/front/dialga.png",
    "assets/front/palkia.png",
    "assets/front/arceus.png"
};

int destroy(game_object **tab);

text_t *init_text(window_t *window);

#endif
