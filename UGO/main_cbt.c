/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"
#include "pkmn.h"
#include "tab.h"
#include <SFML/Audio.h>
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

static int pause_time(float sec)
{
    sfTime time = sfTime_Zero;
    sfClock *clock = sfClock_create();

    while (1) {
        time = sfClock_getElapsedTime(clock);
        if ((time.microseconds / 1000000.0) > sec)
            break;
    }
    sfClock_destroy(clock);
    return (0);
}

game_object *init_hud(char *path, int x, int y, window_t *window)
{
    sfVector2f position = {x, y};
    sfIntRect rect = {0, 203, 256, 203};
    game_object *hud = create_object(path, position, rect, window);

    return (hud);
}

game_object *init_choice(char *path, window_t *window)
{
    sfIntRect rect = {0, 90, 216, 90};
    sfVector2f position = {340, 535};
    game_object *choice = create_object(path, position, rect, window);

    return (choice);
}

game_object *init_little(char *path, int x, int y, window_t *window)
{
    sfIntRect rect = {0, 44, 78, 44};
    sfVector2f position = {x, y};
    game_object *choice = create_object(path, position, rect, window);

    return (choice);
}

void add_attack(sfVector2f *prev, sfVector2f *position,
int flag, window_t *window)
{
    if (flag == 0) {
        position->x -= 0.47 * window->scale.x;
        position->y -= 0.25 * window->scale.y;
        prev->x += 0.002 * window->scale.x;
        prev->y += 0.002 * window->scale.y;
    }
    if (flag == 1) {
        position->x += 0.47 * window->scale.x;
        position->y += 0.25 * window->scale.y;
        prev->x -= 0.002 * window->scale.x;
        prev->y -= 0.002 * window->scale.y;
    }
}

void add_bag(sfVector2f *prev, sfVector2f *position, int flag, window_t *window)
{
    if (flag == 0) {
        position->x -= 0.35 * window->scale.x;
        position->y -= 0.25 * window->scale.y;
        prev->x += 0.003 * window->scale.x;
        prev->y += 0.003 * window->scale.y;
    }
    if (flag == 1) {
        position->x += 0.35 * window->scale.x;
        position->y += 0.25 * window->scale.y;
        prev->x -= 0.003 * window->scale.x;
        prev->y -= 0.003 * window->scale.y;
    }
}

int attack(game_object *sp, sfClock *clk, window_t *window)
{
    sfTime time;
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    (prev.x <= 1 * window->scale.x) ? toggle = 0 : 0;
    (prev.x >= 1.04 * window->scale.x) ? toggle = 1 : 0;
    if (time.microseconds >= 50000) {
        if (toggle == 0)
            add_attack(&prev, &position, 0, window);
        if (toggle == 1)
            add_attack(&prev, &position, 1, window);
        time = sfClock_restart(clk);
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window->window, sp->sprite, NULL);
    return (0);
}

int bag(game_object *sp, sfClock *clk, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(clk);
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    (prev.x <= 1 * window->scale.x) ? toggle = 0 : 0;
    (prev.x >= 1.04 * window->scale.x) ? toggle = 1 : 0;
    if (time.microseconds >= 50000) {
        if (toggle == 0)
            add_bag(&prev, &position, 0, window);
        if (toggle == 1)
            add_bag(&prev, &position, 1, window);
        time = sfClock_restart(clk);
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window->window, sp->sprite, NULL);
    return (0);
}

int display_cursor(window_t *win, misc_t *misc)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f pos1 = {pos.x, pos.y};

    sfSprite_setPosition(misc->sprite, pos1);
    sfRenderWindow_drawSprite(win->window, misc->sprite, NULL);
    return (0);
}

int next_mode(window_t *win, int flag, int ret, sfVector2i vct)
{
    if (vct.x >= 548 * win->scale.x && vct.x <= 730 * win->scale.x
    && vct.y >= 842 * win->scale.y && vct.y <= 948 * win->scale.y) {
        ret = 3;
        if (sfMouse_isButtonPressed(sfMouseLeft) && flag != 6) {
            pause_time(0.3);
            ret = 5;
        }
    }
    return (ret);
}

