/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_quests
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "basics.h"

static void save_quest(FILE *file, quest_list_t *quest)
{
    char *nbr = malloc(sizeof(char) * 20);
    char *cpy = nbr;

    if (file == NULL || nbr == NULL)
        return;
    fwrite("-quest\n", 1, 7, file);
    fwrite("number:", 1, 7, file);
    nbr = my_itoa(quest->number, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("text:", 1, 5, file);
    if (quest->text)
        fwrite(quest->text, 1, my_strlen(quest->text), file);
    fwrite("\n", 1, 1, file);
    fwrite("\n", 1, 1, file);
    free(cpy);
}

static void sub_save_quests(FILE *file, quest_list_t *quests)
{
    if (quests && quests->next)
        sub_save_quests(file, quests->next);
    if (quests)
        save_quest(file, quests);
}

void save_quests(quest_list_t *quests)
{
    FILE *file = fopen("save/actualsave/quests", "w");

    if (file == NULL)
        return;
    sub_save_quests(file, quests);
    fclose(file);
}
