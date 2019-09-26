/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_character
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

static void sub_save_character(FILE *file, char *nbr, character_t *character)
{
    fwrite("type:", 1, 5, file);
    nbr = my_itoa(character->type, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("posx:", 1, 5, file);
    nbr = my_itoa(character->pos.x, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("posy:", 1, 5, file);
    nbr = my_itoa(character->pos.y, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("world:", 1, 6, file);
    nbr = my_itoa(character->world, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("direction:", 1, 10, file);
    nbr = my_itoa(character->direction, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

void save_character(char *path, character_t *character)
{
    FILE *file = fopen(path, "w");
    char *nbr = malloc(sizeof(char) * 20);
    char *cpy = nbr;

    if (nbr == NULL || file == NULL || character == NULL)
        return;
    sub_save_character(file, nbr, character);
    fwrite("music:", 1, 6, file);
    nbr = my_itoa(character->music, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    save_pkmns((void *)(file), character->pkmns);
    fclose(file);
    free(cpy);
}