int mode(window_t *win, int flag)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(win->window);
    int ret = 0;

    if (vct.x >= 343 * win->scale.x && vct.x <= 936 * win->scale.x &&
    vct.y >= 537 * win->scale.y && vct.y <= 812 * win->scale.x) {
        ret = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            pause_time(0.3) == 0 ? ret = 6 : 0;
    }
    (vct.x >= 340 * win->scale.x && vct.x <= 522 * win->scale.x && vct.y >=
    823 * win->scale.y && vct.y <= 929 * win->scale.y) ? ret = 2 : 0;
    ret = next_mode(win, flag, ret, vct);
    (vct.x >= 756 * win->scale.x && vct.x <= 938 * win->scale.x && vct.y >=
    823 * win->scale.y && vct.y <= 929 * win->scale.y) ? ret = 4 : 0;
    return (ret);
}

int destroy_font(text_t *stat, int lim)
{
    for (int i = 0; i < lim; i++) {
        sfText_destroy(stat[i].text);
        sfFont_destroy(stat[i].font);
    }
    free(stat);
    return (0);
}

int cancel(window_t *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    int ret = 2;

    if (vct.x >= 358 && vct.x <= 921 && vct.y >= 845 && vct.y <= 954) {
        ret = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ret = 1;
            pause_time(0.3);
        }
    }
    return (ret);
}

int display_game(game_object **tab, window_t *window, int pos, int start)
{
    for (int i = start; i < pos + 1; i++)
        sfRenderWindow_drawSprite(window->window, tab[i]->sprite, NULL);
    return (0);
}

int attack_box(pkmn_list_t *linked, window_t *window,
int nb, game_object **tab)
{
    char *str = malloc(sizeof(char));
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};

    *str = 0;
    str = my_strcat(str, name[linked->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[nb]);
    str = my_strcat(str, phr[1]);
    pause_time(0.1);
    display_text(str, pos, window, 0);
    sfRenderWindow_clear(window->window, sfBlack);
    display_game(tab, window, 8, 0);
    free(str);
    return (0);
}

int get_atk(pkmn_list_t *linked, int nb)
{
    int ret = -1;

    for (int i = 0; atk[i]; i++)
        if (my_strcmp(atk[i], atk_name[linked->pokemon.atks[nb].number])
            == 0)
            ret = i;
    return (ret);
}

int display_stat(window_t *window, text_t *stat, int lim)
{
    for (int i = 0; i < lim; i++)
        sfRenderWindow_drawText(window->window, stat[i].text, NULL);
    return (0);
}

int attack_anim(misc_t *misc, window_t *window, pkmn_list_t *linked,
int nb)
{
    sfIntRect rect = {0, 0, 605, 340};
    sfVector2f pos = {340, 30};
    int nb_atk = get_atk(linked, nb);
    game_object *sprite;
    sfClock *clock;
    sfTime time;

    if (nb_atk == -1)
        return (0);
    display_game(misc->tab, window, 8, 0);
    display_stat(window, misc->stat, 8);
    sprite = create_object(asset_atk[nb_atk], pos, rect, window);
    clock = sfClock_create();
    sfSprite_setTextureRect(sprite->sprite, rect);
    while (sfRenderWindow_isOpen(window->window)) {
        time = sfClock_getElapsedTime(clock);
        if (rect.left >= 1210)
            break;
        if (time.microseconds >= 400000) {
            sfRenderWindow_clear(window->window, sfBlack);
            display_game(misc->tab, window, 3, 0);
            display_game(misc->tab, window, 7, 6);
            sfSprite_setTextureRect(sprite->sprite, rect);
            sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
            display_game(misc->tab, window, 5, 4);
            display_game(misc->tab, window, 8, 8);
            display_stat(window, misc->stat, 8);
            rect.top += 340;
            rect.top >= 2382 ? rect.left += 605 : 0;
            time = sfClock_restart(clock);
        }
        sfRenderWindow_display(window->window);
    }
    display_game(misc->tab, window, 8, 0);
    display_stat(window, misc->stat, 8);
    destroy_obj(sprite);
    sfClock_destroy(clock);
    return (0);
}

