/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_items
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

void put_item_in_list(item_list_t **list, item_t item, int qty)
{
    item_list_t *element = malloc(sizeof(item_list_t));

    if (element == NULL)
        return;
    element->next = *list;
    element->item = item;
    element->quantity = qty;
    *list = element;
}

void analyse_line_item(char *line, item_t *item, int *qty)
{
    char **words = my_str_to_word_array(line, ": \n");

    if (get_nb_words(words) < 2)
        return (free_word_array(words));
    if (my_strcmp(words[0], "number") == 1)
        item->number = my_getnbr(words[1]);
    if (my_strcmp(words[0], "quantity") == 1)
        *qty = my_getnbr(words[1]);
    if (my_strcmp(words[0], "factor") == 1)
        item->factor = my_getnbr(words[1]);
    if (my_strcmp(words[0], "type") == 1)
        item->type = my_getnbr(words[1]);
    free_word_array(words);
}

void load_item(FILE *file, char *line, ssize_t *nread, item_list_t **list)
{
    item_t item = {0, 0, 0};
    size_t size = 0;
    int qty = 0;

    do {
        *nread = getline(&line, &size, file);
        if (*nread == -1)
            break;
        line[*nread-1] = '\0';
        analyse_line_item(line, &item, &qty);
    } while (*nread != -1 && line[0] != '\0');
    if (line != NULL)
        free(line);
    put_item_in_list(list, item, qty);
}
