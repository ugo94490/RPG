/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"

game_object *init_hud(char *path)
{
    sfVector2f position = {0, 0};
    sfIntRect rect = {0, 203, 256, 203};
    game_object *hud = create_object(path, position, rect);
    sfVector2f scale = {4, 4};

    sfSprite_setScale(hud->sprite, scale);
    return (hud);
}

game_object *init_choice(char *path)
{
    sfIntRect rect = {0, 90, 216, 90};
    sfVector2f scale = {4.665, 5.16};
    sfVector2f position = {8, 96};
    game_object *choice = create_object(path, position, rect);

    sfSprite_setScale(choice->sprite, scale);
    return (choice);
}

int change_scale(game_object *sp, sfClock *clk, sfTime time)
{
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    if (prev.x <= 4.665)
        toggle = 0;
    if (prev.x >= 4.80)
        toggle = 1;
    if (time.microseconds >= 1000000) {
        if (toggle == 0) {
            position.x -= 0.4;
            position.y -= 0.25;
            prev.x += 0.005;
            prev.y += 0.005;
        }
        if (toggle == 1) {
            position.x += 0.4;
            position.y += 0.25;
            prev.x -= 0.005;
            prev.y -= 0.005;
        }
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    return (0);
}

int combat(sfRenderWindow *window)
{
    game_object *hud = init_hud("attack_hud.png");
    game_object *choice = init_choice("game_menu.png");
    sfClock *clock = sfClock_create();
    sfTime time;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, hud->sprite, NULL);
        sfRenderWindow_drawSprite(window, choice->sprite, NULL);
        change_scale(choice, clock, time);
        sfRenderWindow_display(window);
        event(window);
    }
    destroy_object(hud);
    return (0);
}

int main(void)
{
    sfRenderWindow *window = create_window(1024, 812, "COMBAT RPG", 0);

    sfRenderWindow_setFramerateLimit(window, 60);
    combat(window);
    sfRenderWindow_destroy(window);
    return (0);
}
