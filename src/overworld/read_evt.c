/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** read_evt
*/

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
    event.music = 0;
    event.locmap = 0;
    event.trigger = 0;
    event.destmap = 0;
    event.dest = basevector;
    event.direction = 0;
    event.proba = 0;
    event.item = 0;
    event.quantity = 0;
    return (event);
}

void put_event_in_list(evt_list_t **list, evt_t event, int perm)
{
    evt_list_t *element = malloc(sizeof(evt_list_t));

    if (element == NULL)
        return;
    element->event = event;
    element->perm = perm;
    element->next = *list;
    *list = element;
}

static void sub_analyse_line_evt(char **ws, evt_t *ev)
{
    my_strcmp(ws[0], "destx") == 1 ? ev->dest.x = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "desty") == 1 ? ev->dest.y = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "destmap") == 1 ? ev->destmap = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "direction") == 1 ? ev->direction = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "height") == 1 ? ev->colrect.height = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "width") == 1 ? ev->colrect.width = my_getnbr(ws[1]) : 0;
}

void analyse_line_evt(char *line, evt_t *evt)
{
    char **ws = my_str_to_word_array(line, ": \n");

    if (get_nb_words(ws) < 2)
        return (free_word_array(ws));
    my_strcmp(ws[0], "type") == 1 ? evt->type = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "trigger") == 1 ? evt->trigger = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "proba") == 1 ? evt->proba = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "item") == 1 ? evt->item = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "quantity") == 1 ? evt->quantity = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "posx") == 1 ? evt->pos.x = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "posy") == 1 ? evt->pos.y = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "music") == 1 ? evt->music = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "locmap") == 1 ? evt->locmap = my_getnbr(ws[1]) : 0;
    sub_analyse_line_evt(ws, evt);
    free_word_array(ws);
}
