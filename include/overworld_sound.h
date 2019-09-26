/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** overworld_sound_header
*/

#ifndef OVERWORLD_SOUNDS_H
#define OVERWORLD_SOUNDS_H

sfMusic *load_music(int index);
void change_music(int index, sfMusic **music, int *actualmusic);

#endif