misc_t init_atk(game_object **tab, text_t *stat)
{
    misc_t misc;

    misc.tab = tab;
    misc.stat = stat;
    return (misc);
}

int attack_one(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[0].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[0].number, misc->tab);
    attack_anim(misc, window, linked, 0);
    return (1);
}

int attack_two(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[1].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[1].number, misc->tab);
    attack_anim(misc, window, linked, 1);
    return (1);
}

int attack_three(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[2].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[2].number, misc->tab);
    attack_anim(misc, window, linked, 2);
    return (1);
}

int attack_four(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    npc->pokemon.health -= ((linked->pokemon.level * 0.4 + 2) *
    linked->pokemon.atks[3].power * linked->pokemon.atq) /
    (linked->pokemon.def * 50) + 2;
    attack_box(linked, window, linked->pokemon.atks[3].number, misc->tab);
    attack_anim(misc, window, linked, 3);
    return (1);
}

int detect_one(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);

    if (linked->pokemon.atks[0].number != -1 && atk_pos[0].x *
        window->scale.x<= vct.x && (atk_pos[0].x + 293) * window->scale.x >=
        vct.x && atk_pos[0].y * window->scale.y <= vct.y && (atk_pos[0].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_one(window, linked, misc, npc));
    if (linked->pokemon.atks[1].number != -1 && atk_pos[1].x *
        window->scale.x<= vct.x && (atk_pos[1].x + 293) * window->scale.x >=
        vct.x && atk_pos[1].y * window->scale.y <= vct.y && (atk_pos[1].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_two(window, linked, misc, npc));
    return (0);
}

int detect_two(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);

    if (linked->pokemon.atks[2].number != -1 && atk_pos[2].x *
        window->scale.x<= vct.x && (atk_pos[2].x + 293) * window->scale.x >=
        vct.x && atk_pos[2].y * window->scale.y <= vct.y && (atk_pos[2].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_three(window, linked, misc, npc));
    if (linked->pokemon.atks[3].number != -1 && atk_pos[3].x *
        window->scale.x<= vct.x && (atk_pos[3].x + 293) * window->scale.x >=
        vct.x && atk_pos[3].y * window->scale.y <= vct.y && (atk_pos[3].y + 130)
        * window->scale.y >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_four(window, linked, misc, npc));
    return (0);
}

int launch(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    int ret = 0;

    ret = detect_one(window, linked, misc, npc);
    if (ret == 1)
        return (ret);
    ret = detect_two(window, linked, misc, npc);
    if (ret == 1)
        return (ret);
    return (0);
}

char *itoa_dup(int nb)
{
    char *nbr = malloc(sizeof(char) * (my_int(nb) + 1));

    nbr = my_itoa(nb, nbr);
    return (nbr);
}

game_object **init_box(pkmn_list_t *linked, window_t *window)
{
    game_object **tab = malloc(sizeof(game_object *) * 5);
    sfIntRect rc = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        if (linked->pokemon.atks[i].number != -1)
            tab[i] = create_object("assets/attack.png", atk_pos[i], rc, window);
        else
            tab[i] = create_object("assets/vide.png", atk_pos[i], rc, window);
    }
    tab[4] = NULL;
    return (tab);
}

int destroy_tab(game_object **tab)
{
    for (int i = 0; tab[i]; i++)
        destroy_obj(tab[i]);
    free(tab);
    return (0);
}

int display_box(game_object **box, window_t *window)
{
    for (int i = 0; box[i]; i++)
        sfRenderWindow_drawSprite(window->window, box[i]->sprite, NULL);
    return (0);
}

int misc_atk(misc_t *misc, game_object **box, window_t *window,
game_object *atk)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, atk->sprite, NULL);
    display_game(misc->tab, window, 7, 1);
    display_box(box, window);
    display_cursor(window, misc);
    event(window);
    return (0);
}

