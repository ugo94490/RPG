/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** music_fcts
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sounds.h>

static const char *musics[4] =
{
    "assets/hometown.ogg",
    "assets/route201.ogg",
    "assets/pokecenter.ogg",
    "assets/market.ogg"
};

sfMusic *load_music(int index)
{
    sfMusic *music;

    if (index <= 0 || index > 4)
        index = 1;
    music = sfMusic_createFromFile(musics[index-1]);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}

void change_music(int index, sfMusic **music, int *actualmusic)
{
    if (index <= 0 || index > 4 || index == *actualmusic)
        return;
    sfMusic_stop(*music);
    sfMusic_destroy(*music);
    *music = sfMusic_createFromFile(musics[index-1]);
    sfMusic_setLoop(*music, sfTrue);
    sfMusic_play(*music);
    *actualmusic = index;
}
