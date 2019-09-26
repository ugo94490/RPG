/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_menu_game.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static void manage_button(game_t *game, menu_t *menu)
{
    sfVector2f pos = {800, 800};

    if (menu->n_button == QUIT)
        menu->state = QUIT;
    if (menu->n_button == POKEMON)
        menu->state = POKEMON;
    if (menu->n_button == SAVE) {
        save_game(game);
        display_text_overworld(game->window, "Game saved...", game);
    }
}

static void analyse_keyboard_menu_game(game_t *game, menu_t *menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && menu->n_button < 6) {
        menu->select.pos_select.y += 46;
        menu->n_button += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && menu->n_button > 0) {
        menu->select.pos_select.y -= 46;
        menu->n_button -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn))
        manage_button(game, menu);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        menu->state = QUIT;
}

static void analyse_click_menu_game(menu_t *menu)
{
    sfVector2i pMouse = sfMouse_getPositionRenderWindow(menu->window->window);

    if (menu->n_button == QUIT && (float)pMouse.x >=
        menu->buttons[QUIT].pos_img.x && (float)pMouse.x <=
        menu->buttons[QUIT].pos_img.x + menu->menu_rect.width
        && (float)pMouse.y >= menu->buttons[QUIT].pos_img.y && (float)pMouse.y
        <= menu->buttons[QUIT].pos_img.y + menu->menu_rect.width)
        sfRenderWindow_close(menu->window->window);
}

static void analyse_pos_mouse_menu_game(menu_t *menu)
{
    sfVector2i pMouse = sfMouse_getPositionRenderWindow(menu->window->window);

    // for (int i = 0; i < NBR_BUTTON; i += 1)
    //     if ((float)pMouse.x >= menu->buttons[i].pos_img.x &&
    //     (float)pMouse.x <= menu->buttons[i].pos_img.x + menu->select.rect.width
    //     && (float)pMouse.y >= menu->buttons[i].pos_img.y && (float)pMouse.y
    //     <= menu->buttons[i].pos_img.y + menu->buttons[i].rect.height) {
    //         menu->n_button = menu->buttons[i].n_button;
    //         menu->select.pos_select.y = 508 + (46 * menu->n_button);
    //         break;
    //     }
}

void analyse_menu_game(game_t *game, menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(menu->window->window, &event)) {
        if (event.type == sfEvtKeyPressed)
            analyse_keyboard_menu_game(game, menu);
        if (event.type == sfEvtMouseButtonPressed)
            analyse_click_menu_game(menu);
        analyse_pos_mouse_menu_game(menu);
    }
}