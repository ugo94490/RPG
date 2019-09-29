/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "pokedex.h"

static game_object **init_tab(window_t *window)
{
    game_object **tab = malloc(sizeof(game_object *) * 22);
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0};

    rect.width = 1280;
    rect.height = 970;
    tab[0] = create_object("assets/pokedex.png", pos, rect, window);
    pos.x = 70;
    for (int i = 0; i < 20; i++) {
        tab[i + 1] = create_object(front_pkm[i], pos, rect, window);
        rect.width = 173;
        rect.height = 176;
        pos.x += 240 * window->scale.x;
        if (pos.x > 1100 * window->scale.x) {
            pos.x = 70;
            pos.y += 240 * window->scale.y;
        }
    }
    return (tab);
}

static int display_pokedex(window_t *window, game_object **tab)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(window->window);

    sfRenderWindow_setView(window->window, default_view);
    for (int i = 0; i < 21; i++) {
        sfSprite_setTextureRect(tab[i]->sprite, tab[i]->rect);
        sfSprite_setScale(tab[i]->sprite, window->scale);
        sfSprite_setPosition(tab[i]->sprite, tab[i]->pos);
        sfRenderWindow_drawSprite(window->window, tab[i]->sprite, NULL);
    }
    return (0);
}

static int display_txt(window_t *window, text_t *txt)
{
    for (int i = 0; i < 20; i++)
        sfRenderWindow_drawText(window->window, txt[i].text, NULL);
    return (0);
}

static int destroy_txt(text_t *txt)
{
    for (int i = 0; i < 20; i++)
        destroy_text(&txt[i]);
    free(txt);
    return (0);
}

void pokedex(game_t *game, window_t *window)
{
    game_object **tab = init_tab(window);
    text_t *txt = init_text(window);

    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        display_pokedex(window, tab);
        display_txt(window, txt);
        sfRenderWindow_display(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        event(window);
    }
    set_view_params(window, game);
    destroy_txt(txt);
    destroy(tab);
}
