# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2018/04/12 21:32:04 by rthys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all every clean fclean re corewar asm

NAME = every

all:	$(NAME)


$(NAME): corewar asm

corewar: libcor
	make -C ./vm_dir/

asm: libasm
	make -C ./asm_dir/

libasm:
	make -C ./asm_dir/libft/

libcor:
	make -C ./vm_dir/libft/

clean:
	make -C ./vm_dir/ clean
	make -C ./asm_dir/ clean

fclean:
	make -C ./vm_dir/ fclean
	make -C ./asm_dir/ fclean

re: fclean all
