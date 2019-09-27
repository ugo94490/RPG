/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_evts
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graphics.h"
#include "overworld.h"
#include "basics.h"

static int read_evt(FILE *file, char *line, evt_list_t **list, int arg)
{
    evt_t event = create_basic_event();
    size_t size = 0;
    ssize_t nread = 0;

    do {
        nread = getline(&line, &size, file);
        if (nread == -1)
            break;
        line[nread-1] = '\0';
        analyse_line_evt(line, &event);
    } while (nread != -1 && my_strcmp(line, "-evt") != 1);
    if (event.type != 0)
        put_event_in_list(list, event, arg);
    if (line != NULL)
        free(line);
    return (nread);
}

void read_evts(char *path, evt_list_t **list, int arg)
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
            nread = read_evt(file, line, list, arg);
    } while (nread != -1);
    if (line != NULL)
        free(line);
    fclose(file);
}
