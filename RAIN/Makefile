##
## EPITECH PROJECT, 2019
## MUL_my_defender
## File description:
## Makefile
##

SRC	=	main.c				\
		../UGO/useful_fct.c			\
		../lib_CSFML/clock_functions.c	\
		../lib_CSFML/sound_functions.c	\
		../lib_CSFML/text_functions.c	\
		../lib_CSFML/window_functions.c	\
		../lib_CSFML/sprite_functions.c	\
		../lib_CSFML/value_structs.c	\
		tools_two.c			\
		../src/basics/my_strlen.c	\

SRC_T		=

NAME		=	my_rpg

TESTS_NAME	=	tests_run

CC			=	gcc

CFLAGS		=	-I../include -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm -I./lib_CSFML/include -g3 -I../lib_CSFML/include

CPPFLAGS	+=

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
