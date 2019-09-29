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
    anim_t baseanim = {32, 0, 0, 0, 0, {0}, 0};

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
    character->quests = NULL;
    return (character);
}

void analyse_line_character(char *line, character_t *chr)
{
    char **ws = my_str_to_word_array(line, ": \n");

    if (get_nb_words(ws) < 2)
        return (free_word_array(ws));
    if (my_strcmp(ws[0], "type") == 1 && my_getnbr(ws[1]) <= 1)
        chr->type = my_getnbr(ws[1]);
    my_strcmp(ws[0], "world") == 1 ? chr->world = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "music") == 1 ? chr->music = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "direction") == 1 ? chr->direction = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "posx") == 1 ? chr->pos.x = my_getnbr(ws[1]) : 0;
    my_strcmp(ws[0], "posy") == 1 ? chr->pos.y = my_getnbr(ws[1]) : 0;
    free_word_array(ws);
}

character_t *get_character(char *path)
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
    character_t *character = get_character(path);

    if (character == NULL)
        return (NULL);
    character->anim.rects = characterRects[character->type];
    character->objective = character->pos;
    put_object_in_objects(list, (void *)(character), PLAYER, 4);
    return (character);
}
