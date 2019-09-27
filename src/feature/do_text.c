/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** do text
*/

#include <stdlib.h>
#include "text.h"
#include "my_rpg.h"
#include "graphics.h"
#include "basics.h"

static char *set_tmp(char *tmp)
{
    tmp = malloc(sizeof(char));
    if (tmp == NULL)
        return NULL;
    tmp[0] = '\0';
    return tmp;
}

static void display(sfText *text, char *str, sfRenderWindow *window,
sfSprite *sprite)
{
    sfText_setString(text, str);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
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

char *change_str(char *str)
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
    return new;
}

static char *last_line(char *tmp)
{
    int len = 0;
    int cpt = 0;
    char *new = malloc(sizeof(char) * my_strlen(tmp));

    if (new == NULL)
        return NULL;
    for (; tmp[len] != '\n' && tmp[len] != '\0'; ++len);
    if (tmp[len] != '\0')
        len++;
    for (; tmp[len] != '\0'; ++len)
        new[cpt++] = tmp[len];
    new[cpt] = '\0';
    return new;
}

static int update_cpt(txt_t *text, int cpt, int flag, int dif)
{
    if (flag != 1)
        cpt = dif + my_strlen(text->tmp);
    text->tmp = last_line(text->tmp);
    if (flag == 1)
        cpt = dif + my_strlen(text->tmp);
    return cpt;
}

#define FONT "assets/classic.ttf"

static txt_t set_text(txt_t *text, setting_t set, char *base, int opt)
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

static char *set_save(char *save, txt_t *text, sfRenderWindow *window,
sfSprite *sprite)
{
    if (save == NULL) {
        save = malloc(sizeof(char));
        if (save == NULL)
            return NULL;
        save[0] = '\0';
    }
    if (save == NULL)
        return NULL;
    if (save[0] != '\0') {
        text->flag = 1;
        display(text->text, save, window, sprite);
    }
    text->tmp = my_strdup(save);
    return save;
}

static char *destroy_free(txt_t *text, char *save)
{
    save = my_strdup(text->tmp);
    free(text->tmp);
    sfClock_destroy(text->clock);
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    return save;
}

int do_text(char *base, setting_t set, window_t *window, int opt)
{
    static int cpt = 0;
    static char *save = NULL;
    int dif = cpt;
    txt_t text = set_text(&text, set, base, opt);
    int flag = 0;

    save = set_save(save, &text, window->window, set.sprite);
    flag = text.flag;
    if (save == NULL || text.str == NULL || save == NULL)
        return -1;
    cpt = loop(&text, set, cpt, opt);
    if (cpt == -1)
        return -1;
    cpt = update_cpt(&text, cpt, flag, dif);
    save = destroy_free(&text, save);
    if (text.str[cpt] != '\0')
        return 0;
    save = NULL;
    cpt = 0;
    return 1;
}
