/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** header for particule
*/

#ifndef PARTICULE_H
#define PARTICULE_H

void goutte(sfVertexArray *my_rain, sfVertex vertex, int x, int y);
void flocon(sfVertexArray *my_rain, sfVertex vertex, int x, int y);
void change(sfVertexArray *my_rain, sfIntRect pos);

#endif
