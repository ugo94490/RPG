/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

int pause_time(float sec)
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

void add_attack(sfVector2f *prev, sfVector2f *position, int flag, window_t *window)
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
    if (time.microseconds >= 1000000) {
        if (toggle == 0)
            add_attack(&prev, &position, 0, window);
        if (toggle == 1)
            add_attack(&prev, &position, 1, window);
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
    if (time.microseconds >= 1000000) {
        if (toggle == 0)
            add_bag(&prev, &position, 0, window);
        if (toggle == 1)
            add_bag(&prev, &position, 1, window);
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window->window, sp->sprite, NULL);
    return (0);
}

int mode(window_t *window, int flag)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);
    int ret = 0;

    if (vct.x >= 343 && vct.x <= 936 && vct.y >= 537 && vct.y <= 812) {
        ret = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            pause_time(0.3) == 0 ? ret = 6 : 0;
    }
    if (vct.x >= 340 && vct.x <= 522 && vct.y >= 823 && vct.y <= 929)
        ret = 2;
    if (vct.x >= 548 && vct.x <= 730 && vct.y >= 842 && vct.y <= 948) {
        ret = 3;
        if (sfMouse_isButtonPressed(sfMouseLeft) && flag != 6) {
            pause_time(0.3);
            ret = 5;
        }
    }
    if (vct.x >= 756 && vct.x <= 938 && vct.y >= 823 && vct.y <= 929)
        ret = 4;
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
        if (strcmp(atk[i], atk_name[linked->pokemon.atks[nb].number])
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
    display_stat(window, misc->stat, 6);
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
            display_stat(window, misc->stat, 6);
            rect.top += 340;
            rect.top >= 2382 ? rect.left += 605 : 0;
            time = sfClock_restart(clock);
        }
        sfRenderWindow_display(window->window);
    }
    display_game(misc->tab, window, 8, 0);
    display_stat(window, misc->stat, 6);
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

int attack_one(game_object **tab, window_t *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[0].power;
    attack_box(linked, window, 0, tab);
    attack_anim(&misc, window, linked, 0);
    return (1);
}

int attack_two(game_object **tab, window_t *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[1].power;
    attack_box(linked, window, 1, tab);
    attack_anim(&misc, window, linked, 1);
    return (1);
}

int attack_three(game_object **tab, window_t *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[2].power;
    attack_box(linked, window, 2, tab);
    attack_anim(&misc, window, linked, 2);
    return (1);
}

int attack_four(game_object **tab, window_t *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[3].power;
    attack_box(linked, window, 3, tab);
    attack_anim(&misc, window, linked, 3);
    return (1);
}

int launch(game_object **tab, window_t *window,
pkmn_list_t *linked, text_t *stat)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window->window);

    if (linked->pokemon.atks[0].number != -1 && atk_pos[0].x <= vct.x &&
        atk_pos[0].x + 293 >= vct.x && atk_pos[0].y <= vct.y && atk_pos[0].y
        + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_one(tab, window, linked, stat));
    if (linked->pokemon.atks[1].number != -1 && atk_pos[1].x <= vct.x &&
        atk_pos[1].x + 293 >= vct.x && atk_pos[1].y <= vct.y && atk_pos[1].y
        + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_two(tab, window, linked, stat));
    if (linked->pokemon.atks[2].number != -1 && atk_pos[2].x <= vct.x &&
        atk_pos[2].x + 293 >= vct.x && atk_pos[2].y <= vct.y && atk_pos[2].y
        + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_three(tab, window, linked, stat));
    if (linked->pokemon.atks[3].number != -1 && atk_pos[3].x <= vct.x &&
        atk_pos[3].x + 293 >= vct.x && atk_pos[3].y <= vct.y && atk_pos[3].y
        + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft))
        return (attack_four(tab, window, linked, stat));
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
    sfIntRect rect = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        if (linked->pokemon.atks[i].number != -1)
            tab[i] = create_object("assets/attack.png", atk_pos[i], rect, window);
        else
            tab[i] = create_object("assets/vide.png", atk_pos[i], rect, window);
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

