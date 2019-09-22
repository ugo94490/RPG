/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"
#include "graphics.h"
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

int attack_box(pkmn_list_t *linked, sfRenderWindow *window, int nb)
{
    char *str = NULL;
    sfVector2f pos = {338, 374};

    str = malloc(sizeof(char));
    str[0] = '\0';
    str = my_strcat(str, name[linked->pokemon.number]);
    str = my_strcat(str, phr[0]);
    str = my_strcat(str, atk_name[nb]);
    str = my_strcat(str, phr[1]);
    pause_time(0.1);
    display_text(str, pos, window);
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

int attack_anim(game_object **tab, sfRenderWindow *window, pkmn_list_t *linked,
int nb, text_t *stat)
{
    sfIntRect rect = {0, 0, 605, 340};
    sfVector2f pos = {340, 30};
    int nb_atk = get_atk(linked, nb);
    game_object *sprite;
    sfClock *clock;
    sfTime time;

    if (nb_atk == -1)
        return (0);
    sprite = create_object(asset_atk[nb_atk], pos, rect);
    clock = sfClock_create();
    sfSprite_setTextureRect(sprite->sprite, rect);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        if (rect.left >= 1210)
            break;
        sfRenderWindow_display(window);
        if (time.microseconds >= 400000) {
            sfRenderWindow_clear(window, sfBlack);
            display_game(tab, window, 3, 0);
            display_game(tab, window, 7, 6);
            sfSprite_setTextureRect(sprite->sprite, rect);
            sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
            display_game(tab, window, 5, 4);
            display_game(tab, window, 8, 8);
            display_stat(window, linked, stat, 6);
            rect.top += 340;
            rect.top >= 2382 ? rect.left += 605 : 0;
            time = sfClock_restart(clock);
        }
    }
    display_game(tab, window, 8, 0);
    display_stat(window, linked, stat, 6);
    destroy_object(sprite);
    sfClock_destroy(clock);
}

int launch(game_object **tab, sfRenderWindow *window,
pkmn_list_t *linked, text_t *stat)
{
    sfVector2i vct = sfMouse_getPositionRenderWindow(window);
    sfEvent event;

    if (linked->pokemon.atks[0].number != -1 && atk_pos[0].x <= vct.x &&
    atk_pos[0].x + 293 >= vct.x && atk_pos[0].y <= vct.y && atk_pos[0].y
    + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft)) {
        linked->next->pokemon.health -= linked->pokemon.atks[0].power;
        attack_box(linked, window, 0);
        attack_anim(tab, window, linked, 0, stat);
        return (1);
    }
    if (linked->pokemon.atks[1].number != -1 && atk_pos[1].x <= vct.x &&
    atk_pos[1].x + 293 >= vct.x && atk_pos[1].y <= vct.y && atk_pos[1].y
    + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft)) {
        linked->next->pokemon.health -= linked->pokemon.atks[1].power;
        attack_box(linked, window, 1);
        attack_anim(tab, window, linked, 1, stat);
        return (1);
    }
    if (linked->pokemon.atks[2].number != -1 && atk_pos[2].x <= vct.x &&
    atk_pos[2].x + 293 >= vct.x && atk_pos[2].y <= vct.y && atk_pos[2].y
    + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft)) {
        linked->next->pokemon.health -= linked->pokemon.atks[2].power;
        attack_box(linked, window, 2);
        attack_anim(tab, window, linked, 2, stat);
        return (1);
    }
    if (linked->pokemon.atks[3].number != -1 && atk_pos[3].x <= vct.x &&
    atk_pos[3].x + 293 >= vct.x && atk_pos[3].y <= vct.y && atk_pos[3].y
    + 130 >= vct.y && sfMouse_isButtonPressed(sfMouseLeft)) {
        linked->next->pokemon.health -= linked->pokemon.atks[3].power;
        attack_box(linked, window, 3);
        attack_anim(tab, window, linked, 3, stat);
        return (1);
    }
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
            tab[i] = create_object("../assets/attack.png", atk_pos[i], rect);
        else
            tab[i] = create_object("../assets/vide.png", atk_pos[i], rect);
    }
    tab[4] = NULL;
    return (tab);
}

int destroy_tab(game_object **tab)
{
    for (int i = 0; tab[i]; i++)
        destroy_object(tab[i]);
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
            stat[i] = create_text(atk_name[i], "classic.ttf", size, atk_txt[i]);
        else
            stat[i] = create_text(itoa_dup(linked->pokemon.atks[i - 4].power),
            "classic.ttf", size, atk_txt[i]);
        sfText_setFillColor(stat[i].text, sfBlack);
    }
    return (stat);
}

