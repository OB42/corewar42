# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2018/04/12 18:55:44 by rthys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all every clean fclean re corewar asm

NAME = every

all:	$(NAME)

$(NAME): corewar asm

corewar:
	make -C ./vm_dir/

asm:
	make -C ./asm_dir/

clean:
	make -C ./vm_dir/ clean
	make -C ./asm_dir/ clean

fclean:
	make -C ./vm_dir/ fclean
	make -C ./asm_dir/ fclean

re: fclean all
