# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:42:05 by alexwern          #+#    #+#              #
#    Updated: 2022/06/09 13:39:57 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= kata
TESTS	= wordwrap_test.exe romannumerals_test.exe primefactors_test.exe
FLAG	= -m64 -no-pie -Wall -Wextra -Werror
SRCFILE	= wordwrap_test.cpp romannumerals_test.cpp primefactors_test.cpp
REALMAIN= obj/main.o
TEST	= $(addprefix ./build/,$(TESTS))
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
CATCH	= obj/catch_amalgamated.o
LIBFT	= Libft_ASM/Libft_ASM.a
INCLS	= -I ./includes -I Libft_ASM -I ./tests -I wordwrap/includes -I romannumerals/includes -I primefactors/includes -I catch2/extras
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
	@make -C Libft_ASM
	@make -C ft_malloc

katas:
	@make -C wordwrap all
	@make -C romannumerals all
	@make -C primefactors all

$(NAME): $(LIBFT) $(CATCH) $(OBJ) katas
	@echo "Building unit tests"
	@mkdir -p build
	@g++ $(FLAG) -o build/wordwrap_test.exe $(INCLS) obj/wordwrap_test.o wordwrap/obj/wordwrap.o $(CATCH) $(LIBFT)
	@g++ $(FLAG) -o build/romannumerals_test.exe $(INCLS) obj/romannumerals_test.o romannumerals/obj/romannumerals.o $(CATCH) $(LIBFT)
	@g++ $(FLAG) -o build/primefactors_test.exe $(INCLS) obj/primefactors_test.o primefactors/obj/primefactors.o $(CATCH) $(LIBFT)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj
	@make -C Libft_ASM clean
	@make -C ft_malloc clean
	@make -C wordwrap clean
	@make -C romannumerals clean
	@make -C primefactors clean

fclean: clean
	@/bin/rm -rf ./build
	@make -C Libft_ASM fclean
	@make -C ft_malloc fclean
	@make -C wordwrap fclean
	@make -C romannumerals fclean
	@make -C primefactors fclean

re: fclean all