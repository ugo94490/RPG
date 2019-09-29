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
static const int NBR_STRING = 7;

static const char *PHRASE[7] = {"Bonjour,\nJe m'appelle Professeur Sorbier!\n",
    "Je vais t'apprendre comment jouer à ce jeu merveilleux :)\n",
    "Tout d'abord pour te déplacer, utiliser les flèches directionnelles de"
    "de ton clavier.\n", "Ensuite, pour intéragir avec les différentes"
    "entitées utilise la touche ESPACE de ton claver.\n", "Comme ceci\n",
    "Pour finir, pour courir maintient la touche SHIFT de ton clavier.\n",
    "Bon jeu dans l'univers Pokémon!\n"};

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