# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 08:34:28 by alexwern          #+#    #+#              #
#    Updated: 2022/06/13 12:04:57 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= romannumerals.exe
FLAG	= -m64 -no-pie -Wall -Wextra -Werror
SRCFILE	= main.c romannumerals.c rtoi.c
OBJ		= $(addprefix ./obj/,$(SRCFILE:.c=.o))
LIBFT	= -L ../Libft/build -lft
INCLS	= -I ./includes -I ../Libft/includes -I ./tests
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./src/%.cpp
	@echo "Compiling $(GREEN)$@$(STOP)"
	@mkdir -p obj
	@g++ $(FLAG) -c $< -o $@ $(INCLS)

./obj/%.o:./src/%.c
	@echo "Compiling $(GREEN)$@$(STOP)"
	@mkdir -p obj
	@gcc $(FLAG) -c $< -o $@ $(INCLS)

$(NAME): $(OBJ)
	@echo "Building $(PURPLE)$@$(STOP)"
	@gcc $(FLAG) -o $(NAME) $(INCLS) $(OBJ) $(LIBFT)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all