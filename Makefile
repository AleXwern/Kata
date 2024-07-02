# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:42:05 by alexwern          #+#    #+#              #
#    Updated: 2024/06/17 10:29:52 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= kata
TESTS	= buffer_test.exe 
FLAG	= -m64 -no-pie -std=c++17 -g
SRCFILE	= buffer_test.cpp 
REALMAIN= ./obj/main.o
TEST	= $(addprefix ./build/,$(TESTS))
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
CATCH	= ./obj/catch_amalgamated.o
LIBFT	= -L ./Libft/build -lft
INCLS	= -I ./includes -I ./Libft/includes -I ./tests -I ./buffer/includes -I ./catch2/extras
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m
TEMP0	= 0

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./tests/%.cpp
	@echo "Compiling $(GREEN)$@$(STOP)"
	@mkdir -p obj
	@g++ $(FLAG) -c $< -o $@ $(INCLS)

$(CATCH):
	@echo "Compiling $(GREEN)catch_amalgamated.o$(STOP)"
	@mkdir -p obj
	@g++ $(FLAG) -c ./catch2/extras/catch_amalgamated.cpp -o $(CATCH) $(INCLS)

./build/%.exe:./obj/%.o
	@echo "Compiling $(GREEN)$@$(STOP)"
	@mkdir -p build
	@g++ $(FLAG) -o $@ $(INCLS) -DREAL_MAIN=1 $< $(addprefix $(subst obj/,,$(subst _test.o,,$<))/,$(subst _test,,$<)) $(CATCH) $(LIBFT)

$(LIBFT):
	@make -C Libft

katas:
	@make -C buffer all

$(NAME): $(LIBFT) $(CATCH) $(OBJ) katas
	@echo "Building unit tests"
	@mkdir -p build
	g++ $(FLAG) -o ./build/buffer_test.exe $(INCLS) ./buffer/obj/buffer.o ./obj/buffer_test.o $(CATCH) $(LIBFT)
	@echo "buffer_test.exe"
	@./build/buffer_test.exe
	@echo "All done!"
clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj
	@make -C Libft clean
	@make -C buffer clean

fclean: clean
	@/bin/rm -rf ./build
	@make -C Libft fclean
	@make -C buffer fclean

re: fclean all