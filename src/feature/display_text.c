/*
** EPITECH PROJECT, 2019
** MUl_my_rpg_2018
** File description:
** display text
*/

#include "text.h"
#include "basics.h"
#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static char *my_strappend(char *str, char c)
{
    int cpt = 0;
    char *new = NULL;

    new = malloc(sizeof(char) * my_strlen(str) + 2);
    for (; str[cpt] != '\0'; ++cpt)
        new[cpt] = str[cpt];
    new[cpt++] = c;
    new[cpt] = '\0';
    return new;
}

int check_event(sfEvent event, int flag, sfRenderWindow *window)
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

static void display(sfText *text, char *str, sfRenderWindow *window, sfSprite *sprite)
{
    sfText_setString(text, str);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}

static char *get_all(char *str, char *tmp, int where)
{
    int nb = 0;
    int cpt = 0;
    char *new = malloc(sizeof(char) * my_strlen(str));

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

static float get_seconds(sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return seconds;
}

static char *set_tmp(char *tmp)
{
    tmp = malloc(sizeof(char));
    if (tmp == NULL)
        return NULL;
    tmp[0] = '\0';
    return tmp;
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

static int wait_event(text_t *text, sfRenderWindow *window)
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

static char *draw_all(text_t *text, char *tmp, setting_t set, int cpt)
{
    text->flag = 2;
    tmp = get_all(text->str, tmp, cpt);
    display(text->text, tmp, set.window, set.sprite);
    return tmp;
}

static text_t set_text(text_t *text, int size, sfVector2f pos, char *base)
{
    text->tmp = NULL;
    text->tmp = set_tmp(text->tmp);
    text->str = malloc(sizeof(char) * my_strlen(base) + 1);
    if (text->str == NULL || text->tmp == NULL)
        return (*text);
    text->clock = sfClock_create();
    text->flag = 0;
    text->font = sfFont_createFromFile("../UGO/classic.ttf");
    text->text = sfText_create();
    text->str = strcpy(text->str, base);
    text->str = change_str(text->str);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, pos);
    sfText_setColor(text->text, sfBlack);
    sfText_setCharacterSize(text->text, size);
    return (*text);
}

static int check_cpt(text_t *text, int cpt, sfRenderWindow *window, sfSprite *sprite)
{
    text->seconds = get_seconds(text->clock);
    if (text->seconds > 0.03) {
        sfClock_restart(text->clock);
        text->tmp = my_strappend(text->tmp, text->str[cpt]);
        if (text->str[cpt] == '\n')
            text->flag++;
        display(text->text, text->tmp, window, sprite);
        cpt++;
    }
    return cpt;
}

static char *set_save(char *save, text_t *text, sfRenderWindow *window, sfSprite *sprite)
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

static int update_cpt(text_t *text, int cpt, int flag, int dif)
{
    if (flag != 1)
        cpt = dif + my_strlen(text->tmp);
    text->tmp = last_line(text->tmp);
    if (flag == 1)
        cpt = dif + my_strlen(text->tmp);
    return cpt;
}

static int loop(text_t *text, setting_t set, int cpt)
{
    while (text->flag < 3) {
        text->flag = check_event(text->event, text->flag, set.window);
        if (text->flag == -1)
            return -1;
        if (text->flag < 2 && text->str[cpt] != '\0')
            cpt = check_cpt(text, cpt, set.window, set.sprite);
        else
            text->tmp = draw_all(text, text->tmp, set, cpt);
        if (text->flag == 2 || text->str[cpt] == '\0')
            while (wait_event(text, set.window) == 0);
        if (sfRenderWindow_isOpen(set.window) == 0)
            return -1;
    }
    return cpt;
}

static char *destroy_free(text_t *text, char *save)
{
    save = my_strdup(text->tmp);
    free(text->tmp);
    sfClock_destroy(text->clock);
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    return save;
}

static int do_text(char *base, setting_t set, sfRenderWindow *window, sfSprite *sprite)
{
    static int cpt = 0;
    static char *save = NULL;
    int dif = cpt;
    text_t text = set_text(&text, set.size, set.pos, base);
    int flag = 0;

    save = set_save(save, &text, window, sprite);
    flag = text.flag;
    if (save == NULL || text.str == NULL || save == NULL)
        return -1;
    cpt = loop(&text, set, cpt);
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

static setting_t set_setting(sfVector2f pos, int size, sfRenderWindow *window, sfSprite *sprite)
{
    setting_t set;

    set.size = size;
    set.pos.x = pos.x + 20;
    set.pos.y = pos.y + 25;
    set.window = window;
    set.sprite = sprite;
    return set;
}

int display_text(char *base, sfVector2f pos, sfRenderWindow *window)
{
    setting_t set;
    int flag = 0;
    sfIntRect rec = {0, 0, 0, 0};
    game_object *spr = create_object("../assets/text_combat.png", pos, rec);

    set = set_setting(pos, 17, window, spr->sprite);
    while (sfRenderWindow_isOpen(window) == 1 && flag != 1) {
        sfSprite_setPosition(spr->sprite, pos);
        sfRenderWindow_drawSprite(window, spr->sprite, NULL);
        if (flag == 0)
            flag = do_text(base, set, window, spr->sprite);
        if (flag == -1)
            break;
        sfRenderWindow_display(window);
    }
    destroy_object(spr);
    return 0;
}