int misc_atk(game_object **tab, game_object **box, window_t *window,
game_object *atk)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, atk->sprite, NULL);
    display_game(tab, window, 7, 1);
    display_box(box, window);
    event(window);
    return (0);
}

text_t *init_name(pkmn_list_t *linked, window_t *window)
{
    text_t *stat = malloc(sizeof(text_t) * 9);
    int size = 15 * window->scale.x;
    sfVector2f tmp = {0, 0};

    for (int i = 0; i < 9; i++) {
        tmp.x = atk_txt[i].x * window->scale.x;
        tmp.y = atk_txt[i].y * window->scale.y;
        if (i < 4)
            stat[i] = create_text(atk_name[i],
            "assets/classic.ttf", size, tmp);
        else
            stat[i] = create_text(itoa_dup(linked->pokemon.atks[i - 4].power),
            "assets/classic.ttf", size, tmp);
        sfText_setFillColor(stat[i].text, sfBlack);
    }
    return (stat);
}

int destroy_atkhud(text_t *name_pow, game_object **box, game_object *atk,
int flag)
{
    destroy_font(name_pow, 9);
    destroy_tab(box);
    destroy_obj(atk);
    return (flag);
}

int disp_txt(window_t *window, text_t *stat, text_t *name_pow)
{
    display_stat(window, stat, 6);
    display_stat(window, name_pow, 9);
    return (0);
}

int atk_hud(window_t *window, game_object **tab,
pkmn_list_t *linked, text_t *stat)
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
        misc_atk(tab, box, window, atk);
        disp_txt(window, stat, name_pow);
        if (launch(tab, window, linked, stat) == 1) {
            ret = 12;
            break;
        }
        sfRenderWindow_display(window->window);
    }
    return (destroy_atkhud(name_pow, box, atk, ret));
}

game_object **init_object(window_t *window)
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
    tab[6] = create_object("assets/front_pkmn.png", pos2, rect, window);
    tab[7] = create_object("assets/back_pkmn.png", pos, rect, window);
    tab[12] = NULL;
    return (tab);
}

int check_flag(misc_t *misc, int flag, window_t *win, pkmn_list_t *linked)
{
    if (flag == 1)
        attack(misc->tab[8], misc->clock, win);
    if (flag == 2)
        bag(misc->tab[9], misc->clock, win);
    if (flag == 3)
        bag(misc->tab[10], misc->clock, win);
    if (flag == 4)
        bag(misc->tab[11], misc->clock, win);
    if (flag == 5)
        return (84);
    if (flag == 6) {
        return (atk_hud(win, misc->tab, linked, misc->stat));
    }
    return (flag);
}

text_t *init_txt(window_t *window)
{
    text_t *stat = malloc(sizeof(text_t) * 6);
    int size = 15 * window->scale.x;
    sfVector2f tmp = {0, 0};

    for (int i = 0; i < 6; i++) {
        tmp.x = pos_txt[i].x * window->scale.x;
        tmp.y = pos_txt[i].y * window->scale.y;
        stat[i] = create_text("init", "assets/classic.ttf", size, tmp);
        sfText_setFillColor(stat[i].text, sfBlack);
    }
    return (stat);
}

text_t *change_pos(pkmn_list_t *node, window_t *window)
{
    text_t *stat = init_txt(window);

    change_text(itoa_dup(node->pokemon.max_health), &stat[0]);
    change_text(itoa_dup(node->pokemon.health), &stat[1]);
    change_text(itoa_dup(node->pokemon.level), &stat[2]);
    change_text(itoa_dup(node->pokemon.level), &stat[3]);
    change_text(name[node->next->pokemon.number], &stat[4]);
    change_text(name[node->pokemon.number], &stat[5]);
    return (stat);
}

