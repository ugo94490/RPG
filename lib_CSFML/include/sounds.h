/*
** EPITECH PROJECT, 2019
** CGraphical programming
** File description:
** sounds lib functions
*/

#ifndef SOUNDS_H
#define SOUNDS_H

typedef struct sound_s
{
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

sound_t create_sound(char *soundpath, int volume);
void destroy_sound(sound_t *sound);

#endif
