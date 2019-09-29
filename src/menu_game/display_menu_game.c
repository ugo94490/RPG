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

static void sub_display_buttons(menu_t *menu, int i, sfVector2f temppos)
{
    if (i == 4)
        menu->buttons[i].pos_img.y = temppos.y - 225 * menu->window->scale.y +
        (50 * i * menu->window->scale.y) + (5 - 20) * menu->window->scale.y;
    else
        menu->buttons[i].pos_img.y = temppos.y - 225 * menu->window->scale.y
        + (50 * i * menu->window->scale.y) + (5 * menu->window->scale.y);
    sfSprite_setPosition(menu->buttons[i].img.sprite,
    menu->buttons[i].pos_img);
    sfSprite_setScale(menu->buttons[i].img.sprite, menu->window->scale);
    sfRenderWindow_drawSprite(menu->window->window,
    menu->buttons[i].img.sprite, NULL);
    menu->buttons[i].pos_text.x = temppos.x -
    menu->buttons[i].rect.width * menu->window->scale.y;
    if (i == 7)
        menu->buttons[i].pos_text.y = temppos.y - 215 * menu->window->scale.y
        + (50 * i * menu->window->scale.y) + 25 * menu->window->scale.y;
    else
        menu->buttons[i].pos_text.y = temppos.y - 215 * menu->window->scale.y
        + (50 * i * menu->window->scale.y) + 5 * menu->window->scale.y;
}

static void display_buttons_menu_game(game_t *game, menu_t *menu)
{
    sfVector2f temppos = {(game->character->pos.x + character_width / 2)
        * game->window->scale.x, (game->character->pos.y +
        character_height / 6) * game->window->scale.y};

    for (int i = 0; i < NBR_BUTTON; i += 1) {
        if (menu->n_button == menu->buttons[i].n_button) {
            menu->buttons[i].rect.left = 75;
            sfText_setCharacterSize(menu->buttons[i].text.text, 22 * menu->window->scale.x);
        } else {
            menu->buttons[i].rect.left = 0;
            sfText_setCharacterSize(menu->buttons[i].text.text, 20 * menu->window->scale.x);
        }
        sfSprite_setTextureRect(menu->buttons[i].img.sprite,
        menu->buttons[i].rect);
        menu->buttons[i].pos_img.x = temppos.x + 25 * menu->window->scale.x;
        sub_display_buttons(menu, i, temppos);
        sfText_setPosition(menu->buttons[i].text.text,
        menu->buttons[i].pos_text);
        sfRenderWindow_drawText(menu->window->window,
        menu->buttons[i].text.text, NULL);
    }
}

void display_menu_game(game_t *game, menu_t *menu)
{
    sfVector2f temppos = {(game->character->pos.x + character_width / 2)
        * game->window->scale.x, (game->character->pos.y +
        character_height / 6) * game->window->scale.y};

    sfSprite_setTextureRect(menu->menu_w.sprite, menu->menu_rect);
    sfSprite_setScale(menu->menu_w.sprite, menu->window->scale);
    menu->pos_menu.x = temppos.x - (100 * menu->window->scale.x);
    menu->pos_menu.y = temppos.y - (225 * menu->window->scale.y);
    sfSprite_setPosition(menu->menu_w.sprite, menu->pos_menu);
    sfRenderWindow_drawSprite(menu->window->window, menu->menu_w.sprite, NULL);
    display_buttons_menu_game(game, menu);
}