game_object **init_player(window_t *window)
{
    game_object **tmp = malloc(sizeof(game_object *) * 2);
    sfIntRect rect = {0, 0, 170, 148};
    sfIntRect rect2 = {0, 0, 47, 109};
    sfVector2f pos = {380, 226};
    sfVector2f pos2 = {740, 30};

    tmp[0] = create_object("assets/back_train.png", pos, rect, window);
    tmp[1] = create_object("assets/rival_two.png", pos2, rect2, window);
    return (tmp);
}

int disp_sprite(game_object **tab, window_t *window,
game_object **character)
{
    display_game(tab, window, 5, 0);
    sfRenderWindow_drawSprite(window->window, character[0]->sprite, NULL);
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

int animation(window_t *window, game_object **tab)
{
    game_object **character = init_player(window);
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
            disp_sprite(tab, window, character);
            time = sfClock_restart(clock);
            count++;
        }
    }
    sfRenderWindow_clear(window->window, sfBlack);
    free_character(character);
    sfClock_destroy(clock);
    return (0);
}

int riposte(pkmn_list_t *linked, window_t *window)
{
    int nb = rand() % 3;
    char *str = NULL;
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};

    str = malloc(sizeof(char));
    str[0] = '\0';
    str = my_strcat(str, name[linked->next->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[nb]);
    str = my_strcat(str, phr[1]);
    linked->pokemon.health -= linked->next->pokemon.atks[nb].power;
    pause_time(0.3);
    display_text(str, pos, window, 0);
    free(str);
    return (0);
}

int disp_atk_mod(window_t *window, pkmn_list_t *linked,
game_object **tab, text_t *stat)
{
    sfRenderWindow_clear(window->window, sfBlack);
    display_game(tab, window, 7, 0);
    display_stat(window, stat, 6);
    riposte(linked, window);
    return (0);
}

int disp_txt_atk(window_t *window, text_t *stat)
{
    display_stat(window, stat, 6);
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
    destroy_font(misc->stat, 6);
    sfClock_destroy(misc->clock);
    free(misc);
    return (0);
}

misc_t *init_misc(pkmn_list_t *linked, window_t *window)
{
    misc_t *misc = malloc(sizeof(misc_t));

    misc->tab = init_object(window);
    misc->clock = sfClock_create();
    misc->stat = change_pos(linked, window);
    return (misc);
}

int death(pkmn_list_t *linked, window_t *window, misc_t *misc)
{
    sfVector2f pos = {338 * window->scale.x, 374 * window->scale.y};
    char *str = malloc(sizeof(char));

    *str = 0;
    display_stat(window, misc->stat, 6);
    if (linked->pokemon.health <= 0)
        str = my_strcat(str, name[linked->pokemon.number]);
    else if (linked->next->pokemon.health <= 0)
        str = my_strcat(str, name[linked->next->pokemon.number]);
    str = my_strcat(str, phr[2]);
    display_text(str, pos, window, 0);
    free(str);
    return (destroy_all(misc));
}

int combat(window_t *window, pkmn_list_t *linked)
{
    misc_t *misc = init_misc(linked, window);
    int menu = 0;

    animation(window, misc->tab);
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        menu = check_menu(window, menu, misc->tab);
        menu = check_flag(misc, menu, window, linked);
        event(window);
        change_text(itoa_dup(linked->pokemon.health), &misc->stat[1]);
        if (menu == 84)
            break;
        if (linked->pokemon.health <= 0 || linked->next->pokemon.health <= 0)
            return (death(linked, window, misc));
        menu == 12 ? disp_atk_mod(window, linked, misc->tab, misc->stat) : 0;
        disp_txt_atk(window, misc->stat);
        if (linked->pokemon.health <= 0 || linked->next->pokemon.health <= 0)
            return (death(linked, window, misc));
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

void main_cbt(window_t *window, game_t *game)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(window->window);

    sfRenderWindow_setView(window->window, default_view);
    combat(window, game->character->pkmns);
    sfRenderWindow_setView(window->window, game->view);
}
