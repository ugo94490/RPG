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

pkmn_list_t *fill_atk(pkmn_list_t *node)
{
    for (int i = 0; i < 4; i++) {
        node->pokemon.atks[i].number = i;
        node->pokemon.atks[i].power = i * 10 + 10;
    }
    return (node);
}

pkmn_list_t *fill(int flag)
{
    pkmn_list_t *node = malloc(sizeof(*node));

    node->pokemon.number = flag;
    node->pokemon.level = 7;
    node->pokemon.health = 100;
    node->pokemon.max_health = 100;
    node->pokemon.xp_to_next_lvl = 3532;
    node->pokemon.atq = 10;
    node->pokemon.def = 15;
    node = fill_atk(node);
    return (node);
}

void add_node(pkmn_list_t *node, int flag)
{
    pkmn_list_t *new;
    int i = 0;

    for (i = 0; node->next != NULL; i++)
        node = node->next;
    new = fill(flag);
    node->next = new;
    node = node->next;
    node->next = NULL;
}

pkmn_list_t *init(void)
{
    pkmn_list_t *node;
    int flag = 0;

    node = fill(flag);
    node->next = NULL;
    for (int i = 0; i < 6; i++) {
        flag++;
        add_node(node, flag);
    }
    return (node);
}

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
    sfVector2f position = {340, 535};
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

void add_attack(sfVector2f *prev, sfVector2f *position, int flag)
{
    if (flag == 0) {
        position->x -= 0.47;
        position->y -= 0.25;
        prev->x += 0.002;
        prev->y += 0.002;
    }
    if (flag == 1) {
        position->x += 0.47;
        position->y += 0.25;
        prev->x -= 0.002;
        prev->y -= 0.002;
    }
}

void add_bag(sfVector2f *prev, sfVector2f *position, int flag)
{
    if (flag == 0) {
        position->x -= 0.35;
        position->y -= 0.25;
        prev->x += 0.003;
        prev->y += 0.003;
    }
    if (flag == 1) {
        position->x += 0.35;
        position->y += 0.25;
        prev->x -= 0.003;
        prev->y -= 0.003;
    }
}

int attack(game_object *sp, sfClock *clk, sfRenderWindow *window)
{
    sfTime time;
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    time = sfClock_getElapsedTime(clk);
    (prev.x <= 1) ? toggle = 0 : 0;
    (prev.x >= 1.04) ? toggle = 1 : 0;
    if (time.microseconds >= 1000000) {
        if (toggle == 0)
            add_attack(&prev, &position, 0);
        if (toggle == 1)
            add_attack(&prev, &position, 1);
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window, sp->sprite, NULL);
    return (0);
}

int bag(game_object *sp, sfClock *clk, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(clk);
    static int toggle = 0;
    sfVector2f prev = sfSprite_getScale(sp->sprite);
    sfVector2f position = sfSprite_getPosition(sp->sprite);

    (prev.x <= 1) ? toggle = 0 : 0;
    (prev.x >= 1.04) ? toggle = 1 : 0;
    if (time.microseconds >= 1000000) {
        if (toggle == 0)
            add_bag(&prev, &position, 0);
        if (toggle == 1)
            add_bag(&prev, &position, 1);
    }
    sfSprite_setPosition(sp->sprite, position);
    sfSprite_setScale(sp->sprite, prev);
    sfRenderWindow_drawSprite(window, sp->sprite, NULL);
    return (0);
}

int mode(sfRenderWindow *window, int flag)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window);
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

int cancel(sfRenderWindow *window)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window);
    int ret = 2;
    sfEvent event;

    if (vct.x >= 358 && vct.x <= 921 && vct.y >= 845 && vct.y <= 954) {
        ret = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ret = 1;
            pause_time(0.3);
        }
    }
    return (ret);
}

int display_game(game_object **tab, sfRenderWindow *window, int pos, int start)
{
    for (int i = start; i < pos + 1; i++)
        sfRenderWindow_drawSprite(window, tab[i]->sprite, NULL);
    return (0);
}

