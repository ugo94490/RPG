/*
** EPITECH PROJECT, 2019
** CGraphical programming
** File description:
** text_funtcions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graphics.h"

int my_strlen(char const *str);

text_t create_text(char *basetext, char *basefont, int basesize, sfVector2f ps)
{
    text_t text;
    int i = 0;

    text.string = malloc(sizeof(char) * my_strlen(basetext) + 1);
    for (; basetext[i] != '\0'; i++)
        text.string[i] = basetext[i];
    text.string[i] = '\0';
    text.text = sfText_create();
    text.pos = ps;
    sfText_setString(text.text, basetext);
    text.font = sfFont_createFromFile(basefont);
    sfText_setFont(text.text, text.font);
    sfText_setCharacterSize(text.text, basesize);
    sfText_setPosition(text.text, ps);
    text.alive = 1;
    return (text);
}

static void text_free(text_t *text)
{
    free(text->string);
}

void destroy_text(text_t *text)
{
    free(text->string);
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
}

void change_text(char *newtext, text_t *text)
{
    text_free(text);
    text->string = newtext;
    sfText_setString(text->text, text->string);
}
