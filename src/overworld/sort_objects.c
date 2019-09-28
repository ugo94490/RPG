/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sort_objects
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "basics.h"
#include "game_object.h"

static int check_sorted_list(game_object_list_t *list)
{
    while (list->next != NULL) {
        if (get_posy_obj(list) > get_posy_obj(list->next))
            return (1);
        list = list->next;
    }
    return (0);
}

static void sort(game_object_list_t **la, game_object_list_t **lb)
{
    while ((*la) != NULL) {
        if (*la != NULL && (*la)->next != NULL &&
        get_posy_obj((*la)->next) < get_posy_obj(*la))
            reverse_first_two_elements(la);
        if (*lb != NULL && (*lb)->next != NULL &&
        get_posy_obj((*lb)->next) > get_posy_obj(*lb))
            reverse_first_two_elements(lb);
        push_in_other_list(la, lb);
    }
    while ((*lb) != NULL) {
        if (*la != NULL && (*la)->next != NULL &&
        get_posy_obj((*la)->next) < get_posy_obj(*la))
            reverse_first_two_elements(la);
        if (*lb != NULL && (*lb)->next != NULL &&
        get_posy_obj((*lb)->next) > get_posy_obj(*lb))
            reverse_first_two_elements(lb);
        push_in_other_list(lb, la);
    }
}

void sort_list(game_object_list_t **objects)
{
    game_object_list_t *la = *objects;
    game_object_list_t *lb = NULL;

    while (check_sorted_list(la) == 1) {
        sort(&la, &lb);
    }
    *objects = la;
}
