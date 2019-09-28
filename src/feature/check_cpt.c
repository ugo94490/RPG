/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check if need to put a new char (controled by a clock)
*/

#include <stdlib.h>
#include "text.h"
#include "basics.h"
#include "my_rpg.h"

static float get_seconds(sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return seconds;
}

static char *my_strappend(char *str, char c)
{
    int cpt = 0;
    char *new = NULL;

    new = malloc(sizeof(char) * my_strlen(str) + 2);
    for (; str[cpt] != '\0'; ++cpt)
        new[cpt] = str[cpt];
    new[cpt++] = c;
    new[cpt] = '\0';
    free(str);
    return new;
}

int check_cpt(txt_t *text, int cpt, sfRenderWindow *window, sfSprite *sprite)
{
    text->seconds = get_seconds(text->clock);
    if (text->seconds > 0.03) {
        sfClock_restart(text->clock);
        text->tmp = my_strappend(text->tmp, text->str[cpt]);
        if (text->str[cpt] == '\n')
            text->flag++;
        display(text->text, text->tmp, window, sprite);
        cpt++;
    }
    return cpt;
}
