# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:42:05 by alexwern          #+#    #+#              #
#    Updated: 2022/06/06 10:02:19 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= kata
TESTS	= wordwrap_test.exe romannumerals_test.exe
FLAG	= -m64 -no-pie -Wall -Wextra -Werror
SRCFILE	= wordwrap_test.cpp romannumerals_test.cpp
REALMAIN= obj/main.o
TEST	= $(addprefix ./build/,$(TESTS))
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
CATCH	= obj/catch_amalgamated.o
LIBFT	= Libft_ASM/Libft_ASM.a
INCLS	= -I ./includes -I Libft_ASM -I ./tests -I wordwrap/includes -I romannumerals/includes
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m
TEMP0	= 0

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./tests/%.cpp
	@mkdir -p obj
	@g++ $(FLAG) -c $< -o $@ $(INCLS)

./build/%.exe:./obj/%.o
	@mkdir -p build
	@g++ $(FLAG) -o $@ $(INCLS) $< $(addprefix $(subst obj/,,$(subst _test.o,,$<))/,$(subst _test,,$<)) $(CATCH) $(LIBFT)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C Libft_ASM
	@make -C ft_malloc

katas:
	@make -C wordwrap all
	@make -C romannumerals all
	@make -C primefactors all

$(NAME): $(LIBFT) $(CATCH) $(OBJ) katas
	@mkdir -p build
	@g++ $(FLAG) -o build/wordwrap_test.exe $(INCLS) obj/wordwrap_test.o wordwrap/obj/wordwrap.o $(CATCH) $(LIBFT)
	@g++ $(FLAG) -o build/romannumerals_test.exe $(INCLS) obj/romannumerals_test.o romannumerals/obj/romannumerals.o $(CATCH) $(LIBFT)

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