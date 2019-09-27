/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_save_evts
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graphics.h"
#include "overworld.h"
#include "basics.h"

static void sub_save_evt(FILE *file, char *nbr, evt_t evt)
{
    fwrite("type:", 1, 5, file);
    nbr = my_itoa(evt.type, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("posx:", 1, 5, file);
    nbr = my_itoa(evt.pos.x, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("posy:", 1, 5, file);
    nbr = my_itoa(evt.pos.y, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("locmap:", 1, 6, file);
    nbr = my_itoa(evt.locmap, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("direction:", 1, 10, file);
    nbr = my_itoa(evt.direction, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

static void sub_save_evt_2(FILE *file, char *nbr, evt_t evt)
{
    fwrite("width:", 1, 6, file);
    nbr = my_itoa(evt.colrect.width, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("height:", 1, 7, file);
    nbr = my_itoa(evt.colrect.height, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("trigger:", 1, 8, file);
    nbr = my_itoa(evt.trigger, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("destx:", 1, 6, file);
    nbr = my_itoa(evt.dest.x, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("desty:", 1, 6, file);
    nbr = my_itoa(evt.dest.y, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

static void sub_save_evt_3(FILE *file, char *nbr, evt_t evt)
{
    fwrite("destmap:", 1, 8, file);
    nbr = my_itoa(evt.destmap, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("proba:", 1, 6, file);
    nbr = my_itoa(evt.proba, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("item:", 1, 5, file);
    nbr = my_itoa(evt.item, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("quantity:", 1, 9, file);
    nbr = my_itoa(evt.quantity, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("music:", 1, 6, file);
    nbr = my_itoa(evt.music, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
}

static void save_evt(FILE *file, evt_t event)
{
    char *nbr = malloc(sizeof(char) * 20);
    char *cpy = nbr;

    if (file == NULL || nbr == NULL)
        return;
    fwrite("-evt\n", 1, 5, file);
    sub_save_evt(file, nbr, event);
    sub_save_evt_2(file, nbr, event);
    sub_save_evt_3(file, nbr, event);
    fwrite("\n", 1, 1, file);
    free(cpy);
}

void sub_save_evts(void *file, evt_list_t *evts)
{
    if (evts && evts->next)
        sub_save_evts(file, evts->next);
    if (evts && evts->perm == 0)
        save_evt((FILE *)(file), evts->event);
}
