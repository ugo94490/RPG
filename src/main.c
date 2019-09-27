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
        draw_game(window, game);
    }
    destroy_clock(&clock);
}

void init_game(void)
{
    window_t window = create_window(1280*0.5, 960*0.5, 32, "poukiman");
    sfVector2f scale = {1, 1};
    game_t game = create_game(1);

    if (game.view == NULL || game.objects == NULL ||
    game.sprites == NULL || game.character == NULL)
        return;
    window.scale = scale;
    game.window = &window;
    temp_loop(&window, &scale, &game);
    destroy_game(&game);
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
