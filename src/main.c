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
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void temp_loop(window_t *window, sfVector2f *scale, game_t *game)
{
    clock_sf clock = create_clock();

    sfRenderWindow_setFramerateLimit(window->window, 60);
    while (sfRenderWindow_isOpen(window->window)) {
        clock.time = sfClock_getElapsedTime(clock.clock);
        sfClock_restart(clock.clock);
        animate_objects(game);
        move_objects(game->objects, clock.time);
        analyse_event(window, game);
        set_view_params(window, game, *scale);
        draw_game(window, *scale, game);
    }
}

void init_game()
{
    window_t window = create_window(1280, 960, 32, "poukiman");
    sfVector2f scale = {1.0, 1.0};
    game_t game = create_game();

    temp_loop(&window, &scale, &game);
}

int main(int ac, char **av, char **env)
{
    if (env == NULL || env[0] == NULL)
        return (84);
    init_game();
    return (0);
}
