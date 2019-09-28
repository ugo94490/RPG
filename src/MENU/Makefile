##
## EPITECH PROJECT, 2019
## MUL_my_defender
## File description:
## Makefile
##

SRC	=	main.c	\
		display_menu.c	\
		bouton_tools.c	\
		menu_button.c	\
		menu_tools.c	\
		condition_gender.c	\
		condition_save.c	\
		../../lib_CSFML/window_functions.c	\

SRC_T		=

NAME		=	my_rpg

TESTS_NAME	=	tests_run

CC			=	gcc

CFLAGS		=	-I../../include -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm -I../../lib_CSFML/include/

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
