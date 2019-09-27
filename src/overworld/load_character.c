/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_character
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "overworld_rects.h"
#include "basics.h"
#include "pkmn.h"

character_t *create_base_character(void)
{
    character_t *character = malloc(sizeof(character_t));
    sfVector2f basevector = {0, 0};
    anim_t baseanim = {32, 0, 0, 0, 0};

    if (character == NULL)
        return (NULL);
    character->type = 0;
    character->status = 0;
    character->direction = 0;
    character->pos = basevector;
    character->world = 0;
    character->music = 0;
    character->anim = baseanim;
    character->anim.rects = dawn_rects;
    character->anim.clock = create_clock();
    character->pkmns = NULL;
    character->items = NULL;
    return (character);
}

void analyse_line_character(char *line, character_t *character)
{
    char **words = my_str_to_word_array(line, ": \n");

    if (get_nb_words(words) < 2)
        return (free_word_array(words));
    if (my_strcmp(words[0], "type") == 1 && my_getnbr(words[1]) <= 1)
        character->type = my_getnbr(words[1]);
    my_strcmp(words[0], "world") == 1 ?
    character->world = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "music") == 1 ?
    character->music = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "direction") == 1 ?
    character->direction = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "posx") == 1 ?
    character->pos.x = my_getnbr(words[1]) : 0;
    my_strcmp(words[0], "posy") == 1 ?
    character->pos.y = my_getnbr(words[1]) : 0;
    free_word_array(words);
}

character_t *get_character(char *path, game_object_list_t **list)
{
    FILE *file = fopen(path, "r");
    character_t *character = create_base_character();
    size_t size = 0;
    ssize_t nread = 0;
    char *line = NULL;

    if (file == NULL || character == NULL)
        return (NULL);
    while ((nread = getline(&line, &size, file)) != -1) {
        line[nread-1] = '\0';
        if (my_strcmp(line, "-pkmn") == 1)
            load_pkmn(file, line, &nread, &(character->pkmns));
        if (my_strcmp(line, "-item") == 1)
            load_item(file, line, &nread, &(character->items));
        analyse_line_character(line, character);
    }
    if (line != NULL)
        free(line);
    fclose(file);
    return (character);
}

character_t *load_character(char *path, game_object_list_t **list)
{
    character_t *character = get_character(path, list);

    if (character == NULL)
        return (NULL);
    character->anim.rects = characterRects[character->type];
    character->objective = character->pos;
    put_object_in_objects(list, (void *)(character), PLAYER, 3);
    return (character);
}
