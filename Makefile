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

NAME = corewar

.PHONY: all, clean, $(NAME), fclean, re

all: $(NAME)

$(NAME):
	make -C ./asm
	make -C ./vm

clean:
	make -C ./vm clean
	make -C ./asm clean

fclean:
	make -C ./vm fclean
	make -C ./asm fclean

re: fclean all
