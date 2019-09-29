/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** how_to_play.h
*/

#ifndef _HOW_TO_PLAY_H_
#define _HOW_TO_PLAY_H_

#include "graphics.h"
#include "basics.h"
#include "my_rpg.h"

static const int NBR_HELP_IMG = 3;

enum STATE {
    START,
    STEP_ONE,
    STEP_TWO,
    END
};

typedef struct how_to_s {
    sprite_t *spriteHelp;
    sfIntRect rectProf;
    sfIntRect rectScreen;
    sfVector2f posProf;
    int state;
    int nbr_where;
} how_to_t;

#endif /* _HOW_TO_PLAY_H_ */