/*
** EPITECH PROJECT, 2019
** CGraphical programming
** File description:
** header with system SFML lib functions
*/

#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <SFML/System.h>

typedef struct clock_s
{
    sfClock *clock;
    sfTime time;
} clock_sf;

typedef struct clock_list_s
{
    struct clock_list_s *next;
    clock_sf clock;
} clock_list_t;

clock_sf create_clock(void);
clock_sf *create_clock_array(int nb);
void my_put_in_clist(clock_list_t **list, clock_sf clock);
void destroy_clock(clock_sf *clock);

#endif
