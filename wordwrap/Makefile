# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 08:34:28 by alexwern          #+#    #+#              #
#    Updated: 2022/03/17 13:19:50 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wordwrap.exe
FLAG	= -no-pie -O1
SRCFILE	= main.cpp wordwrap.cpp
SRC		= $(addprefix ./src/,$(SRCFILE))
OBJ	= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
LIBFT	= ../Libft_ASM/Libft_ASM.a
INCLS	= -I ./includes -I ../Libft_ASM
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./src/%.cpp
	@mkdir -p obj
	g++ $(FLAG) -c $< -o $@ $(INCLS)

./obj/%.o:./src/%.c
	@mkdir -p obj
	gcc $(FLAG) -c $< -o $@ $(INCLS)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C ../Libft_ASM

$(NAME): $(LIBFT) $(OBJ)
	g++ $(FLAG) -o $(NAME) $(INCLS) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf ./obj

fclean: clean
	make -C ../Libft_ASM fclean
	/bin/rm -f $(NAME)

re: fclean all