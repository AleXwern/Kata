# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:42:05 by alexwern          #+#    #+#              #
#    Updated: 2022/04/22 14:06:01 by alexwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= kata
TESTS	= wordwrap_test.exe
FLAG	= -m64 -no-pie
SRCFILE	= wordwrap_test.cpp romannumerals_test.cpp
REALMAIN= obj/main.o
TEST	= $(addprefix ./build/,$(TESTS))
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
CATCH	= obj/catch_amalgamated.o
LIBFT	= Libft_ASM/Libft_ASM.a
INCLS	= -I ./includes -I Libft_ASM -I ./tests -I */includes
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m
TEMP0	= 0

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./tests/%.cpp
	@mkdir -p obj
	g++ $(FLAG) -c $< -o $@ $(INCLS)

./build/%.exe:./obj/%.o
	@mkdir -p build
	g++ $(FLAG) -o $@ $(INCLS) $< $(addprefix $(subst obj/,,$(subst _test.o,,$<))/,$(subst _test,,$<)) $(CATCH) $(LIBFT)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C Libft_ASM

katas:
	make -C wordwrap all
	make -C romannumerals all

$(NAME): $(LIBFT) $(CATCH) $(OBJ) katas
	@mkdir -p build
	for f in $(SRCFILE); do \
		TEMP0 = $(subst _test.cpp,,$${f}); \
		echo $(TEMP); \
	done
#g++ $(FLAG) -o build/wordwrap_test.exe $(INCLS) obj/wordwrap_test.o wordwrap/obj/wordwrap.o $(CATCH) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf ./obj
	make -C Libft_ASM clean
	make -C wordwrap clean
	make -C romannumerals clean

fclean: clean
	make -C Libft_ASM fclean
	make -C wordwrap fclean
	make -C romannumerals fclean

re: fclean all