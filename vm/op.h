/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:25:17 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/19 12:23:48 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * les tailles sont en octets.
 * ** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
 * */
#ifndef OP_H
# define OP_H

# include "LIBFT/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define IND_SIZE	2
# define REG_SIZE	4
# define DIR_SIZE	REG_SIZE


# define REG_CODE	1
# define DIR_CODE	2
# define IND_CODE	3

# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE		(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE	(MEM_SIZE / 6)

# define COMMENT_CHAR	'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR	','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define REG_NUMBER		16

# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA		50
# define NBR_LIVE		21
# define MAX_CHECKS		10

/**
 *  ***
 *   **/

typedef char	t_arg_type;

# define T_REG		1
# define T_DIR		2
# define T_IND		4
# define T_LAB		8

/**
 * ***
 * **/

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct s_proc	t_proc;

typedef struct s_ins	t_ins;

typedef struct	s_par
{
	int type;
	int val_type;
	int value;
}				t_par;

struct	s_ins
{
	char	*name;
	int		ocp;
	int		param[3];
	t_par	tab[3];
	void	(*fun)(t_ins*, t_proc*);
	int		size;
	int		cycle;
	int		nb_param;
};

typedef	struct	s_op
{
	char	*name;
	int		nb_param;
	int		param[3];
	int		length;
	int		ocp;
	int		size_no_ocp;
	void	(*fun)(t_ins*, t_proc*);
}				t_op;

typedef struct	header_s
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}
header_t;

typedef struct	s_champ
{
	header_t		header;
	unsigned char	*code;
	int				placed;
	int				color;
	unsigned int	rank;
}				t_champ;

typedef struct	s_corewar
{
	char			arena_id[MEM_SIZE + 1];
	unsigned char	arena[MEM_SIZE + 1];
	int				nb_champ;
	t_champ			tab_champ[6];
	int				ctd_obj;
	int				ctd_cur;
	int				nb_live;
	int				cycle;
	int				check;
	int				last_live_id;
	unsigned int	n_rank;
	unsigned int	a_rank;
	int				select;
	unsigned int	dump;

}				t_corewar;

struct	s_proc
{
	int				id;
	int				pc;
	t_ins			*ins;
	unsigned char	*curseur;
	int				cycle;
	unsigned char	*init;
	int				carry;
	int				player;
	int				live;
	int				last_live;
	t_corewar		*corewar;
	t_champ			champ;
	int				reg[REG_NUMBER + 1];
	int				success;
	struct s_proc	*nxt;
};

void			*pr_malloc(size_t n);
void			pr_free(void *p);
header_t		ft_get_header(int fd);
t_champ			ft_get_champ(char *filename, t_corewar *corewar);
void			ft_get_var(t_proc *proc, unsigned char *code_champ, unsigned char *init);
t_ins			*ft_get_instru(unsigned char *code_champ, unsigned char *init);
int				ft_get_int(unsigned char *code_champ, int size);
unsigned char	*ft_get_ind(t_ins *ins, unsigned char *curseur, int n_param, unsigned char *init);
unsigned char	*ft_get_dir(t_ins *ins, unsigned char *curseur, int n_param, unsigned char *init);
unsigned char	*ft_get_reg(t_proc *proc, unsigned char *curseur, int n_param, unsigned char *init);
int				ft_loop(t_corewar *corewar);
void			ft_live(t_ins *ins, t_proc *proc);
void			ft_ld(t_ins *ins, t_proc *proc);
void			ft_st(t_ins	*ins, t_proc *proc);
void			ft_ldi(t_ins *ins, t_proc *proc);
void			ft_sti(t_ins *ins, t_proc *proc);
void			ft_fork(t_ins *ins, t_proc *proc);
void			ft_sub(t_ins *ins, t_proc *proc);
void			ft_add(t_ins *ins, t_proc *proc);
void			ft_aff(t_ins *ins, t_proc *proc);
void			load_arena(t_corewar *corewar);
void			ft_print_arena(unsigned char *arena);
void			ft_lfork(t_ins *ins, t_proc *proc);
void			ft_lldi(t_ins *ins, t_proc *proc);
void			ft_lld(t_ins *ins, t_proc *proc);
void			ft_and(t_ins *ins, t_proc *proc);
void			ft_or(t_ins *ins, t_proc *proc);
void			ft_xor(t_ins *ins, t_proc *proc);
void			ft_zjmp(t_ins *ins, t_proc *proc);
void			ft_print_instru(t_proc *lst_proc);
unsigned char	*ft_oob(unsigned char *init, unsigned char *dest);
int				ft_addlim(int decal);
void			ft_print_proc(t_proc *proc);
int				ft_get_procnb(t_proc *proc);
void			ft_verbose(t_proc *proc);
void			ft_write_ram(int value, int size, unsigned char *ram, t_proc *proc);
t_proc			*ft_del(t_proc *proc);
t_proc			*ft_cycle_to_die(t_corewar *corewar, t_proc *proc);
int				ft_val_ocp(int ocp, int param);
void			ft_print_ocp(t_proc *proc, int param1, int param2, int param3);
int				ft_conv(int value, t_proc *proc);
void			ft_print_nxt(unsigned char *init, unsigned char *curseur, int size);
void			ft_update_ins(unsigned char *code_champ, unsigned char *init, t_proc *proc);
void			ft_output_arena(t_corewar *corewar);
void			who_win(t_corewar *corewar);
int				ft_decal(unsigned char *init, unsigned char *curseur, int decal);
int				nbr_champs(int argc, char **argv);
void			error_end(char *error, int id_error, char *info);
int				get_options(int i, char **av, t_corewar *corewar);
void			ft_valid_champ(int fd, char *filename);

#endif
