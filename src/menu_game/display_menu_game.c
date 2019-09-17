/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_menu_game.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

void display_buttons_menu_game(menu_t *menu)
{
    for (int i = 0; i < NBR_BUTTON; i += 1) {
        if (menu->n_button == menu->buttons[i].n_button) {
            menu->buttons[i].rect.left = 75;
            sfText_setCharacterSize(menu->buttons[i].text.text, 21);
        } else {
            menu->buttons[i].rect.left = 0;
            sfText_setCharacterSize(menu->buttons[i].text.text, 20);
        }
        sfSprite_setTextureRect(menu->buttons[i].img.sprite,
        menu->buttons[i].rect);
        sfSprite_setPosition(menu->buttons[i].img.sprite,
        menu->buttons[i].pos_img);
        sfSprite_setScale(menu->buttons[i].img.sprite, menu->scale);
        sfRenderWindow_drawSprite(menu->window->window,
        menu->buttons[i].img.sprite, NULL);
        sfRenderWindow_drawText(menu->window->window,
        menu->buttons[i].text.text, NULL);
    }
}

void display_menu_game(menu_t *menu)
{
    sfSprite_setTextureRect(menu->menu_w.sprite, menu->menu_rect);
    sfSprite_setPosition(menu->menu_w.sprite, menu->pos_menu);
    sfRenderWindow_drawSprite(menu->window->window, menu->menu_w.sprite, NULL);
    display_buttons_menu_game(menu);
    sfSprite_setTextureRect(menu->select.img.sprite, menu->select.rect);
    sfSprite_setPosition(menu->select.img.sprite, menu->select.pos_select);
    sfRenderWindow_drawSprite(menu->window->window,
    menu->select.img.sprite, NULL);
}