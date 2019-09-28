/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main loop for displaying text char by char
*/

#include <stdlib.h>
#include "text.h"
#include "my_rpg.h"
#include "basics.h"

static int check_event(sfEvent event, int flag, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if ((event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(window);
            return -1;
        } if ((event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyReturn))
            flag = 2;
    }
    return flag;
}

static char *get_all(char *str, char *tmp, int where)
{
    int nb = 0;
    int cpt = 0;
    char *new = malloc(sizeof(char) * my_strlen(str) + 1);

    for (; tmp[cpt] != '\0'; ++cpt) {
        new[cpt] = tmp[cpt];
        if (tmp[cpt] == '\n')
            nb++;
    }
    for (; nb < 2 && str[where] != '\0'; ++where) {
        new[cpt++] = str[where];
        if (str[where] == '\n')
            nb++;
    }
    new[cpt] = '\0';
    free(tmp);
    return new;
}

static char *draw_all(txt_t *text, setting_t set, int cpt)
{
    text->flag = 2;
    text->tmp = get_all(text->str, text->tmp, cpt);
    display(text->text, text->tmp, set.window, set.sprite);
    return text->tmp;
}

static int wait_event(txt_t *text, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &text->event)) {
        if ((text->event.type == sfEvtKeyPressed &&
        text->event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(window);
            return -1;
        }
        if ((text->event.type == sfEvtKeyPressed &&
        text->event.key.code == sfKeyReturn)) {
            text->flag = 3;
            return 1;
        }
    }
    return 0;
}

int loop(txt_t *text, setting_t set, int cpt, int opt)
{
    if (text->str == NULL)
        return -1;
    while (text->flag < 3) {
        text->flag = check_event(text->event, text->flag, set.window);
        if (text->flag == -1)
            return -1;
        if (text->flag < 2 && text->str[cpt] != '\0')
            cpt = check_cpt(text, cpt, set.window, set.sprite);
        else
            text->tmp = draw_all(text, set, cpt);
        if ((text->flag == 2 || text->str[cpt] == '\0') && opt != 0)
            while (wait_event(text, set.window) == 0);
        if ((text->flag == 2 || text->str[cpt] == '\0') && opt == 0)
            text->flag = 3;
        if (sfRenderWindow_isOpen(set.window) == 0)
            return -1;
    }
    return cpt;
}
