/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"
#include "graphics.h"
#include "basics.h"

static char *name[13] =
{
    "Ouisticram",
    "Tiplouf",
    "Tortipouss",
    "Chimpenfeu",
    "Prinplouf",
    "Boskerra",
    "Simiabraz",
    "Pingoleon",
    "Torterra",
    "Dialga",
    "Palkia",
    "Arceus",
    NULL
};

static char *front_pkm[12] =
{
    "assets/front/ouisticram.png",
    "assets/front/tiplouf.png",
    "assets/front/tortipouss.png",
    "assets/front/chimpenfeu.png",
    "assets/front/prinplouf.png",
    "assets/front/boskerra.png",
    "assets/front/simiabraz.png",
    "assets/front/pingoleon.png",
    "assets/front/torterra.png",
    "assets/front/dialga.png",
    "assets/front/palkia.png",
    "assets/front/arceus.png"
};

game_object **init_tab(game_t *game, window_t *window)
{
    game_object **tab = malloc(sizeof(game_object *) * (get_nb_words(front_pkm) + 1));
    sfVector2f temppos = {(game->character->pos.x + character_width / 2)
        * game->window->scale.x, (game->character->pos.y +
        character_height / 6) * game->window->scale.y};
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0};

    rect.width = 1280;
    rect.height = 970;
    tab[0] = create_object("assets/pokedex.png", pos, rect, window);
    for (int i = 0; i < get_nb_words(front_pkm) - 1; i++) {
        tab[i + 1] = create_object(front_pkm[i], pos, rect, window);
        rect.width = 173;
        rect.height = 176;
        pos.x += temppos.x - 240 * window->scale.x;
        if (pos.x > 1200) {
            pos.x = temppos.x - 100 * window->scale.x;
            pos.y += temppos.y - 240 * window->scale.y;
        }
    }
    return (tab);
}

int display_pokedex(window_t *window, game_object **tab)
{
    for (int i = 0; i < get_nb_words(front_pkm); i++) {
        // sfSprite_setTextureRect(tab[i]->sprite, tab[i]->rect);
        sfSprite_setScale(tab[i]->sprite, window->scale);
        sfSprite_setPosition(tab[i]->sprite, tab[i]->pos);
        sfRenderWindow_drawSprite(window->window, tab[i]->sprite, NULL);
    }
    return (0);
}

int destroy(game_object **tab)
{
    for (int i = 0; i < get_nb_words(front_pkm); i++) {
        sfSprite_destroy(tab[i]->sprite);
        sfTexture_destroy(tab[i]->texture);
        free(tab[i]);
    }
    free(tab);
    return (0);
}

text_t *init_text(game_t *game, window_t *window)
{
    sfVector2f temppos = {(game->character->pos.x + character_width / 2)
        * game->window->scale.x, (game->character->pos.y +
        character_height / 6) * game->window->scale.y};
    text_t *txt = malloc(sizeof(text_t) * 12);
    sfVector2f pos = {temppos.x - 110 * window->scale.x, temppos.y - 216 * window->scale.y};

    for (int i = 0; i < 12; i++) {
        txt[i] = create_text(strdup(name[i]), "assets/classic.ttf",
        15 * window->scale.x, pos);
        sfText_setFillColor(txt[i].text, sfBlack);
        pos.x += 240 * window->scale.x;
        if (pos.x > 1200 * window->scale.x) {
            pos.x = 110 * window->scale.x;
            pos.y += 240 * window->scale.y;
        }
    }
    return (txt);
}

int display_txt(window_t *window, text_t *txt)
{
    for (int i = 0; i < 12; i++)
        sfRenderWindow_drawText(window->window, txt[i].text, NULL);
    return (0);
}

int destroy_txt(text_t *txt)
{
    for (int i = 0; i < 12; i++)
        destroy_text(&txt[i]);
    free(txt);
    return (0);
}

void pokedex(game_t *game, window_t *window)
{
    game_object **tab = init_tab(game, window);
    text_t *txt = init_text(game, window);

    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        display_pokedex(window, tab);
        display_txt(window, txt);
        sfRenderWindow_display(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        // event(window);
    }
    destroy_txt(txt);
    destroy(tab);
}