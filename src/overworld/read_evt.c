/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** read_evt
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graphics.h"
#include "overworld.h"
#include "basics.h"

evt_t create_basic_event(void)
{
    evt_t event;
    sfIntRect baserect = {0, 0, 0, 0};
    sfVector2f basevector = {0, 0};

    event.type = 0;
    event.pos = basevector;
    event.colrect = baserect;
    event.locmap = 0;
    event.trigger = 0;
    event.destmap = 0;
    event.dest = basevector;
    event.direction = 0;
    event.proba = 0;
    event.item = 0;
    return (event);
}

void put_event_in_list(evt_list_t **list, evt_t event)
{
    evt_list_t *element = malloc(sizeof(evt_list_t));

    if (element == NULL)
        return;
    element->event = event;
    element->next = *list;
    *list = element;
}

void analyse_line_evt(char *line, evt_t *evt)
{
    char **words = my_str_to_word_array(line, ": \n");

    if (get_nb_words(words) < 2)
        return (free_word_array(words));
    my_strcmp(words[0], "type") == 1 ? evt->type = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "trigger") == 1 ?
    evt->trigger = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "proba") == 1 ? evt->proba = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "item") == 1 ? evt->item = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "posx") == 1 ? evt->pos.x = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "posy") == 1 ? evt->pos.y = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "locmap") == 1 ? evt->locmap = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "destx") == 1 ? evt->dest.x = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "desty") == 1 ? evt->dest.y = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "destmap") == 1 ?
    evt->destmap = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "direction") == 1 ?
    evt->direction = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "height") == 1 ?
    evt->colrect.height = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "width") == 1 ?
    evt->colrect.width = my_getnbr(words[1]) : 0;
    free_word_array(words);
}

void read_evt(FILE *file, char *line, evt_list_t **list, ssize_t *nread)
{
    evt_t event = create_basic_event();
    size_t size = 0;

    do {
        *nread = getline(&line, &size, file);
        if (*nread == -1)
            break;
        line[*nread-1] = '\0';
        analyse_line_evt(line, &event);
    } while (*nread != -1 && my_strcmp(line, "-evt") != 1);
    if (event.type != 0)
        put_event_in_list(list, event);
    if (line != NULL)
        free(line);
}

void read_evts(char *path, evt_list_t **list)
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
        while (nread > 0 && my_strcmp(line, "-evt") == 1)
            read_evt(file, line, list, &nread);
    } while (nread != -1);
    if (line != NULL)
        free(line);
    fclose(file);
}
