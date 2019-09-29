/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_cbt7.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

int detect_one(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);

    if (linked->pokemon.atks[0].number != -1 && atk_pos[0].x *
        window->scale.x<= vct.x && (atk_pos[0].x + 293) * window->scale.x >=
        vct.x && atk_pos[0].y * window->scale.y <= vct.y && (atk_pos[0].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_one(window, linked, misc, npc));
    if (linked->pokemon.atks[1].number != -1 && atk_pos[1].x *
        window->scale.x<= vct.x && (atk_pos[1].x + 293) * window->scale.x >=
        vct.x && atk_pos[1].y * window->scale.y <= vct.y && (atk_pos[1].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_two(window, linked, misc, npc));
    return (0);
}

int detect_two(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);

    if (linked->pokemon.atks[2].number != -1 && atk_pos[2].x *
        window->scale.x<= vct.x && (atk_pos[2].x + 293) * window->scale.x >=
        vct.x && atk_pos[2].y * window->scale.y <= vct.y && (atk_pos[2].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_three(window, linked, misc, npc));
    if (linked->pokemon.atks[3].number != -1 && atk_pos[3].x *
        window->scale.x<= vct.x && (atk_pos[3].x + 293) * window->scale.x >=
        vct.x && atk_pos[3].y * window->scale.y <= vct.y && (atk_pos[3].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_four(window, linked, misc, npc));
    return (0);
}

int launch(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    int ret = 0;

    ret = detect_one(window, linked, misc, npc);
    if (ret == 1)
        return (ret);
    ret = detect_two(window, linked, misc, npc);
    if (ret == 1)
        return (ret);
    return (0);
}

char *itoa_dup(int nb)
{
    char *nbr = malloc(sizeof(char) * (my_int(nb) + 1));

    nbr = my_itoa(nb, nbr);
    return (nbr);
}

game_object **init_box(pkmn_list_t *linked, window_t *window)
{
    game_object **tab = malloc(sizeof(game_object *) * 5);
    sfIntRect rc = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        if (linked->pokemon.atks[i].number != -1)
            tab[i] = create_object("assets/attack.png", atk_pos[i], rc, window);
        else
            tab[i] = create_object("assets/vide.png", atk_pos[i], rc, window);
    }
    tab[4] = NULL;
    return (tab);
}