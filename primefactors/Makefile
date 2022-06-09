# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 08:34:28 by alexwern          #+#    #+#              #
#    Updated: 2022/06/09 13:40:45 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= primefactors.exe
FLAG	= -m64 -no-pie -Wall -Wextra -Werror
SRCFILE	= primefactors.cpp main.cpp
SRC		= $(addprefix ./src/,$(SRCFILE))
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
LIBFT	= ../Libft_ASM/Libft_ASM.a
INCLS	= -I ./includes -I ../Libft_ASM -I ./tests
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./src/%.cpp
	@echo "Compiling $(GREEN)$@$(STOP)"
	@mkdir -p obj
	@g++ $(FLAG) -c $< -o $@ $(INCLS) -lfmt

./obj/%.o:./src/%.c
	@echo "Compiling $(GREEN)$@$(STOP)"
	@mkdir -p obj
	@gcc $(FLAG) -c $< -o $@ $(INCLS)

$(NAME): $(OBJ)
	@echo "Building $(PURPLE)$(NAME)$(STOP)"
	@g++ $(FLAG) -o $(NAME) $(INCLS) $(OBJ) $(LIBFT) -lfmt

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all