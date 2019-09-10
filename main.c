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

    return (hud);
}

game_object *init_choice(char *path)
{
    sfIntRect rect = {0, 90, 216, 90};
    sfVector2f position = {340, 537};
    game_object *choice = create_object(path, position, rect);

    return (choice);
}

game_object *init_little(char *path, int x, int y)
{
    sfIntRect rect = {0, 44, 78, 44};
    sfVector2f position = {x, y};
    game_object *choice = create_object(path, position, rect);

    return (choice);
}

int attack(game_object *sp, sfClock *clk, sfRenderWindow *window)
{
    sfTime time;
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    if (prev.x <= 1)
        toggle = 0;
    if (prev.x >= 1.04)
        toggle = 1;
    if (time.microseconds >= 1000000) {
        if (toggle == 0) {
            position.x -= 0.47;
            position.y -= 0.25;
            prev.x += 0.002;
            prev.y += 0.002;
        }
        if (toggle == 1) {
            position.x += 0.47;
            position.y += 0.25;
            prev.x -= 0.002;
            prev.y -= 0.002;
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
    if (prev.x <= 1)
        toggle = 0;
    if (prev.x >= 1.04)
        toggle = 1;
    if (time.microseconds >= 1000000) {
        if (toggle == 0) {
            position.x -= 0.35;
            position.y -= 0.25;
            prev.x += 0.003;
            prev.y += 0.003;
        }
        if (toggle == 1) {
            position.x += 0.35;
            position.y += 0.25;
            prev.x -= 0.003;
            prev.y -= 0.003;
        }
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window, sp->sprite, NULL);
    return (0);
}

int mode(sfRenderWindow *window, int flag)
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
        if (sfMouse_isButtonPressed(sfMouseLeft) && flag != 6)
            ret = 5;
    }
    if (vct.x >= 756 && vct.x <= 938 && vct.y >= 823 && vct.y <= 929)
        ret = 4;
    return (ret);
}

int cancel(sfRenderWindow *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window);
    int ret = 2;

    if (vct.x >= 358 && vct.x <= 921 && vct.y >= 845 && vct.y <= 954) {
        ret = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            ret = 1;
    }
    return (ret);
}

int atk_hud(sfRenderWindow *window, game_object *screen, game_object *text_box, game_object *cercle, game_object *o_life, game_object *m_life)
{
    game_object *atk = init_hud("assets/pp_hud.png", 338, 480);
    static int mode = 0;

    while (sfRenderWindow_isOpen(window)) {
        mode = cancel(window);
        if (mode == 1) {
            mode = 0;
            break;
        }
        sfRenderWindow_drawSprite(window, atk->sprite, NULL);
        sfRenderWindow_drawSprite(window, screen->sprite, NULL);
        sfRenderWindow_drawSprite(window, text_box->sprite, NULL);
        sfRenderWindow_drawSprite(window, cercle->sprite, NULL);
        sfRenderWindow_drawSprite(window, o_life->sprite, NULL);
        sfRenderWindow_drawSprite(window, m_life->sprite, NULL);
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
    game_object *little = init_little("assets/menu_selection.png", 336, 825);
    game_object *sp_run = init_little("assets/menu_selection.png", 544, 844);
    game_object *sp_pkm = init_little("assets/menu_selection.png", 752, 825);
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
        menu = mode(window, menu);
        if (menu == 1)
            attack(choice, clock, window);
        if (menu == 2)
            bag(little, clock, window);
        if (menu == 3)
            bag(sp_run, clock, window);
        if (menu == 4)
            bag(sp_pkm, clock, window);
        if (menu == 5)
            sfRenderWindow_close(window);
        if (menu == 6)
            atk_hud(window, screen, text_box, cercle, o_life, m_life);
        printf("%d\n", menu);
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
