/*
** EPITECH PROJECT, 2019
** CGraphical programming
** File description:
** functions using SFML/graphics lib
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct sprite_s
{
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct text_s
{
    sfText *text;
    sfFont *font;
    char *string;
    sfVector2f pos;
    int alive;
} text_t;

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode mode;
    char *title;
    sfVector2f scale;
} window_t;

sprite_t create_sprite(char *texturepath);
void destroy_sprite(sprite_t *sprite);
text_t create_text(char *basetext, char *basefont, int basesize, sfVector2f ps);
window_t create_window(int resx, int resy, int colours, char *title);
sfIntRect create_int_rect(int top, int left, int width, int height);
sfVector2i create_vector2i(int x, int y);
sfVector2f create_vector2f(float x, float y);
void change_mode(window_t *window, int resx, int resy, int colours);
void change_text(char *newtext, text_t *text);
void destroy_text(text_t *text);

#endif