int attack_box(pkmn_list_t *linked, sfRenderWindow *window,
int nb, game_object **tab)
{
    char *str = malloc(sizeof(char));
    sfVector2f pos = {338, 374};

    *str = 0;
    str = my_strcat(str, name[linked->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[nb]);
    str = my_strcat(str, phr[1]);
    pause_time(0.1);
    display_text(str, pos, window);
    sfRenderWindow_clear(window, sfBlack);
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

int display_stat(sfRenderWindow *window, pkmn_list_t *linked, text_t *stat,
int lim)
{
    for (int i = 0; i < lim; i++)
        sfRenderWindow_drawText(window, stat[i].text, NULL);
    return (0);
}

int attack_anim(misc_t *misc, sfRenderWindow *window, pkmn_list_t *linked,
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
    display_stat(window, linked, misc->stat, 6);
    sprite = create_object(asset_atk[nb_atk], pos, rect);
    clock = sfClock_create();
    sfSprite_setTextureRect(sprite->sprite, rect);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        if (rect.left >= 1210)
            break;
        if (time.microseconds >= 400000) {
            sfRenderWindow_clear(window, sfBlack);
            display_game(misc->tab, window, 3, 0);
            display_game(misc->tab, window, 7, 6);
            sfSprite_setTextureRect(sprite->sprite, rect);
            sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
            display_game(misc->tab, window, 5, 4);
            display_game(misc->tab, window, 8, 8);
            display_stat(window, linked, misc->stat, 6);
            rect.top += 340;
            rect.top >= 2382 ? rect.left += 605 : 0;
            time = sfClock_restart(clock);
        }
        sfRenderWindow_display(window);
    }
    display_game(misc->tab, window, 8, 0);
    display_stat(window, linked, misc->stat, 6);
    destroy_obj(sprite);
    sfClock_destroy(clock);
}

misc_t init_atk(game_object **tab, text_t *stat)
{
    misc_t misc;

    misc.tab = tab;
    misc.stat = stat;
    return (misc);
}

int attack_one(game_object **tab, sfRenderWindow *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[0].power;
    attack_box(linked, window, 0, tab);
    attack_anim(&misc, window, linked, 0);
    return (1);
}

int attack_two(game_object **tab, sfRenderWindow *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[1].power;
    attack_box(linked, window, 1, tab);
    attack_anim(&misc, window, linked, 1);
    return (1);
}

int attack_three(game_object **tab, sfRenderWindow *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[2].power;
    attack_box(linked, window, 2, tab);
    attack_anim(&misc, window, linked, 2);
    return (1);
}

int attack_four(game_object **tab, sfRenderWindow *window,
pkmn_list_t *linked, text_t *stat)
{
    misc_t misc = init_atk(tab, stat);

    linked->next->pokemon.health -= linked->pokemon.atks[3].power;
    attack_box(linked, window, 3, tab);
    attack_anim(&misc, window, linked, 3);
    return (1);
}

int launch(game_object **tab, sfRenderWindow *window,
pkmn_list_t *linked, text_t *stat)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window);

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

game_object **init_box(pkmn_list_t *linked)
{
    game_object **tab = malloc(sizeof(game_object *) * 5);
    sfIntRect rect = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        if (linked->pokemon.atks[i].number != -1)
            tab[i] = create_object("assets/attack.png", atk_pos[i], rect);
        else
            tab[i] = create_object("assets/vide.png", atk_pos[i], rect);
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

int display_box(game_object **box, sfRenderWindow *window)
{
    for (int i = 0; box[i]; i++)
        sfRenderWindow_drawSprite(window, box[i]->sprite, NULL);
    return (0);
}

int misc_atk(game_object **tab, game_object **box, sfRenderWindow *window,
game_object *atk)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, atk->sprite, NULL);
    display_game(tab, window, 7, 1);
    display_box(box, window);
    event(window);
    return (0);
}

