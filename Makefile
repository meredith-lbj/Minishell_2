##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No file there, just an epitech header example
##

CC = gcc

D_SRC = ./src/
D_BUILTIN = ./builtin/
D_CD = ./cd/
D_ENV = ./env/
D_EXIT = ./exit/
D_SETENV = ./setenv/
D_UNSETENV = ./unsetenv/
D_EXEC = ./exec/
D_OPERATOR = ./operator/
D_ERRORS = ./errors/
D_PIPE = ./pipe/
D_REDIRECTIONS = ./redirections/
D_SEMICOLON = ./semicolon/

SRC	=	$(D_SRC)/mysh.c	\
		$(D_SRC)/get_commands.c	\
		$(D_SRC)/space_count.c	\
		$(D_SRC)/count_chr.c	\
		$(D_SRC)/move.c	\
		$(D_SRC)/check_start.c	\
		$(D_SRC)/find_my_chr.c	\
		$(D_SRC)/fix_space.c	\
		$(D_SRC)/print_helper.c	\
		$(D_SRC)/$(D_BUILTIN)/exec_builtin.c	\
		$(D_SRC)/$(D_BUILTIN)/command_not_found.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_ENV)/create_env.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_ENV)/free_list.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_ENV)/print_env.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_ENV)/get_name.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_ENV)/get_value.c	\
		$(D_SRC)/$(D_BUILTIN)/builtin_list.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_EXIT)/exit_builtin.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_UNSETENV)/unsetenv_builtin.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_SETENV)/check_var.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_SETENV)/setenv_builtin.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_CD)/cd_builtin.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_CD)/get_way.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_CD)/prev_directory.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_CD)/change_dir.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_CD)/check_access.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_CD)/check_dir_perms.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_EXEC)/exec_command.c    \
		$(D_SRC)/$(D_BUILTIN)/$(D_EXEC)/swap_way.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_EXEC)/get_path.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_EXEC)/get_binary.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_EXEC)/execut.c	\
		$(D_SRC)/$(D_BUILTIN)/$(D_EXEC)/get_2d_env.c	\
		$(D_SRC)/$(D_OPERATOR)/find_operator.c	\
		$(D_SRC)/$(D_OPERATOR)/find_redirections.c	\
		$(D_SRC)/$(D_OPERATOR)/check_ope.c	\
		$(D_SRC)/$(D_OPERATOR)/calcul_operator.c	\
		$(D_SRC)/$(D_OPERATOR)/exec_operator.c	\
		$(D_SRC)/$(D_OPERATOR)/fix_operator.c	\
		$(D_SRC)/$(D_OPERATOR)/parse_commands.c	\
		$(D_SRC)/$(D_OPERATOR)/create_parse.c	\
		$(D_SRC)/$(D_OPERATOR)/delete_node.c	\
		$(D_SRC)/$(D_OPERATOR)/free_parse.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_ERRORS)/find_letter.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_ERRORS)/semicolon_error.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_ERRORS)/double_quotes_error.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_ERRORS)/quotes_error.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_ERRORS)/pipe_error.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_SEMICOLON)/exec_semicolon.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_REDIRECTIONS)/init_redirect.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_REDIRECTIONS)/redirections.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_REDIRECTIONS)/reset_fd.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_PIPE)/exec_pipe.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_PIPE)/count_pipe.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_PIPE)/check_exit.c	\
		$(D_SRC)/$(D_OPERATOR)/$(D_PIPE)/my_pipe.c

INCLUDE	=        -I include/

LIB =	-L./ -lmy

OBJ	=	$(SRC:.c=.o)

CFLAGS =	-W -Wall -Wextra

NAME =	mysh

CRITERION = -lcriterion --coverage

all:	GCC

%.o:	%.c
	$(CC) $(INCLUDE) -g -c $< -o $@

GCC:	$(OBJ)
	$(MAKE) -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(INCLUDE) $(CFLAGS)

debug:	$(OBJ)
	$(MAKE) -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(INCLUDE) -g $(CFLAGS)

clean:
	$(MAKE) -C lib/ clean
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) -C lib/ fclean
	rm -f $(NAME)

re:	fclean debug

unit_tests:
	$(CC) -o unit_tests tests/test_bubble_sort_array.c src/pushswap.c $(INCLUDE) $(LIB) $(CRITERION)

run_tests:	libmy.a unit_tests
	./unit_tests

.PHONY:	libmy.a GCC CC NAME CRITERION