int destroy_atkhud(text_t *name_pow, game_object **box, game_object *atk,
int flag)
{
    destroy_font(name_pow, 9);
    destroy_tab(box);
    destroy_object(atk);
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
    game_object *atk = init_hud("../assets/pp_hud.png", 338, 480);
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

    tab[0] = init_hud("../assets/attack_hud.png", 338, 480);
    tab[8] = init_choice("../assets/game_menu.png");
    tab[1]= init_hud("../assets/combat_screen.png", 338, 0);
    tab[3] = init_hud("../assets/text_combat.png", 338, 374);
    tab[2] = init_hud("../assets/cercle.png", 338, 204);
    tab[5] = init_hud("../assets/opponent_life.png", 338, 123);
    tab[4] = init_hud("../assets/my_life.png", 659, 263);
    tab[9] = init_little("../assets/m_sel.png", 341, 825);
    tab[10] = init_little("../assets/m_sel.png", 549, 844);
    tab[11] = init_little("../assets/m_sel.png", 757, 825);
    tab[6] = create_object("../assets/front_pkmn.png", pos2, rect);
    tab[7] = create_object("../assets/back_pkmn.png", pos, rect);
    tab[12] = NULL;
    return (tab);
}

int check_flag(game_object **tab, sfClock *clock,
int flag, sfRenderWindow *win, pkmn_list_t *linked, text_t *stat)
{
    if (flag == 1)
        attack(tab[8], clock, win);
    if (flag == 2)
        bag(tab[9], clock, win);
    if (flag == 3)
        bag(tab[10], clock, win);
    if (flag == 4)
        bag(tab[11], clock, win);
    if (flag == 5)
        sfRenderWindow_close(win);
    if (flag == 6) {
        return (atk_hud(win, tab, linked, stat));
    }
    return (flag);
}

text_t *init_txt(pkmn_list_t *linked)
{
    text_t *stat = malloc(sizeof(text_t) * 6);
    int size = 15;

    for (int i = 0; i < 6; i++) {
        stat[i] = create_text("init", "classic.ttf", size, pos_txt[i]);
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

    tmp[0] = create_object("../assets/back_train.png", pos, rect);
    tmp[1] = create_object("../assets/rival_two.png", pos2, rect2);
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
    destroy_object(character[0]);
    destroy_object(character[1]);
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
    free_character(character);
    sfClock_destroy(clock);
    return (0);
}

int dresseur(sfRenderWindow *window, int menu, game_object **tab)
{
    if (menu == -1)
        return (animation(window, tab));
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
    display_game(tab, window, 7, 0);
    display_stat(window, linked, stat, 6);
    riposte(linked, window);
    return (0);
}

int disp_txt_atk(sfRenderWindow *window, pkmn_list_t *linked, text_t *stat)
{
    change_text(itoa_dup(linked->pokemon.health), &stat[1]);
    display_stat(window, linked, stat, 6);
    sfRenderWindow_display(window);
    return (0);
}

int check_menu(sfRenderWindow *window, int menu, game_object **tab)
{
    menu = dresseur(window, menu, tab);
    display_game(tab, window, 7, 0);
    menu = mode(window, menu);
    return (menu);
}

int combat(sfRenderWindow *window, pkmn_list_t *linked)
{
    game_object **tab = init_object();
    sfClock *clock = sfClock_create();
    text_t *stat = change_pos(linked);
    int menu = -1;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        menu = check_menu(window, menu, tab);
        menu = check_flag(tab, clock, menu, window, linked, stat);
        event(window);
        if (menu == 12)
            disp_atk_mod(window, linked, tab, stat);
        disp_txt_atk(window, linked, stat);
        if (linked->pokemon.health <= 0 || linked->next->pokemon.health <= 0)
            sfRenderWindow_close(window);
    }
    destroy_tab(tab);
    destroy_font(stat, 6);
    sfClock_destroy(clock);
    return (0);
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

int main(void)
{
    pkmn_list_t *linked = init();
    pkmn_list_t *tmp = linked;
    window_t window = create_window(1280, 960, 32, "COMBAT RPG");

    srand(time(0));
    sfRenderWindow_setFramerateLimit(window.window, 60);
    combat(window.window, linked);
    sfRenderWindow_destroy(window.window);
    return (0);
}
