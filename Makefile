# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2018/04/11 12:36:06 by rthys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, every, clean, fclean, re, corewar, asm

NAME = every

all:	$(NAME)

$(NAME): corewar asm

corewar:
	make -C ./vm/

asm:
	make -C ./asm/

clean:
	make -C ./vm/ clean
	make -C ./asm/ clean

fclean:
	make -C ./vm/ fclean
	make -C ./asm/ fclean

re: fclean all
