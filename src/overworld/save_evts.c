/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_evt
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graphics.h"
#include "overworld.h"

void save_evts(evt_list_t *evts)
{
    FILE *file = fopen("save/actualsave/tempevts", "w");

    if (file == NULL)
        return;
    sub_save_evts((void *)file, evts);
    fclose(file);
}