text_t *init_name(pkmn_list_t *linked, window_t *window)
{
    text_t *stat = malloc(sizeof(text_t) * 9);
    int size = 15 * window->scale.x;
    sfVector2f tmp = {0, 0};
    sfVector2f tmp2 = {0, 0};

    for (int i = 0; i < 4; i++) {
        tmp.x = atk_txt[i].x * window->scale.x;
        tmp.y = atk_txt[i].y * window->scale.y;
        tmp2.x = atk_txt[i + 4].x * window->scale.x;
        tmp2.y = atk_txt[i + 4].y * window->scale.y;
        stat[i] = create_text(atk_name[linked->pokemon.atks[i].number],
        "assets/classic.ttf", size, tmp);
        stat[i + 4] = create_text(itoa_dup(linked->pokemon.atks[i].power),
        "assets/classic.ttf", size, tmp2);
        sfText_setFillColor(stat[i].text, sfBlack);
        sfText_setFillColor(stat[i + 4].text, sfBlack);
    }
    return (stat);
}

int destroy_atkhud(text_t *name_pow, game_object **box, game_object *atk,
int flag)
{
    destroy_font(name_pow, 9 - 1);
    destroy_tab(box);
    destroy_obj(atk);
    return (flag);
}

int disp_txt(window_t *window, text_t *stat, text_t *name_pow)
{
    display_stat(window, stat, 8);
    display_stat(window, name_pow, 9 - 1);
    return (0);
}

int atk_hud(window_t *window, pkmn_list_t *linked,
misc_t *misc, pkmn_list_t *npc)
{
    game_object *atk = init_hud("assets/pp_hud.png", 338, 480, window);
    game_object **box = init_box(linked, window);
    text_t *name_pow = init_name(linked, window);
    int ret = 0;
    static int mode = 0;
    while (sfRenderWindow_isOpen(window->window)) {
        mode = cancel(window);
        if (mode == 1) {
            mode = 0;
            break;
        }
        misc_atk(misc, box, window, atk);
        disp_txt(window, misc->stat, name_pow);
        if (launch(window, linked, misc, npc) == 1) {
            ret = 12;
            break;
        }
        sfRenderWindow_display(window->window);
    }
    return (destroy_atkhud(name_pow, box, atk, ret));
}

game_object **init_object(window_t *window, pkmn_list_t *pkm, pkmn_list_t *npc)
{
    game_object **tab = malloc(sizeof(game_object *) * 13);
    sfVector2f pos = {420, 218};
    sfVector2f pos2 = {720, 85};
    sfIntRect rect = {0, 0, 0, 0};

    tab[0] = init_hud("assets/attack_hud.png", 338, 480, window);
    tab[8] = init_choice("assets/game_menu.png", window);
    tab[1]= init_hud("assets/combat_screen.png", 338, 0, window);
    tab[3] = init_hud("assets/text_combat.png", 338, 374, window);
    tab[2] = init_hud("assets/cercle.png", 338, 204, window);
    tab[5] = init_hud("assets/opponent_life.png", 338, 123, window);
    tab[4] = init_hud("assets/my_life.png", 659, 263, window);
    tab[9] = init_little("assets/m_sel.png", 341, 825, window);
    tab[10] = init_little("assets/m_sel.png", 549, 844, window);
    tab[11] = init_little("assets/m_sel.png", 757, 825, window);
    tab[6] = create_object(front_pkm[npc->pokemon.number], pos2, rect, window);
    tab[7] = create_object(back_pkm[pkm->pokemon.number], pos, rect, window);
    tab[12] = NULL;
    return (tab);
}

int check_flag(misc_t *misc, window_t *win,
pkmn_list_t *linked, pkmn_list_t *npc)
{
    if (misc->flag == 1)
        attack(misc->tab[8], misc->clock, win);
    if (misc->flag == 2)
        bag(misc->tab[9], misc->clock, win);
    if (misc->flag == 3)
        bag(misc->tab[10], misc->clock, win);
    if (misc->flag == 4)
        bag(misc->tab[11], misc->clock, win);
    if (misc->flag == 5)
        return (84);
    if (misc->flag == 6) {
        return (atk_hud(win, linked, misc, npc));
    }
    return (misc->flag);
}

