/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_map
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "other_path.h"
#include "basics.h"
#include "game_object.h"
#include "overworld_rects.h"
#include "map_path.h"

char **read_map(char const *path)
{
    FILE *file = fopen(path, "r");
    char **map = NULL;
    char *line = NULL;
    size_t size = 0;
    ssize_t nread = 0;

    if (file == NULL)
        return (NULL);
    map = malloc(sizeof(char *));
    if (map == NULL)
        return (NULL);
    map[0] = NULL;
    while ((nread = getline(&line, &size, file)) != -1)
        map = add_str_to_array(map, my_strdup(line));
    if (line != NULL)
        free(line);
    for (int i = 0; map[i]; i++)
        if (my_strlen(map[i]) > 0)
            map[i][my_strlen(map[i]) - 1] = '\0';
    fclose(file);
    return (map);
}

void load_map(game_object_list_t **list, int arg)
{
    ground_info_t info;
    char **map = NULL;

    for (int i = 0; i < 6; i++) {
        map = read_map(mapspaths[arg][i]);
        info = infos[i+arg*6];
        if (map != NULL)
            put_map_in_grounds(list, map, info);
        free_word_array(map);
    }
    if (arg == 0) {
        map = read_map("maps/outdoors/speobjs");
        put_map_in_grounds_spe(list, map);
        free_word_array(map);
    }
}
