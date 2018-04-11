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

.PHONY: all, asm, corewar, clean, fclean, re

NAME = corewar

all:
	make -C ./asm
	make -C ./vm
corewar:
	make -C ./vm
asm:
	make -C ./asm
clean:
	make -C ./vm clean
	make -C ./asm clean
fclean:
	make -C ./vm fclean
	make -C ./asm fclean
re: fclean all
