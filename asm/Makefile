# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2017/11/30 10:33:39 by obenazzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, asm, clean, fclean, re

CC = gcc -Wall -Wextra -Werror
NAME = asm
LFT_PATH = ./ft_printf/
SRC_NAME = asm.c get_next_line/get_next_line.c pr_malloc.c print_error.c
OBJ = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
