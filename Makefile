##
## EPITECH PROJECT, 2019
## MUL_my_defender
## File description:
## Makefile
##

SRC	=	src/main.c				\
		src/overworld/read_evt.c		\
		src/overworld/read_map.c		\
		src/overworld/put_special_grounds.c	\
		src/overworld/draw_game.c		\
		src/overworld/game_obj_fcts.c		\
		src/overworld/collisions.c		\
		src/overworld/analyse_events.c		\
		src/overworld/input_react.c		\
		src/overworld/move_characters.c		\
		src/overworld/move_npc.c		\
		src/overworld/create_overworld.c	\
		src/overworld/misc.c			\
		src/overworld/animate.c			\
		src/overworld/unload_map.c		\
		src/overworld/animate_ground.c		\
		src/overworld/animate_characters.c	\
		src/overworld/check_can_go.c		\
		src/overworld/npc_move_fcts.c		\
		src/overworld/load_npc.c		\
		src/overworld/destroy_game.c		\
		src/overworld/sub_destroy_game.c	\
		src/overworld/load_character.c		\
		src/overworld/load_pkmns.c		\
		src/basics/my_strlen.c			\
		src/basics/string_array_fcts.c		\
		src/basics/my_strdup.c			\
		src/basics/my_strcmp.c			\
		src/basics/my_str_to_word_array.c	\
		src/basics/my_getnbr.c			\
		src/basics/word_array_fcts.c		\
		UGO/useful_fct.c			\
		UGO/main_cbt.c				\
		UGO/tools_two.c				\
		lib_CSFML/window_functions.c		\
		lib_CSFML/clock_functions.c		\
		lib_CSFML/sound_functions.c		\
		lib_CSFML/text_functions.c		\
		lib_CSFML/value_structs.c		\
		lib_CSFML/sprite_functions.c		\
		src/feature/display_text.c

SRC_T		=

NAME		=	my_rpg

TESTS_NAME	=	tests_run

CC			=	gcc

CFLAGS		=	-I./include -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm -I./lib_CSFML/include -I./src/feature -g3

CPPFLAGS	+=	-Wall -Wextra -Wmissing-field-initializers

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
