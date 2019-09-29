/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt10.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"
#include "cbt.h"

int destroy_font(text_t *stat, int lim)
{
    for (int i = 0; i < lim; i++) {
        sfText_destroy(stat[i].text);
        sfFont_destroy(stat[i].font);
    }
    free(stat);
    return (0);
}

int cancel(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    int ret = 2;

    if (vct.x >= 358 && vct.x <= 921 && vct.y >= 845 && vct.y <= 954) {
        ret = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ret = 1;
            pause_time(0.3);
        }
    }
    return (ret);
}

int display_game(game_object **tab, window_t *window, int pos, int start)
{
    for (int i = start; i < pos + 1; i++)
        sfRenderWindow_drawSprite(window->window, tab[i]->sprite, NULL);
    return (0);
}

int attack_box(pkmn_list_t *linked, window_t *window,
int nb, game_object **tab)
{
    char *str = malloc(sizeof(char));
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};

    *str = 0;
    str = my_strcat(str, name[linked->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[nb]);
    str = my_strcat(str, phr[1]);
    pause_time(0.1);
    display_text(str, pos, window, 0);
    display_game(tab, window, 8, 0);
    sfRenderWindow_display(window->window);
    free(str);
    return (0);
}

int get_atk(pkmn_list_t *linked, int nb)
{
    int ret = -1;

    for (int i = 0; atk[i]; i++)
        if (my_strcmp(atk[i], atk_name[linked->pokemon.atks[nb].number])
            == 1)
            ret = i;
    return (ret);
}