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

static char *destroy_free(txt_t *text, char *save)
{
    if (save != NULL)
        free(save);
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
    cpt = loop(&text, set, cpt, opt);
    if (save == NULL || cpt == -1 || save == NULL)
        return -1;
    cpt = update_cpt(&text, cpt, flag, dif);
    save = destroy_free(&text, save);
    if (text.str[cpt] != '\0')
        return 0;
    free(save);
    save = NULL;
    cpt = 0;
    return 1;
}
