/*
** EPITECH PROJECT, 2019
** CGraphical_programming
** File description:
** rect_functions.c
*/

#include <SFML/Graphics.h>

sfIntRect create_int_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfVector2i create_vector2i(int x, int y)
{
    sfVector2i vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2f create_vector2f(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}
