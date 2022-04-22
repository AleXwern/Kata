# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 08:34:28 by alexwern          #+#    #+#              #
#    Updated: 2022/04/22 13:26:31 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= romannumerals.exe
FLAG	= -m64 -no-pie
SRCFILE	= main.c romannumerals.c
OBJ		= $(addprefix ./obj/,$(SRCFILE:.c=.o))
LIBFT	= ../Libft_ASM/Libft_ASM.a
INCLS	= -I ./includes -I ../Libft_ASM -I ./tests
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

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(INCLS) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf ./obj

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all