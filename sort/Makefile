# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    katasub                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 08:34:28 by alexwern          #+#    #+#              #
#    Updated: 2022/09/16 13:17:03 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#0 = name of the project, 1 = sources
NAME	= sort.exe
FLAG	= -m64 -no-pie -Wall -Wextra -Werror
SRCFILE	= main.cpp sort.cpp 
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
LIBFT	= -L ../Libft/build -lft
# -lfmt
INCLS	= -I ./includes -I ../Libft/includes -I ./tests
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m
GCC		= g++

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
	@$(GCC) $(FLAG) -o $(NAME) $(INCLS) $(OBJ) $(LIBFT)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
