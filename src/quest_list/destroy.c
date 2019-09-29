/*
** EPITECH PROJECT, 2019
** destroy.c
** File description:
** destroy.c
*/

#include "my_rpg.h"

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
