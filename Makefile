CC = gcc
FLAGS = -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a
NAME = minishell
SRC = src/main.c \
	src/get_next_line.c \
	src/builtins.c \
	src/sh_execute.c \
	src/init_env.c \
	src/init_shell.c \
	src/builtin_cd.c \
	src/check_bin_cmd.c \
	src/builtin_env.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME):$(LIBFT) $(NAME) $(OBJ)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(LIBFT)

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all