text_t *init_txt(window_t *window)
{
    text_t *stat = malloc(sizeof(text_t) * 8);
    int size = 15 * window->scale.x;
    sfVector2f tmp = {0, 0};

    for (int i = 0; i < 8; i++) {
        tmp.x = pos_txt[i].x * window->scale.x;
        tmp.y = pos_txt[i].y * window->scale.y;
        stat[i] = create_text("init", "assets/classic.ttf", size, tmp);
        sfText_setFillColor(stat[i].text, sfBlack);
    }
    return (stat);
}

text_t *change_pos(pkmn_list_t *node, window_t *window, pkmn_list_t *npc)
{
    text_t *stat = init_txt(window);

    change_text(itoa_dup(node->pokemon.max_health), &stat[0]);
    change_text(itoa_dup(node->pokemon.health), &stat[1]);
    change_text(itoa_dup(node->pokemon.level), &stat[2]);
    change_text(itoa_dup(npc->pokemon.level), &stat[3]);
    change_text(my_strdup(name[npc->pokemon.number]), &stat[4]);
    change_text(my_strdup(name[node->pokemon.number]), &stat[5]);
    change_text(itoa_dup(npc->pokemon.health), &stat[6]);
    change_text(itoa_dup(npc->pokemon.max_health), &stat[7]);
    return (stat);
}

game_object **init_player(window_t *window, int flag)
{
    game_object **tmp = malloc(sizeof(game_object *) * 2);
    sfIntRect rect = {0, 0, 170, 148};
    sfIntRect rect2 = {0, 0, 47, 109};
    sfVector2f pos = {380, 226};
    sfVector2f pos2 = {740, 30};

    tmp[0] = create_object(player[flag], pos, rect, window);
    tmp[1] = create_object("assets/rival_two.png", pos2, rect2, window);
    return (tmp);
}

int disp_sprite(game_object **tab, window_t *window,
game_object **character, npc_t *npc)
{
    display_game(tab, window, 5, 0);
    sfRenderWindow_drawSprite(window->window, character[0]->sprite, NULL);
    if (npc->type != -1)
        sfRenderWindow_drawSprite(window->window, character[1]->sprite, NULL);
    sfRenderWindow_display(window->window);
    return (0);
}

int free_character(game_object **character)
{
    destroy_obj(character[0]);
    destroy_obj(character[1]);
    free(character);
    return (0);
}

int animation(window_t *window, game_object **tab, int flag, npc_t *npc)
{
    game_object **character = init_player(window, flag);
    sfClock *clock = sfClock_create();
    sfTime time;
    int count = 0;
    display_game(tab, window, 5, 0);
    while (count != 5) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds >= 400000) {
            sfRenderWindow_clear(window->window, sfBlack);
            character[0]->rect.left += 173;
            sfSprite_setTextureRect(character[0]->sprite, character[0]->rect);
            disp_sprite(tab, window, character, npc);
            time = sfClock_restart(clock);
            count++;
        }
    }
    sfRenderWindow_clear(window->window, sfBlack);
    free_character(character);
    sfClock_destroy(clock);
    return (0);
}

int riposte(npc_t *npc, window_t *window, game_t *game)
{
    int nb = rand() % 3;
    char *str = NULL;
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};

    str = malloc(sizeof(char));
    str[0] = '\0';
    str = my_strcat(str, name[npc->pkmns->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[npc->pkmns->pokemon.atks[nb].number]);
    str = my_strcat(str, phr[1]);
    game->character->pkmns->pokemon.health -= ((npc->pkmns->pokemon.level *
    0.4 + 2) * npc->pkmns->pokemon.atks[3].power * npc->pkmns->pokemon.atq)
    / (npc->pkmns->pokemon.def * 50) + 2;
    if (game->character->pkmns->pokemon.health <= 0)
        game->character->pkmns->pokemon.health = 0;
    pause_time(0.3);
    display_text(str, pos, window, 0);
    free(str);
    return (0);
}

int disp_atk_mod(window_t *window, npc_t *npc, misc_t *misc, game_t *game)
{
    sfRenderWindow_clear(window->window, sfBlack);
    display_game(misc->tab, window, 7, 0);
    display_stat(window, misc->stat, 8);
    riposte(npc, window, game);
    return (0);
}

