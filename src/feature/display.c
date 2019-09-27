/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** function display
*/

#include "my_rpg.h"

void display(sfText *text, char *str, sfRenderWindow *window, sfSprite *sprite)
{
    sfText_setString(text, str);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}
