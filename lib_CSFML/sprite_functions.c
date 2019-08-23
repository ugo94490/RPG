/*
** EPITECH PROJECT, 2019
** CGraphical_programming
** File description:
** sprite functions
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"

void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy((*sprite).sprite);
    sfTexture_destroy((*sprite).texture);
}

sprite_t create_sprite(char *texturepath)
{
    sprite_t sprite;

    sprite.sprite = sfSprite_create();
    sprite.texture = sfTexture_createFromFile(texturepath, NULL);
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfFalse);
    return (sprite);
}
