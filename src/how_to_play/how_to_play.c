/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** how_to_play.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "menu.h"
#include "how_to_play.h"

static void create_how_to_play(how_to_t *help)
{
    help->nbr_where = 0;
    help->state = START;
    help->spriteHelp = malloc(sizeof(sprite_t) * NBR_HELP_IMG);
    help->rectProf.width = 98;
    help->rectProf.height = 132;
    help->rectProf.top = 0;
    help->rectProf.left = 0;
    help->rectScreen.width = 640;
    help->rectScreen.height = 480;
    help->rectScreen.top = 0;
    help->rectScreen.left = 0;
    help->spriteHelp[0] = create_sprite("assets/ProfSprite.png");
    help->spriteHelp[1] = create_sprite("assets/TutoOne1.png");
    help->spriteHelp[2] = create_sprite("assets/TutoOne2.png");
}

static void how_to_analyse_event(how_to_t *help)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) ||
    sfKeyboard_isKeyPressed(sfKeyEscape))
        help->state = END;
}

static void how_to_display(window_t *window, how_to_t *help)
{
    sfVector2f pos = {0};
    sfVector2f tmp = {3 * window->scale.x, 3 * window->scale.y};

    pos.x = (1280 - help->rectProf.width * 3) / 2 * window->scale.x;
    pos.y = (960 - help->rectProf.height * 3) / 2 * window->scale.y;
    if (help->state == START) {
        sfSprite_setScale(help->spriteHelp[0].sprite, tmp);
        sfSprite_setPosition(help->spriteHelp[0].sprite, pos);
        sfSprite_setTextureRect(help->spriteHelp[0].sprite, help->rectProf);
        sfRenderWindow_drawSprite(window->window, help->spriteHelp[0].sprite, NULL);
        help->nbr_where += 1;
    }
}

static void destroy_how_to_play(how_to_t *help)
{
    for (int i = 0; i < NBR_HELP_IMG; i += 1)
        destroy_sprite(&help->spriteHelp[i]);
    free(help->spriteHelp);
    free(help);
}

void how_to_play(window_t *window)
{
    how_to_t *help = malloc(sizeof(how_to_t));

    create_how_to_play(help);
    while (help->state != END) {
        sfRenderWindow_clear(window->window, sfWhite);
        how_to_analyse_event(help);
        how_to_display(window, help);
        sfRenderWindow_display(window->window);
        if (help->nbr_where == NBR_STRING - 1)
            help->state = END;
    }
    destroy_how_to_play(help);
}