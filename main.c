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

game_object *init_little(char *path, sfVector2f position)
{
    sfIntRect rect = {0, 44, 78, 44};
    sfVector2f scale = {4.17, 4.17};
    game_object *choice = create_object(path, position, rect);

    sfSprite_setScale(choice->sprite, scale);
    return (choice);
}

int attack(game_object *sp, sfClock *clk, sfRenderWindow *window)
{
    sfTime time;
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
    sfRenderWindow_drawSprite(window, sp->sprite, NULL);
    return (0);
}

int bag(game_object *sp, sfClock *clk, sfRenderWindow *window)
{
    sfTime time;
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    if (prev.x <= 4.1)
        toggle = 0;
    if (prev.x >= 4.235)
        toggle = 1;
    if (time.microseconds >= 1000000) {
        if (toggle == 0) {
            position.x -= 0.2;
            position.y -= 0.25;
            prev.x += 0.005;
            prev.y += 0.005;
        }
        if (toggle == 1) {
            position.x += 0.2;
            position.y += 0.25;
            prev.x -= 0.005;
            prev.y -= 0.005;
        }
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window, sp->sprite, NULL);
    return (0);
}

int pkmn(game_object *sp, sfClock *clk, sfRenderWindow *window)
{
    sfTime time;
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    if (prev.x <= 4.1)
        toggle = 0;
    if (prev.x >= 4.235)
        toggle = 1;
    if (time.microseconds >= 1000000) {
        if (toggle == 0) {
            position.x -= 0.2;
            position.y -= 0.25;
            prev.x += 0.005;
            prev.y += 0.005;
        }
        if (toggle == 1) {
            position.x += 0.2;
            position.y += 0.25;
            prev.x -= 0.005;
            prev.y -= 0.005;
        }
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window, sp->sprite, NULL);
    return (0);
}

int run(game_object *sp, sfClock *clk, sfRenderWindow *window)
{
    sfTime time;
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    if (prev.x <= 4.1)
        toggle = 0;
    if (prev.x >= 4.235)
        toggle = 1;
    if (time.microseconds >= 1000000) {
        if (toggle == 0) {
            position.x -= 0.2;
            position.y -= 0.25;
            prev.x += 0.005;
            prev.y += 0.005;
        }
        if (toggle == 1) {
            position.x += 0.2;
            position.y += 0.25;
            prev.x -= 0.005;
            prev.y -= 0.005;
        }
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window, sp->sprite, NULL);
    return (0);
}

int mode(sfRenderWindow *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window);
    static int ret = 0;

    if (vct.x >= 8 && vct.x <= 872 && vct.y >= 96 && vct.y <= 456) {
        ret = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            ret = 6;
    }
    if (vct.x >= 4 && vct.x <= 312 && vct.y >= 580 && vct.y <= 760)
        ret = 2;
    if (vct.x >= 356 && vct.x <= 664 && vct.y >= 612 && vct.y <= 792) {
        ret = 3;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            ret = 5;
    }
    if (vct.x >= 708 && vct.x <= 1016 && vct.y >= 580 && vct.y <= 760)
        ret = 4;
    return (ret);
}

int atk_hud(sfRenderWindow *window)
{
    game_object *atk = init_hud("pp_hud.png");

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, atk->sprite, NULL);
        sfRenderWindow_display(window);
        event(window);
    }
    destroy_object(atk);
    return (0);
}

int combat(sfRenderWindow *window)
{
    game_object *hud = init_hud("attack_hud.png");
    game_object *choice = init_choice("game_menu.png");
    sfVector2f pos = {0, 585};
    sfVector2f pos1 = {350, 615};
    sfVector2f pos2 = {700, 585};
    game_object *little = init_little("menu_selection.png", pos);
    game_object *sp_run = init_little("menu_selection.png", pos1);
    game_object *sp_pkm = init_little("menu_selection.png", pos2);
    sfClock *clock = sfClock_create();
    int menu = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, hud->sprite, NULL);
        menu = mode(window);
        if (menu == 1)
            attack(choice, clock, window);
        if (menu == 2)
            bag(little, clock, window);
        if (menu == 3)
            run(sp_run, clock, window);
        if (menu == 4)
            pkmn(sp_pkm, clock, window);
        if (menu == 5)
            sfRenderWindow_close(window);
        if (menu == 6)
            atk_hud(window);
        sfRenderWindow_display(window);
        event(window);
    }
    destroy_object(choice);
    destroy_object(hud);
    sfClock_destroy(clock);
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
