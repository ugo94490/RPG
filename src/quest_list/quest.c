/*
** EPITECH PROJECT, 2019
** quest.c
** File description:
** quest.c
*/

#include "my_rpg.h"
#include "basics.h"

int destroy_back(game_object *back)
{
    sfSprite_destroy(back->sprite);
    sfTexture_destroy(back->texture);
    free(back);
    return (0);
}

int nb_quest(game_t *game)
{
    int compteur = 0;

    if (game->character->quests == NULL)
        return (compteur);
    compteur++;
    while (game->character->quests->next != NULL) {
        game->character->quests = game->character->quests->next;
        compteur++;
    }
    return (compteur);
}

text_t *init_tabtxt(game_t *game, int nb)
{
    text_t *tab = malloc(sizeof(text_t) * nb);
    int size = 20;
    sfVector2f pos = {100, 20};

    for (int i = 0; i < nb; i++) {
        tab[i] = create_text(my_strdup(game->character->quests->text),
        "assets/classic.ttf", size, pos);
        pos.y += 40;
        sfText_setFillColor(tab[i].text, sfBlack);
        game->character->quests = game->character->quests->next;
    }
    return (tab);
}

int draw_quest(text_t *tab, window_t *window, int nb)
{
    for (int i = 0; i < nb; i++) {
        sfRenderWindow_drawText(window->window, tab[i].text, NULL);
    }
    return (0);
}

int destroy_tabtxt(text_t *tab, int nb)
{
    for (int i = 0; i < nb; i++)
        destroy_text(&tab[i]);
    free(tab);
    return (0);
}

int quest(window_t *win, game_t *game)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 0, 0};
    game_object *back = create_object("assets/back_quest.png", pos, rect, win);
    int nb = nb_quest(game);
    text_t *tab = init_tabtxt(game, nb);

    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        sfRenderWindow_drawSprite(win->window, back->sprite, NULL);
        draw_quest(tab, win, nb);
        sfRenderWindow_display(win->window);
        event(win);
        if (sfKeyboard_isKeyPressed(sfKeyB))
            break;
    }
    destroy_tabtxt(tab, nb);
    destroy_back(back);
    return (0);
}

int launch_quest(window_t *window, game_t *game)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(window->window);

    sfRenderWindow_setView(window->window, default_view);
    quest(window, game);
    set_view_params(window, game);
    return (0);
}
