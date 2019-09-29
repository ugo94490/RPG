/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_quests
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

void put_quest_in_list(char *text, int number, quest_list_t **list)
{
    quest_list_t *element = malloc(sizeof(quest_list_t));

    if (element == NULL)
        return;
    element->text = text;
    element->number = number;
    element->next = *list;
    *list = element;
}

static void analyse_line_quest(char *line, int *number, char **text)
{
    char **ws = my_str_to_word_array(line, ": \n");

    if (get_nb_words(ws) < 2)
        return (free_word_array(ws));
    if (my_strcmp(ws[0], "number") == 1)
        *number = my_getnbr(ws[1]);
    if (my_strcmp(ws[0], "text") == 1)
        *text = my_strdup(ws[1]);
    free_word_array(ws);
}

static ssize_t load_quest(FILE *file, char *line, quest_list_t **list)
{
    int number = 0;
    char *text = NULL;
    size_t size = 0;
    ssize_t nread = 0;

    do {
        nread = getline(&line, &size, file);
        if (nread == -1)
            break;
        line[nread-1] = '\0';
        analyse_line_quest(line, &number, &text);
    } while (nread != -1 && my_strcmp(line, "-quest") != 1);
    if (number != 0)
        put_quest_in_list(text, number, list);
    if (line != NULL)
        free(line);
    return (nread);
}

void load_quests(char *path, quest_list_t **quests)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t size = 0;
    ssize_t nread = 0;

    if (file == NULL)
        return;
    do {
        nread = getline(&line, &size, file);
        if (nread == -1)
            break;
        else if (nread > 0)
            line[nread-1] = '\0';
        while (nread > 0 && my_strcmp(line, "-quest") == 1)
            nread = load_quest(file, line, quests);
    } while (nread != -1);
    if (line != NULL)
        free(line);
    fclose(file);
}
