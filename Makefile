##
## EPITECH PROJECT, 2019
## MUL_my_defender
## File description:
## Makefile
##

SRC	=	src/main.c					\
		src/overworld/load_evts.c			\
		src/overworld/read_evt.c			\
		src/overworld/read_map.c			\
		src/overworld/put_special_grounds.c		\
		src/overworld/draw_game.c			\
		src/overworld/game_obj_fcts.c			\
		src/overworld/collisions.c			\
		src/overworld/analyse_events.c			\
		src/overworld/input_react.c			\
		src/overworld/move_characters.c			\
		src/overworld/move_npc.c			\
		src/overworld/create_overworld.c		\
		src/overworld/misc.c				\
		src/overworld/animate.c				\
		src/overworld/unload_map.c			\
		src/overworld/animate_ground.c			\
		src/overworld/animate_characters.c		\
		src/overworld/check_can_go.c			\
		src/overworld/npc_move_fcts.c			\
		src/overworld/load_npc.c			\
		src/overworld/destroy_game.c			\
		src/overworld/sub_destroy_game.c		\
		src/overworld/load_quests.c			\
		src/overworld/save_quests.c			\
		src/overworld/load_character.c			\
		src/overworld/load_pkmns.c			\
		src/overworld/save_character.c			\
		src/overworld/save_pkmn.c			\
		src/overworld/save_npc.c			\
		src/overworld/save_game.c			\
		src/overworld/interact.c			\
		src/overworld/sub_interact.c			\
		src/overworld/music_fcts.c			\
		src/overworld/save_items.c			\
		src/overworld/load_items.c			\
		src/overworld/activate_evt.c			\
		src/overworld/sub_activate_event.c		\
		src/overworld/save_evts.c			\
		src/overworld/sub_save_evts.c			\
		src/overworld/sub_draw_game.c			\
		src/overworld/load_map.c			\
		src/overworld/sort_objects.c			\
		src/overworld/sub_sort_list.c			\
		src/basics/my_strlen.c				\
		src/basics/string_array_fcts.c			\
		src/basics/my_strdup.c				\
		src/basics/my_strcmp.c				\
		src/basics/my_str_to_word_array.c		\
		src/basics/my_getnbr.c				\
		src/basics/word_array_fcts.c			\
		src/basics/my_score.c				\
		src/basics/my_strcpy.c				\
		src/basics/useful_fct.c				\
		src/basics/tools_two.c					\
		lib_CSFML/window_functions.c			\
		lib_CSFML/clock_functions.c			\
		lib_CSFML/sound_functions.c			\
		lib_CSFML/text_functions.c			\
		lib_CSFML/value_structs.c			\
		lib_CSFML/sprite_functions.c			\
		src/feature/display_text.c			\
		src/feature/loop.c				\
		src/feature/display.c				\
		src/feature/do_text.c				\
		src/feature/set_text.c				\
		src/feature/check_cpt.c				\
		src/feature/set_to_base.c			\
		src/menu/bouton_tools.c				\
		src/menu/condition_gender.c			\
		src/menu/condition_save.c			\
		src/menu/display_menu.c				\
		src/menu/menu_button.c				\
		src/menu/menu_tools.c				\
		src/menu/condition_back.c			\
		src/menu/condition_left_right.c			\
		src/menu/condition_scale.c			\
		src/menu/condition_frame.c			\
		src/menu/condition_volume.c			\
		src/menu/config_option.c			\
		src/menu_game/analyse_menu_game.c		\
		src/menu_game/create_menu_game.c		\
		src/menu_game/destroy_menu_game.c 		\
		src/menu_game/display_menu_game.c		\
		src/menu_game/menu_game.c			\
		src/menu_game/pokemon/analyse_pokemon_bag.c 	\
		src/menu_game/pokemon/create_pokemon_bag.c	\
		src/menu_game/pokemon/destroy_pokemon_bag.c 	\
		src/menu_game/pokemon/display_pokemon_bag.c 	\
		src/menu_game/pokemon/fn_item.c 		\
		src/menu_game/pokemon/menu_pokemon.c		\
		src/quest_list/quest.c				\
		src/pokedex/pokedex.c				\
		src/pokedex/pokedex_name.c			\
		src/how_to_play/how_to_play.c		\
		src/combat/main_cbt.c			\

SRC_T		=

NAME		=	my_rpg

TESTS_NAME	=	tests_run

CC			=	gcc

CFLAGS		=	-I./include -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm -I./lib_CSFML/include

CPPFLAGS	+=	-Wall -Wextra

TEST_FLAGS	=	-lcriterion --coverage

RM			=	rm -f

RED			=	'\033[1;31m'

GREEN		=	'\033[5;92m'

N_COLOR		=	'\033[1;0m'

all			:	$(NAME)

$(NAME) 	:
			@$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS)
			@echo -e $(GREEN)[OK]$(N_COLOR)

tests_run 	:
			@$(CC) $(SRC_T) -o $(TESTS_NAME) $(CPPFLAGS) $(TEST_FLAGS)
			@./$(TESTS_NAME)

clean 		:
			@echo -e $(RED)============= Cleaning ==============$(N_COLOR)
			@echo -e $(RED)[OK]$(N_COLOR)

tests_clean :
			@echo -e $(RED)========== Cleaning : TEST ==========$(N_COLOR)
			$(RM) *.gcda *.gcno test_run
			@echo -e $(RED)[OK]$(N_COLOR)

fclean 		:
			@echo -e $(RED)========= Cleaning : FINAL ==========$(N_COLOR)
			$(RM) *.gcda *.gcno test_run
			$(RM) $(NAME) $(TESTS_NAME)
			@echo -e $(RED)[OK]$(N_COLOR)

re 			:	fclean all
				@rm -rf $(OBJ)
				@rm -rf src/*~

.PHONY 		:	all clean fclean re tests_run tests_clean
