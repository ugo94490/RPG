/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_menu_game.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static const char *NAME_EN[] = {"Pokedex", "Pokemon", "Bag",
    "Save", "Settings", "Quest", "Resume", "Quit"};

static void create_select(menu_t *menu)
{
    menu->select.img = menu->menu_w;
    menu->select.rect.left = 512;
    menu->select.rect.top = 0;
    menu->select.rect.width = 178;
    menu->select.rect.height = 46;
    menu->select.pos_select.x = 690;
    menu->select.pos_select.y = 508;
}

static button_t *create_button(menu_t *menu)
{
    button_t *buttons = malloc(sizeof(button_t) * NBR_BUTTON);

    if (!buttons)
        return (NULL);
    for (int i = 0; i < NBR_BUTTON; i += 1) {
        buttons[i].n_button = i;
        buttons[i].img = menu->menu_w;
        buttons[i].rect.top = topIcon[i];
        buttons[i].rect.left = 0;
        buttons[i].rect.height = 70;
        buttons[i].rect.width = 75;
        buttons[i].pos_img.x = 688;
        buttons[i].pos_img.y = posIconY[i];
        buttons[i].pos_text.x = 770;
        buttons[i].pos_text.y = posTextY[i];
        buttons[i].text = create_text((char *)NAME_EN[i],
        "assets/Pokemon Solid.ttf", 20, buttons[i].pos_text);
        sfText_setColor(buttons[i].text.text, sfBlack);
    }
    return (buttons);
}

static void create_menu(menu_t *menu)
{
    menu->scale.x = 1;
    menu->scale.y = 1;
    menu->menu_w = create_sprite("assets/MenuSprite.png");
    if (!menu->menu_w.sprite)
        return ;
    menu->menu_rect.top = 0;
    menu->menu_rect.left = 294;
    menu->menu_rect.width = 202;
    menu->menu_rect.height = 534;
    menu->pos_menu.x = 678;
    menu->pos_menu.y = 500;
}

menu_t *create_menu_game(window_t *window)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return (NULL);
    menu->window = window;
    create_menu(menu);
    if (!menu->menu_w.sprite)
        return (NULL);
    menu->buttons = create_button(menu);
    if (!menu->buttons)
        return (NULL);
    create_select(menu);
    menu->n_button = POKEDEX;
    menu->state = NONE;
    return (menu);
}