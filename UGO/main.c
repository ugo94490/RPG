/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"
#include "graphics.h"

pkmn_list_t *fill_atk(pkmn_list_t *node)
{
    for (int i = 0; i < 4; i++) {
        node->pokemon.atks[i].number = i;
        node->pokemon.atks[i].power = i * 10 + 20;
        node->pokemon.atks[i].type = 0;
        node->pokemon.atks[i].spetype = 1;
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
    node->pokemon.speed = 5;
    node->pokemon.physatq = 100;
    node->pokemon.physdef = 75;
    node->pokemon.speatq = 10;
    node->pokemon.spedef = 15;
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
    static int ret = 0;

    ret = 0;
    if (vct.x >= 343 && vct.x <= 936 && vct.y >= 537 && vct.y <= 812) {
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

int display_game(game_object **tab, sfRenderWindow *window, int pos, int start)
{
    for (int i = start; i < pos + 1; i++)
        sfRenderWindow_drawSprite(window, tab[i]->sprite, NULL);
    return (0);
}

int launch(game_object **tab, sfRenderWindow *window, pkmn_list_t *linked)
{
    int nb = rand() % 3;

    if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
        linked->next->pokemon.health -= linked->pokemon.atks[0].power;
        linked->pokemon.health -= linked->next->pokemon.atks[nb].power;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
        linked->next->pokemon.health -= linked->pokemon.atks[1].power;
        linked->pokemon.health -= linked->next->pokemon.atks[nb].power;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum3)) {
        linked->next->pokemon.health -= linked->pokemon.atks[2].power;
        linked->pokemon.health -= linked->next->pokemon.atks[nb].power;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum4)) {
        linked->next->pokemon.health -= linked->pokemon.atks[3].power;
        linked->pokemon.health -= linked->next->pokemon.atks[nb].power;
    }
    return (0);
}

char *itoa_dup(int nb)
{
    char *nbr = malloc(sizeof(char) * (my_int(nb) + 1));

    nbr = my_itoa(nb, nbr);
    return (nbr);
}

int display_stat(sfRenderWindow *window, pkmn_list_t *linked, text_t *stat)
{
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(window, stat[i].text, NULL);
    sfRenderWindow_display(window);
    return (0);
}

int atk_hud(sfRenderWindow *window, game_object **tab, pkmn_list_t *linked, text_t *stat)
{
    game_object *atk = init_hud("../assets/pp_hud.png", 338, 480);
    static int mode = 0;

    while (sfRenderWindow_isOpen(window)) {
        mode = cancel(window);
        if (mode == 1) {
            mode = 0;
            break;
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, atk->sprite, NULL);
        display_game(tab, window, 7, 1);
        display_stat(window, linked, stat);
        launch(tab, window, linked);
        event(window);
        change_text(itoa_dup(linked->pokemon.health), &stat[1]);
        if (linked->pokemon.health <= 0 || linked->next->pokemon.health <= 0)
            break;
        sfRenderWindow_display(window);
    }
    destroy_object(atk);
    return (0);
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

int destroy_tab(game_object **tab)
{
    for (int i = 0; tab[i]; i++)
        destroy_object(tab[i]);
    free(tab);
    return (0);
}

int check_flag(game_object **tab, sfClock *clock, int flag, sfRenderWindow *win, pkmn_list_t *linked, text_t *stat)
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
        atk_hud(win, tab, linked, stat);
        return (1);
    }
    return (flag);
}

text_t *init_txt(pkmn_list_t *linked)
{
    text_t *stat = malloc(sizeof(text_t) * 6);
    sfVector2f pos = {0, 0};
    int size = 15;

    for (int i = 0; i < 6; i++) {
        stat[i] = create_text("init", "classic.ttf", size, pos);
        sfText_setFillColor(stat[i].text, sfBlack);
    }
    return (stat);
}

void new_pos(text_t text, sfVector2f pos)
{
    sfText_setPosition(text.text, pos);
}

text_t *change_pos(pkmn_list_t *node)
{
    sfVector2f pos = {880, 328};
    sfVector2f pos2 = {815, 328};
    sfVector2f pos3 = {885, 280};
    sfVector2f pos4 = {535, 141};
    sfVector2f pos5 = {340, 135};
    sfVector2f pos6 = {700, 275};
    text_t *stat = init_txt(node);

    change_text(itoa_dup(node->pokemon.max_health), &stat[0]);
    change_text(itoa_dup(node->pokemon.health), &stat[1]);
    change_text(itoa_dup(node->pokemon.level), &stat[2]);
    change_text(itoa_dup(node->pokemon.level), &stat[3]);
    change_text(name[node->next->pokemon.number], &stat[4]);
    change_text(name[node->pokemon.number], &stat[5]);
    new_pos(stat[0], pos);
    new_pos(stat[1], pos2);
    new_pos(stat[2], pos3);
    new_pos(stat[3], pos4);
    new_pos(stat[4], pos5);
    new_pos(stat[5], pos6);
    return (stat);
}

int animation(sfRenderWindow *window, game_object **tab)
{
    sfIntRect rect = {0, 0, 170, 148};
    sfIntRect rect2 = {0, 0, 47, 109};
    sfVector2f pos = {380, 226};
    sfVector2f pos2 = {740, 30};
    game_object *player = create_object("../assets/back_train.png", pos, rect);
    game_object *rival = create_object("../assets/rival_two.png", pos2, rect2);
    sfClock *clock = sfClock_create();
    sfTime time;
    int count = 0;

    display_game(tab, window, 5, 0);
    while (count != 5) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds >= 400000) {
            sfRenderWindow_clear(window, sfBlack);
            rect.left += 173;
            sfSprite_setTextureRect(player->sprite, rect);
            display_game(tab, window, 5, 0);
            sfRenderWindow_drawSprite(window, player->sprite, NULL);
            sfRenderWindow_drawSprite(window, rival->sprite, NULL);
            sfRenderWindow_display(window);
            time = sfClock_restart(clock);
            count++;
        }
    }
    destroy_object(rival);
    destroy_object(player);
    sfClock_destroy(clock);
    return (0);
}

int dresseur(sfRenderWindow *window, int menu, game_object **tab)
{
    if (menu == -1)
        return (animation(window, tab));
    return (0);
}

int destroy_font(text_t *stat)
{
    for (int i = 0; i < 6; i++) {
        sfText_destroy(stat[i].text);
        sfFont_destroy(stat[i].font);
    }
    free(stat);
    return (0);
}

int combat(sfRenderWindow *window, pkmn_list_t *linked)
{
    game_object **tab = init_object();
    sfClock *clock = sfClock_create();
    text_t *stat = change_pos(linked);
    int menu = -1;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        menu = dresseur(window, menu, tab);
        display_game(tab, window, 7, 0);
        menu = mode(window, menu);
        menu = check_flag(tab, clock, menu, window, linked, stat);
        display_stat(window, linked, stat);
        sfRenderWindow_display(window);
        event(window);
        if (linked->pokemon.health <= 0 || linked->next->pokemon.health <= 0)
            sfRenderWindow_close(window);
    }
    destroy_tab(tab);
    destroy_font(stat);
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
