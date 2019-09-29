/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** name of pkm
*/

#include "pokedex_name.h"
#include "my_rpg.h"
#include "graphics.h"
#include "basics.h"

int destroy(game_object **tab)
{
    for (int i = 0; i < 20; i++) {
        sfSprite_destroy(tab[i]->sprite);
        sfTexture_destroy(tab[i]->texture);
        free(tab[i]);
    }
    free(tab);
    return (0);
}

text_t *init_text(window_t *window)
{
    text_t *txt = malloc(sizeof(text_t) * 20);
    sfVector2f pos = {70, 220 * window->scale.y};

    for (int i = 0; i < 20; i++) {
        txt[i] = create_text(strdup(name[i]), "assets/classic.ttf",
        15 * window->scale.x, pos);
        sfText_setFillColor(txt[i].text, sfBlack);
        pos.x += 240 * window->scale.x;
        if (pos.x > 1100 * window->scale.x) {
            pos.x = 70;
            pos.y += 240 * window->scale.y;
        }
    }
    return (txt);
}
