NAME = corewar

SRC = main.c\
	  ft_get_champ.c\
	  ft_get_instru.c\
	  ft_get_int.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C LIBFT
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L. LIBFT/libft.a

$(FT_PRINTF):
	make all -C LIBFT

%.o : %.c
	gcc -o $@ -c $< -g -Wall -Wextra -Werror

clean :
	rm -rf *.o
	make clean -C LIBFT

fclean : clean 
	rm -rf $(NAME)
	make fclean -C LIBFT

re :	
	make fclean
	make
