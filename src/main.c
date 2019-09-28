/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <time.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"
#include "main_menu.h"

void temp_loop(window_t *window, sfVector2f *scale, int flag, int gender)
{
    clock_sf clock = create_clock();
    game_t game = create_game(flag, gender);

    if (game.view == NULL || game.objects == NULL ||
        game.sprites == NULL || game.character == NULL)
        return;
    game.window = window;
    sfRenderWindow_setFramerateLimit(window->window, 60);
    while (sfRenderWindow_isOpen(window->window)) {
        clock.time = sfClock_getElapsedTime(clock.clock);
        sfClock_restart(clock.clock);
        animate_objects(&game);
        move_objects(game.objects, clock.time);
        analyse_event(window, &game);
        set_view_params(window, &game, *scale);
        draw_game(window, &game);
    }
    destroy_clock(&clock);
    destroy_game(&game);
}

void init_game(void)
{
    sfVector2f scale = {0.5, 0.5};
    window_t window = create_window(1280*scale.x, 960*scale.y, 32, "MY_RPG");

    window.scale = scale;
    display_menu(&window, &scale);
    sfRenderWindow_destroy(window.window);
}

int main(int ac, char **av, char **env)
{
    if (env == NULL || env[0] == NULL)
        return (84);
    (void) ac;
    (void) av;
    srand(time(0));
    init_game();
    return (0);
}
