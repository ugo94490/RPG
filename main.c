/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"

game_object *init_hud(char *path, int x, int y)
{
    sfVector2f position = {x, y};
    sfIntRect rect = {0, 203, 256, 203};
    game_object *hud = create_object(path, position, rect);
    sfVector2f scale = {2.365, 2.365};

    sfSprite_setScale(hud->sprite, scale);
    return (hud);
}

game_object *init_choice(char *path)
{
    sfIntRect rect = {0, 90, 216, 90};
    sfVector2f scale = {2.76, 3.05};
    sfVector2f position = {340, 537};
    game_object *choice = create_object(path, position, rect);

    sfSprite_setScale(choice->sprite, scale);
    return (choice);
}

game_object *init_little(char *path, sfVector2f position)
{
    sfIntRect rect = {0, 44, 78, 44};
    sfVector2f scale = {2.47, 2.47};
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
    if (prev.x <= 2.76)
        toggle = 0;
    if (prev.x >= 2.890)
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
    if (prev.x <= 2.40)
        toggle = 0;
    if (prev.x >= 2.535)
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
    if (prev.x <= 2.4)
        toggle = 0;
    if (prev.x >= 2.535)
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
    if (prev.x <= 2.4)
        toggle = 0;
    if (prev.x >= 2.535)
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

    if (vct.x >= 343 && vct.x <= 854 && vct.y >= 537 && vct.y <= 750) {
        ret = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            ret = 6;
    }
    if (vct.x >= 340 && vct.x <= 522 && vct.y >= 823 && vct.y <= 929)
        ret = 2;
    if (vct.x >= 548 && vct.x <= 730 && vct.y >= 842 && vct.y <= 948) {
        ret = 3;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            ret = 5;
    }
    if (vct.x >= 756 && vct.x <= 938 && vct.y >= 823 && vct.y <= 929)
        ret = 4;
    return (ret);
}

int atk_hud(sfRenderWindow *window)
{
    game_object *atk = init_hud("assets/pp_hud.png", 338, 480);

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
    game_object *hud = init_hud("assets/attack_hud.png", 338, 480);
    game_object *choice = init_choice("assets/game_menu.png");
    game_object *screen = init_hud("assets/combat_screen.png", 338, 0);
    game_object *text_box = init_hud("assets/text_combat.png", 338, 374);
    game_object *cercle = init_hud("assets/cercle.png", 338, 204);
    game_object *o_life = init_hud("assets/opponent_life.png", 338, 123);
    game_object *m_life = init_hud("assets/my_life.png", 659, 263);
    sfVector2f pos = {336, 825};
    sfVector2f pos1 = {544, 844};
    sfVector2f pos2 = {752, 825};
    game_object *little = init_little("assets/menu_selection.png", pos);
    game_object *sp_run = init_little("assets/menu_selection.png", pos1);
    game_object *sp_pkm = init_little("assets/menu_selection.png", pos2);
    sfClock *clock = sfClock_create();
    int menu = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, hud->sprite, NULL);
        sfRenderWindow_drawSprite(window, screen->sprite, NULL);
        sfRenderWindow_drawSprite(window, text_box->sprite, NULL);
        sfRenderWindow_drawSprite(window, cercle->sprite, NULL);
        sfRenderWindow_drawSprite(window, o_life->sprite, NULL);
        sfRenderWindow_drawSprite(window, m_life->sprite, NULL);
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
    destroy_object(screen);
    destroy_object(text_box);
    destroy_object(cercle);
    destroy_object(little);
    destroy_object(sp_run);
    destroy_object(sp_pkm);
    destroy_object(o_life);
    destroy_object(m_life);
    sfClock_destroy(clock);
    return (0);
}

int main(void)
{
    sfRenderWindow *window = create_window(1280, 960, "COMBAT RPG", 0);

    sfRenderWindow_setFramerateLimit(window, 60);
    combat(window);
    sfRenderWindow_destroy(window);
    return (0);
}