text_t *init_name(pkmn_list_t *linked)
{
    text_t *stat = malloc(sizeof(text_t) * 9);
    int size = 15;

    for (int i = 0; i < 9; i++) {
        if (i < 4)
            stat[i] = create_text(atk_name[i],
            "assets/classic.ttf", size, atk_txt[i]);
        else
            stat[i] = create_text(itoa_dup(linked->pokemon.atks[i - 4].power),
            "assets/classic.ttf", size, atk_txt[i]);
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

int disp_txt(sfRenderWindow *window, pkmn_list_t *linked,
text_t *stat, text_t *name_pow)
{
    display_stat(window, linked, stat, 6);
    display_stat(window, linked, name_pow, 9);
    return (0);
}

int atk_hud(sfRenderWindow *window, game_object **tab,
pkmn_list_t *linked, text_t *stat)
{
    game_object *atk = init_hud("assets/pp_hud.png", 338, 480);
    game_object **box = init_box(linked);
    text_t *name_pow = init_name(linked);
    int ret = 0;
    static int mode = 0;
    while (sfRenderWindow_isOpen(window)) {
        mode = cancel(window);
        if (mode == 1) {
            mode = 0;
            break;
        }
        misc_atk(tab, box, window, atk);
        disp_txt(window, linked, stat, name_pow);
        if (launch(tab, window, linked, stat) == 1) {
            ret = 12;
            break;
        }
        sfRenderWindow_display(window);
    }
    return (destroy_atkhud(name_pow, box, atk, ret));
}

game_object **init_object(void)
{
    game_object **tab = malloc(sizeof(game_object *) * 13);
    sfVector2f pos = {420, 218};
    sfVector2f pos2 = {720, 85};
    sfIntRect rect = {0, 0, 0, 0};

    tab[0] = init_hud("assets/attack_hud.png", 338, 480);
    tab[8] = init_choice("assets/game_menu.png");
    tab[1]= init_hud("assets/combat_screen.png", 338, 0);
    tab[3] = init_hud("assets/text_combat.png", 338, 374);
    tab[2] = init_hud("assets/cercle.png", 338, 204);
    tab[5] = init_hud("assets/opponent_life.png", 338, 123);
    tab[4] = init_hud("assets/my_life.png", 659, 263);
    tab[9] = init_little("assets/m_sel.png", 341, 825);
    tab[10] = init_little("assets/m_sel.png", 549, 844);
    tab[11] = init_little("assets/m_sel.png", 757, 825);
    tab[6] = create_object("assets/front_pkmn.png", pos2, rect);
    tab[7] = create_object("assets/back_pkmn.png", pos, rect);
    tab[12] = NULL;
    return (tab);
}

int check_flag(misc_t *misc, int flag, sfRenderWindow *win, pkmn_list_t *linked)
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

text_t *init_txt(pkmn_list_t *linked)
{
    text_t *stat = malloc(sizeof(text_t) * 6);
    int size = 15;

    for (int i = 0; i < 6; i++) {
        stat[i] = create_text("init", "assets/classic.ttf", size, pos_txt[i]);
        sfText_setFillColor(stat[i].text, sfBlack);
    }
    return (stat);
}

text_t *change_pos(pkmn_list_t *node)
{
    text_t *stat = init_txt(node);

    change_text(itoa_dup(node->pokemon.max_health), &stat[0]);
    change_text(itoa_dup(node->pokemon.health), &stat[1]);
    change_text(itoa_dup(node->pokemon.level), &stat[2]);
    change_text(itoa_dup(node->pokemon.level), &stat[3]);
    change_text(name[node->next->pokemon.number], &stat[4]);
    change_text(name[node->pokemon.number], &stat[5]);
    return (stat);
}

game_object **init_player(void)
{
    game_object **tmp = malloc(sizeof(game_object *) * 2);
    sfIntRect rect = {0, 0, 170, 148};
    sfIntRect rect2 = {0, 0, 47, 109};
    sfVector2f pos = {380, 226};
    sfVector2f pos2 = {740, 30};

    tmp[0] = create_object("assets/back_train.png", pos, rect);
    tmp[1] = create_object("assets/rival_two.png", pos2, rect2);
    return (tmp);
}

int disp_sprite(game_object **tab, sfRenderWindow *window,
game_object **character)
{
    display_game(tab, window, 5, 0);
    sfRenderWindow_drawSprite(window, character[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, character[1]->sprite, NULL);
    sfRenderWindow_display(window);
    return (0);
}

int free_character(game_object **character)
{
    destroy_obj(character[0]);
    destroy_obj(character[1]);
    free(character);
    return (0);
}

int animation(sfRenderWindow *window, game_object **tab)
{
    game_object **character = init_player();
    sfClock *clock = sfClock_create();
    sfTime time;
    int count = 0;

    display_game(tab, window, 5, 0);
    while (count != 5) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds >= 400000) {
            sfRenderWindow_clear(window, sfBlack);
            character[0]->rect.left += 173;
            sfSprite_setTextureRect(character[0]->sprite, character[0]->rect);
            disp_sprite(tab, window, character);
            time = sfClock_restart(clock);
            count++;
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    free_character(character);
    sfClock_destroy(clock);
    return (0);
}

int riposte(pkmn_list_t *linked, sfRenderWindow *window)
{
    int nb = rand() % 3;
    char *str = NULL;
    sfVector2f pos = {338, 374};

    str = malloc(sizeof(char));
    str[0] = '\0';
    str = my_strcat(str, name[linked->next->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[nb]);
    str = my_strcat(str, phr[1]);
    linked->pokemon.health -= linked->next->pokemon.atks[nb].power;
    pause_time(0.3);
    display_text(str, pos, window);
    free(str);
    return (0);
}

int disp_atk_mod(sfRenderWindow *window, pkmn_list_t *linked,
game_object **tab, text_t *stat)
{
    sfRenderWindow_clear(window, sfBlack);
    display_game(tab, window, 7, 0);
    display_stat(window, linked, stat, 6);
    riposte(linked, window);
    return (0);
}

int disp_txt_atk(sfRenderWindow *window, pkmn_list_t *linked, text_t *stat)
{
    display_stat(window, linked, stat, 6);
    sfRenderWindow_display(window);
    return (0);
}

int check_menu(sfRenderWindow *window, int menu, game_object **tab)
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

misc_t *init_misc(pkmn_list_t *linked)
{
    misc_t *misc = malloc(sizeof(misc_t));

    misc->tab = init_object();
    misc->clock = sfClock_create();
    misc->stat = change_pos(linked);
    return (misc);
}

int death(pkmn_list_t *linked, sfRenderWindow *window, misc_t *misc)
{
    sfVector2f pos = {338, 374};
    char *str = malloc(sizeof(char));

    *str = 0;
    display_stat(window, linked, misc->stat, 6);
    if (linked->pokemon.health <= 0)
        str = my_strcat(str, name[linked->pokemon.number]);
    else if (linked->next->pokemon.health <= 0)
        str = my_strcat(str, name[linked->next->pokemon.number]);
    str = my_strcat(str, phr[2]);
    display_text(str, pos, window);
    free(str);
    return (destroy_all(misc));
}

int combat(sfRenderWindow *window, pkmn_list_t *linked)
{
    misc_t *misc = init_misc(linked);
    int menu = 0;

    animation(window, misc->tab);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        menu = check_menu(window, menu, misc->tab);
        menu = check_flag(misc, menu, window, linked);
        event(window);
        change_text(itoa_dup(linked->pokemon.health), &misc->stat[1]);
        if (menu == 84)
            break;
        if (linked->pokemon.health <= 0 || linked->next->pokemon.health <= 0)
            return (death(linked, window, misc));
        menu == 12 ? disp_atk_mod(window, linked, misc->tab, misc->stat) : 0;
        disp_txt_atk(window, linked, misc->stat);
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
    combat(window->window, game->character->pkmns);
    sfRenderWindow_setView(window->window, game->view);
}
