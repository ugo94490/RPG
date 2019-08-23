/*
** EPITECH PROJECT, 2019
** CGraphical programming
** File description:
** sound functions
*/

#include <SFML/Audio.h>
#include "sounds.h"

void destroy_sound(sound_t *sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
}

sound_t create_sound(char *soundpath, int volume)
{
    sound_t sound;

    sound.buffer = sfSoundBuffer_createFromFile(soundpath);
    sound.sound = sfSound_create();
    sfSound_setBuffer(sound.sound, sound.buffer);
    sfSound_setVolume(sound.sound, volume);
    return (sound);
}
