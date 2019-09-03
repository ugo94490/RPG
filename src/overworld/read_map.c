/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** read_map
*/

#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include "game_object.h"

void put_ground_in_objects(game_object_list_t **list, ground_t ground)
{
    game_object_list_t *element = malloc(sizeof(game_object_list_t));
    if (element == NULL)
        return;

    element->object = (void *)(&ground);
    element->type = GROUND;
    element->next = *list;
    *list = element;
}

ground_t create_col_ground(game_object_list_t **list, int rect, int x, int y)
{
    ground_t ground;

    ground.appearance = rect;
    ground.solid = 1;
    ground.pos.x = x*ground_width;
    ground.pos.y = y*ground_height;
    return (ground);
}

ground_t create_nocol_ground(game_object_list_t **list, int rect, int x, int y)
{
    ground_t ground;

    ground.appearance = rect;
    ground.solid = 0;
    ground.pos.x = x*ground_width;
    ground.pos.y = y*ground_height;
    return (ground);
}

void create_ground_from_char(game_object_list_t **list, char c, int x, int y)
{
    ground_t ground;

    if ((c > 'Z' || c < 'A') && (c > 'z' || c < 'a'))
        return;
    if (c >= 'A' && c <= 'Z')
        ground = create_col_ground(list, c-'A', x, y);
    if (c >= 'a' && c <= 'z')
        ground = create_nocol_ground(list, c-'a'+('Z'-'A'), x, y);
    put_ground_in_objects(ground);
}

void put_map_in_objects(game_object_list_t **list, char **map)
{
    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            create_object_from_char(list, map[y][x], x, y);
        }
    }
}

char **read_map(char const *path)
{
    FILE *file = fopen(path, "r");
    char **map;
    char *line;
    size_t size;
    ssize_t nread;

    if (file == NULL)
        return (NULL);
    map = malloc(sizeof(char *));
    if (map == NULL)
        return (NULL);
    map[0] = NULL;
    while ((nread = getline(&line, &size, file)) != -1)
        map = add_str_to_array(maze, my_strdup(line));
    if (line != NULL)
        free(line);
    for (int i = 0; map[i]; i++)
        if (my_strlen(map[i]) > 0)
            map[i][my_strlen(map[i]) - 1] = '\0';
    fclose(file);
    return (map);
}
