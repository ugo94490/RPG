/*
** EPITECH PROJECT, 2019
** CGraphical programming
** File description:
** clock functions
*/

#include <SFML/System.h>
#include <stdlib.h>
#include "systems.h"

clock_sf create_clock(void)
{
    clock_sf clock;

    clock.clock = sfClock_create();
    return (clock);
}

clock_sf *create_clock_array(int nb)
{
    clock_sf *clock = malloc(sizeof(clock_sf) * nb);
    int i = 0;

    for (; i < nb; i++) {
        clock[i] = create_clock();
    }
    return (clock);
}

void my_put_in_clist(clock_list_t **list, clock_sf clock)
{
    clock_list_t *element = malloc(sizeof(clock_list_t));

    if (element == NULL)
        return;
    element->clock = clock;
    element->next = *list;
    *list = element;
}

void free_clist(clock_list_t *list)
{
    if (list != NULL && list->next != NULL)
        free_clist(list->next);
    if (list != NULL)
        sfClock_destroy(list->clock.clock);
}

void destroy_clock(clock_sf *clock)
{
    if (clock->clock != NULL)
        sfClock_destroy(clock->clock);
}