int disp_txt_atk(window_t *window, text_t *stat, misc_t *misc)
{
    display_stat(window, stat, 8);
    display_cursor(window, misc);
    sfRenderWindow_display(window->window);
    return (0);
}

int check_menu(window_t *window, int menu, game_object **tab)
{
    display_game(tab, window, 7, 0);
    menu = mode(window, menu);
    return (menu);
}

int destroy_all(misc_t *misc)
{
    destroy_tab(misc->tab);
    destroy_font(misc->stat, 8);
    sfClock_destroy(misc->clock);
    sfTexture_destroy(misc->texture);
    sfSprite_destroy(misc->sprite);
    free(misc);
    return (0);
}

misc_t *init_misc(window_t *window, game_t *game, npc_t *npc)
{
    misc_t *misc = malloc(sizeof(misc_t));
    sfVector2f pos = {0, 0};

    misc->tab = init_object(window, game->character->pkmns, npc->pkmns);
    misc->clock = sfClock_create();
    misc->stat = change_pos(game->character->pkmns, window, npc->pkmns);
    misc->sprite = sfSprite_create();
    misc->texture = sfTexture_createFromFile("assets/cursor.png", NULL);
    sfSprite_setTexture(misc->sprite, misc->texture, sfTrue);
    sfSprite_setOrigin(misc->sprite, pos);
    return (misc);
}

int death(window_t *window, misc_t *misc, npc_t *npc, game_t *game)
{
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};
    char *str = malloc(sizeof(char));
    int ret = 0;

    *str = 0;
    display_stat(window, misc->stat, 8);
    if (game->character->pkmns->pokemon.health <= 0) {
        str = my_strcat(str, name[game->character->pkmns->pokemon.number]);
        ret = 0;
    }
    else if (npc->pkmns->pokemon.health <= 0) {
        str = my_strcat(str, name[npc->pkmns->pokemon.number]);
        ret = 1;
    }
    str = my_strcat(str, phr[2]);
    display_text(str, pos, window, 0);
    free(str);
    destroy_all(misc);
    return (ret);
}

int ck_hp(game_t *game, npc_t *npc)
{
    if (game->character->pkmns->pokemon.health <= 0)
        return (2);
    if (npc->pkmns->pokemon.health <= 0)
        return (1);
    return (0);
}

int display_combat(window_t *win, game_t *game, npc_t *npc, misc_t *misc)
{
    misc->flag == 12 ? disp_atk_mod(win, npc, misc, game) : 0;
    disp_txt_atk(win, misc->stat, misc);
    return (0);
}

int reload(game_t *game, misc_t *misc, npc_t *npc)
{
    change_text(itoa_dup(game->character->pkmns->pokemon.health),
    &misc->stat[1]);
    change_text(itoa_dup(npc->pkmns->pokemon.health),
    &misc->stat[6]);
    return (0);
}

pkmn_list_t *nx_p(game_t *game, misc_t *misc, window_t *window)
{
    sfVector2f pos = {420, 218};
    sfIntRect rect = {0, 0, 0, 0};

    sfSprite_destroy(misc->tab[7]->sprite);
    sfTexture_destroy(misc->tab[7]->texture);
    free(misc->tab[7]);
    misc->tab[7] =
    create_object(back_pkm[game->character->pkmns->next->pokemon.number],
    pos, rect, window);
    change_text(my_strdup(name[game->character->pkmns->next->pokemon.number]),
    &misc->stat[5]);
    change_text(itoa_dup(game->character->pkmns->next->pokemon.max_health),
    &misc->stat[0]);
    change_text(itoa_dup(game->character->pkmns->next->pokemon.health),
    &misc->stat[1]);
    change_text(itoa_dup(game->character->pkmns->next->pokemon.level),
    &misc->stat[2]);
    return (game->character->pkmns->next);
}

