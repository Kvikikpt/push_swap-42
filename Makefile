# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 14:46:44 by cnikia            #+#    #+#              #
#    Updated: 2019/09/27 19:39:22 by cnikia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

SRC_SWP = struct.c push_swap.c main_funct.c error_exit.c commands.c stack_fill.c com_one.c com_two.c com_three.c extern_funct.c bonus.c

SRC_CHECKER = struct.c checker.c error_exit.c commands.c stack_fill.c com_one.c com_two.c com_three.c bonus.c extern_funct.c main_funct.c

INCLUDES = push_swap.h

OBJ_SWP = $(SRC_SWP:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

LIB = ./libft/libft.a

all: lib $(CHECKER) $(PUSH_SWAP) clean

lib:
	@make -C libft re
	@make -C libft clean

$(CHECKER): $(OBJ_CHECKER)
	gcc -Wall -Werror -Wextra -g -o $(CHECKER) $(OBJ_CHECKER) $(LIB)

$(PUSH_SWAP): $(OBJ_SWP)
	gcc -Wall -Werror -Wextra -g -o $(PUSH_SWAP) $(OBJ_SWP) $(LIB)

%.o: %.c $(INCLUDES)
	gcc -Wall -Werror -Wextra -c $<

clean:
	/bin/rm -f $(OBJ_CHECKER)
	/bin/rm -f $(OBJ_SWP)
	/bin/rm -f #*#
	/bin/rm -f *~
	/bin/rm -f *.gch
	@make -C libft clean

fclean: clean
	/bin/rm -f $(CHECKER)
	/bin/rm -f $(PUSH_SWAP)
	@make -C libft fclean

re: fclean all
	/bin/rm -f $(OBJ_CHECKER)
	/bin/rm -f $(OBJ_SWP)
