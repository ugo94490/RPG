/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** config struct text_t
*/

#include <stdlib.h>
#include "text.h"
#include "basics.h"

#define FONT "assets/classic.ttf"

static char *set_tmp(char *tmp)
{
    tmp = malloc(sizeof(char));
    if (tmp == NULL)
        return NULL;
    tmp[0] = '\0';
    return tmp;
}

static char *replace_str(char *new, int flag, int tmp)
{
    tmp = tmp * flag;
    for (int check = flag; check == flag; --tmp)
        if (new[tmp] == ' ') {
            new[tmp] = '\n';
            flag++;
        }
    return new;
}

static char *change_str(char *str)
{
    int tmp = 0;
    int where = 0;
    int flag = 1;
    char *new = malloc(sizeof(char) * my_strlen(str) * 2);

    for (int cpt = 0; str[cpt] != '\0'; ++tmp) {
        new[where++] = str[cpt];
        if (str[cpt++] == '\n')
            tmp = 0;
        if (tmp == 35) {
            new = replace_str(new, flag, tmp);
            flag++;
            tmp = 0;
        }
    }
    new[where++] = '\n';
    new[where] = '\0';
    free(str);
    return new;
}

txt_t set_text(txt_t *text, setting_t set, char *base, int opt)
{
    text->tmp = NULL;
    text->tmp = set_tmp(text->tmp);
    text->str = malloc(sizeof(char) * my_strlen(base) + 1);
    if (text->str == NULL || text->tmp == NULL)
        return (*text);
    text->clock = sfClock_create();
    text->flag = 0;
    text->font = sfFont_createFromFile(FONT);
    text->text = sfText_create();
    text->str = strcpy(text->str, base);
    text->str = change_str(text->str);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, set.pos);
    sfText_setColor(text->text, sfBlack);
    sfText_setCharacterSize(text->text, set.size);
    return (*text);
}
