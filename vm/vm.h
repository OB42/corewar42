/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:06:03 by rthys             #+#    #+#             */
/*   Updated: 2018/03/06 16:20:20 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct		s_op
{
	char			*code;
	char			*type;
	int				params[4];
}					t_op;

typedef struct		s_champs
{
	char			*until;
	char			*filename;
	char			*name;
	char			*comment;
	int				reg[REG_NUMBER];
	int				size;
	int				color;
	int				placed;
	int				adress;
	int				start;
	int				pc;
	int				carry;
	int				len;
}					t_champs;

typedef struct		s_corewar
{
	char			arena[(4*MEM_SIZE) + 1];
	char			arena_id_champs[MEM_SIZE + 1];
	char			**map;
	int				nb_champs;
	t_champs		champ[6];
	t_champs		*last_champ;
	int				last_live_champ;
	int				cycle_to_die_current;
}					t_corewar;

void				init_arena(t_corewar *corewar, int size, int value);
int					load_arena(t_corewar *corewar);
void				place_champs(t_corewar *corewar, int id);
int					load_champs(t_corewar *corewar);
void				ft_print_map(char *arena);
void				init_all(t_corewar *corewar);
int					get_name_comment_champ(t_champs *champs, int *fd);

#endif
