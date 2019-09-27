/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_items
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

static char *sub_save_item(FILE *file, char *nbr, item_t item)
{
    fwrite("number:", 1, 7, file);
    nbr = my_itoa(item.number, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("factor:", 1, 7, file);
    nbr = my_itoa(item.factor, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    return (nbr);
}

static void save_item(FILE *file, item_t item, int quantity)
{
    char *nbr = malloc(sizeof(char) * 20);
    char *cpy = nbr;

    if (nbr == NULL || file == NULL)
        return;
    fwrite("-item\n", 1, 6, file);
    fwrite("quantity:", 1, 9, file);
    nbr = my_itoa(quantity, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    fwrite("type:", 1, 5, file);
    nbr = my_itoa(item.type, nbr);
    fwrite(nbr, 1, my_strlen(nbr), file);
    fwrite("\n", 1, 1, file);
    nbr = sub_save_item(file, nbr, item);
    fwrite("\n", 1, 1, file);
    free(cpy);
}

void save_items(void *file, item_list_t *items)
{
    if (items != NULL && items->next != NULL)
        save_items(file, items->next);
    if (items != NULL)
        save_item((FILE *)(file), items->item, items->quantity);
}
