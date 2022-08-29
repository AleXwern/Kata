# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:42:05 by alexwern          #+#    #+#              #
#    Updated: 2022/08/29 13:23:50 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= kata
TESTS	= wordwrap_test.exe romannumerals_test.exe primefactors_test.exe queue_test.exe
FLAG	= -m64 -no-pie -Wall -Wextra -Werror -std=c++17
SRCFILE	= wordwrap_test.cpp romannumerals_test.cpp primefactors_test.cpp queue_test.cpp
REALMAIN= obj/main.o
TEST	= $(addprefix ./build/,$(TESTS))
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
CATCH	= obj/catch_amalgamated.o
LIBFT	= -L ./Libft/build -lft
INCLS	= -I ./includes -I Libft/includes -I ./tests -I wordwrap/includes -I romannumerals/includes -I primefactors/includes -I queue/includes -I catch2/extras
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
	@g++ $(FLAG) -o $@ $(INCLS) $< $(addprefix $(subst obj/,,$(subst _test.o,,$<))/,$(subst _test,,$<)) $(CATCH) $(LIBFT)

$(LIBFT):
	@make -C Libft

katas:
	@make -C wordwrap all
	@make -C romannumerals all
	@make -C primefactors all
	@make -C queue all

$(NAME): $(LIBFT) $(CATCH) $(OBJ) katas
	@echo "Building unit tests"
	@mkdir -p build
	@g++ $(FLAG) -o build/wordwrap_test.exe $(INCLS) obj/wordwrap_test.o wordwrap/obj/wordwrap.o $(CATCH) $(LIBFT)
	@g++ $(FLAG) -o build/romannumerals_test.exe $(INCLS) obj/romannumerals_test.o romannumerals/obj/romannumerals.o $(CATCH) $(LIBFT)
	@g++ $(FLAG) -o build/primefactors_test.exe $(INCLS) obj/primefactors_test.o primefactors/obj/primefactors.o $(CATCH) $(LIBFT)
	@g++ $(FLAG) -o build/queue_test.exe $(INCLS) obj/queue_test.o queue/obj/queue.o $(CATCH) $(LIBFT)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj
	@make -C Libft clean
	@make -C wordwrap clean
	@make -C romannumerals clean
	@make -C primefactors clean
	@make -C queue clean

fclean: clean
	@/bin/rm -rf ./build
	@make -C Libft fclean
	@make -C wordwrap fclean
	@make -C romannumerals fclean
	@make -C primefactors fclean
	@make -C queue fclean

re: fclean all