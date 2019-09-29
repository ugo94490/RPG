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

typedef struct how_to_s {
    sprite_t spriteHelp[3];
    sfIntRect rectProf;
    sfIntRect rectScreen;
    sfVector2f posProf;
} how_to_t;

#endif /* _HOW_TO_PLAY_H_ */