pkmn_list_t *npc_p(npc_t *npc, misc_t *misc, window_t *window)
{
    sfVector2f pos = {720, 85};
    sfIntRect rect = {0, 0, 0, 0};

    sfSprite_destroy(misc->tab[6]->sprite);
    sfTexture_destroy(misc->tab[6]->texture);
    free(misc->tab[6]);
    misc->tab[6] =
    create_object(front_pkm[npc->pkmns->next->pokemon.number],
    pos, rect, window);
    change_text(my_strdup(name[npc->pkmns->next->pokemon.number]),
    &misc->stat[4]);
    change_text(itoa_dup(npc->pkmns->next->pokemon.max_health),
    &misc->stat[7]);
    change_text(itoa_dup(npc->pkmns->next->pokemon.health),
    &misc->stat[6]);
    change_text(itoa_dup(npc->pkmns->next->pokemon.level),
    &misc->stat[3]);
    return (npc->pkmns->next);
}

int combat(window_t *win, game_t *gm, npc_t *npc)
{
    misc_t *misc = init_misc(win, gm, npc);

    misc->flag = 0;
    animation(win, misc->tab, gm->character->type, npc);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        misc->flag = check_menu(win, misc->flag, misc->tab);
        misc->flag = check_flag(misc, win, gm->character->pkmns, npc->pkmns);
        event(win);
        reload(gm, misc, npc);
        if (misc->flag == 84)
            break;
        if ((ck_hp(gm, npc) == 1 && npc->pkmns->next == NULL) ||
            (ck_hp(gm, npc) == 2 && gm->character->pkmns->next == NULL))
            return (death(win, misc, npc, gm));
        ck_hp(gm, npc) == 2 ? gm->character->pkmns = nx_p(gm, misc, win) : 0;
        ck_hp(gm, npc) == 1 ? npc->pkmns = npc_p(npc, misc, win) : 0;
        display_combat(win, gm, npc, misc);
    }
    return (destroy_all(misc));
}

int my_linklen(pkmn_list_t *linked)
{
    int i = 0;

    if (linked == NULL)
        return (0);
    for (i = 0; linked->next != NULL; i++)
        linked = linked->next;
    return (i);
}

void free_linked(pkmn_list_t **linked, pkmn_list_t *tmp)
{
    int i = 0;

    (*linked) = tmp;
    for (i = 0; (*linked)->next != NULL; i++) {
        (*linked) = (*linked)->next;
    }
    free((*linked));
    (*linked) = NULL;
}

int choose_level(game_t *game)
{
    int nb = rand() % 6;
    int op = rand() % 2;

    if (op == 1)
        return (game->character->pkmns->pokemon.level + nb);
    else
        return (game->character->pkmns->pokemon.level - nb);
    return (0);
}

npc_t *init_rand(game_t *game)
{
    npc_t *npc = malloc(sizeof(*npc));

    if (npc == NULL)
        return (NULL);
    npc->type = -1;
    npc->pkmns = malloc(sizeof(pkmn_list_t));
    npc->pkmns->next = NULL;
    npc->pkmns->pokemon.number = rand() % 17;
    npc->pkmns->pokemon.level = choose_level(game);
    npc->pkmns->pokemon.xp_to_next_lvl = 0;
    npc->pkmns->pokemon.atq = 100 * (npc->pkmns->pokemon.level / 80) + 10;
    npc->pkmns->pokemon.def = 100 * (npc->pkmns->pokemon.level / 90) + 10;
    npc->pkmns->pokemon.max_health = ((0.90 + 2) * 60 + (20 / 4) + 100)
    * npc->pkmns->pokemon.level / 100 + 10;
    npc->pkmns->pokemon.health = npc->pkmns->pokemon.max_health;
    for (int i = 0; i < 4; i++) {
        npc->pkmns->pokemon.atks[i] = atks[rand() % NB_ATK];
    }
    return (npc);
}

int free_savage(npc_t *npc)
{
    free(npc->pkmns);
    free(npc);
    return (0);
}

void main_cbt(window_t *window, game_t *game, npc_t *npc)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(window->window);
    int toggle = 0;

    if (npc == NULL) {
        npc = init_rand(game);
        toggle = 1;
    }
    sfMusic_stop(game->music);
    sfRenderWindow_setView(window->window, default_view);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    combat(window, game, npc);
    sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
    sfRenderWindow_setView(window->window, game->view);
    if (toggle == 1)
        free_savage(npc);
    sfMusic_play(game->music);
}
