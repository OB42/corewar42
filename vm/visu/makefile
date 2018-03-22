NAME = corewar

SRC = main.c\
	  ft_get_champ.c\
	  ft_get_instru.c\
	  ft_get_int.c\
	  ft_get_indireg.c\
	  ft_loop.c\
	  ft_live.c\
	  ft_ld.c\
	  ft_st.c\
	  load_arena.c\
	  ft_print_arena.c\
	  ft_ldi.c\
	  ft_sti.c\
	  ft_add.c\
	  ft_sub.c\
	  ft_fork.c\
	  ft_andorxor.c\
	  ft_zjmp.c\
	  ft_aff.c\
	  ft_oob.c\
	  ft_print_instru.c\
	  ft_addlim.c\
	  ft_print_proc.c\
	  ft_verbose.c\
	  ft_del.c\
	  ft_cycle_to_die.c\
	  ft_val_ocp.c\
	  ft_print_nxt.c\
	  ft_update_ins.c\
	  ft_output_arena.c\
	  pr_malloc.c\
	  error.c\
	  error_2.c\
	  options.c\
	  options2.c\
	  global_visu.c\
	  info_visu.c\


OBJ = $(SRC:.c=.o)

LIB = -L. LIBFT/libft.a -lncurses

FLAGS = -fsanitize=address -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C LIBFT
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

$(FT_PRINTF):
	make all -C LIBFT

%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -g

clean :
	rm -rf *.o
	make clean -C LIBFT

fclean : clean
	rm -rf $(NAME)
	make fclean -C LIBFT

re :
	make fclean
	make
