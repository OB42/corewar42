/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	*find_op(t_op op_tab[], char *name)
{
	int i;

	i = 0;
	while (op_tab[i].name)
	{
		if (!ft_strcmp(op_tab[i].name, name))
			return (&(op_tab[i]));
		i++;
	}
	print_error(ERR_UNKNOWN_OPERATION);
	return (0);
}

t_op	*get_op(char *name)
{
	static t_op    op_tab[17] =
	{
		{"live", 1, {T_DIR}, 1, -1, 0, 0},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, -1, 1, 0},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, -1, 1, 0},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, -1, 1, 0},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, -1, 1, 0},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, -1,
		1, 0},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, -1,
		1, 0},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, -1,
		 1, 0},
		{"zjmp", 1, {T_DIR}, 9, -1, 0, 1},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, -1,
		 1, 1},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, -1,
		 1, 1},
		{"fork", 1, {T_DIR}, 12, -1, 0, 1},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, -1, 1, 0},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, -1,
1, 1},
		{"lfork", 1, {T_DIR}, 15, -1, 0, 1},
		{"aff", 1, {T_REG}, 16, -1, 1, 0},
		{0, 0, {0}, 0, 0, 0, 0}
	};

	return (find_op(op_tab, name));
}

char 	get_ocp(char **op_arr, int o)
{
	char ocp;
	int a;
	char t;
	int n;

	n = ft_arrstrlen(op_arr - o);
	a = 0;
	ocp = 0;
	while (op_arr[o])
	{
		if (op_arr[o][0] == 'r')
			t = 1;
		else if (op_arr[o][0] == DIRECT_CHAR)
			t = 2;
		else
			t = 3;
		ocp += t << (6 - 2 * a);
		a++;
		o++;
	}
	return (ocp);
}

void save_bytes(header_t *header, char *champion, void *temp, int i)
{
	if (header->prog_size + i <= CHAMP_MAX_SIZE)
		ft_memcpy(champion + header->prog_size, temp, i);
	else
		print_error(ERR_CHAMPION_SIZE);
	header->prog_size += i;
}

void	parse_register(header_t *header, t_op *op, char *arg, char *champion)
{
	char	r;

	if (ft_strlen(arg) > 3 || !(arg[1]) || !ft_isdigit(arg[1])
	|| (arg[2] && !ft_isdigit(arg[2])))
		print_error(ERR_SYNTAX);
	r = ft_atoi(arg + 1);
	save_bytes(header, champion, &r, 1);
}

short swap16(short n)
{
	return (n << 8) | ((n >> 8) & 0xFF);
}

void	parse_direct(header_t *header, t_op *op, char *arg, char *champion, int spg)
{
	short	r;
	int		n;
	r = 0;
	n = 0;

	if (!(op->d2))
	{
		if (!ft_isdigit(arg[ft_strlen(arg) - 1]))
			print_error(ERR_SYNTAX);
		n = endian_swap_u32(ft_atoi(arg + 1));
		save_bytes(header, champion, &n, sizeof(int));
	}
	else if (arg[1] == LABEL_CHAR)
	{
		save_bytes(header, champion, &r, sizeof(short));
		add_label(champion, arg + 2, header->prog_size, 1, spg);
	}
	else
	{
		if (!ft_isdigit(arg[ft_strlen(arg) - 1]))
		{
			ft_printf("%s\nWTF", arg);
			print_error("THAT ONE\n");
			print_error(ERR_SYNTAX);
		}
		r = swap16(ft_atos(arg + 1));
		save_bytes(header, champion, &r, sizeof(short));
	}

}


void	parse_indirect(header_t *header, t_op *op, char *arg, char *champion, int spg)
{
	short	r;

	r = 0;
	if (arg[0] == LABEL_CHAR)
		add_label(champion, arg + 1, header->prog_size, 1, spg);
	else
		r = swap16(ft_atos(arg));
	save_bytes(header, champion, &r, sizeof(short));
}

int		parse_op(char **op_arr, header_t *header, char *champion)
{
	int		o;
	t_op	*op;
	char 	ocp;
	int		arv;
	int spg;
	int a;

	o = 0;
	spg = header->prog_size;
	if (op_arr[0] && op_arr[0][ft_strlen(op_arr[0]) - 1] == LABEL_CHAR)
	{
		op_arr[0][ft_strlen(op_arr[0]) - 1] = 0;
		add_label(champion, op_arr[o++], header->prog_size, 0, spg);
		if (!op_arr[1])
		{
			pr_free_char_arr(op_arr);
			return (0);
		}
	}
	op = get_op(op_arr[o++]);
	if (ft_arrstrlen(&(op_arr[o])) != op->arg_len)
		print_error(ERR_ARG_LEN);
	op->ocp = get_ocp(op_arr, o);
	save_bytes(header, champion, &(op->op_code), 1);
	if (op->print_ocp)
		save_bytes(header, champion, &(op->ocp), 1);
	a = 0;
	while (op_arr[o])
	{
		if (op_arr[o][0] == 'r')
		{
			if (!(op->args_type[a] % 2))
				print_error(ERR_ARG_TYPE);
			parse_register(header, op, op_arr[o], champion);
			arv += T_REG;
		}
		else if (op_arr[o][0] == DIRECT_CHAR)
		{
			if (!((op->args_type[a] >> 1) % 2))
				print_error(ERR_ARG_TYPE);
			arv += T_DIR;
			parse_direct(header, op, op_arr[o], champion, spg);
		}
		else
		{
			if (!((op->args_type[a] >> 2) % 2))
				print_error(ERR_ARG_TYPE);
			arv += T_IND;
			parse_indirect(header, op, op_arr[o], champion, spg);
		}
		o++;
		a++;
	}
	//CHECK PARAMS TYPE
	pr_free_char_arr(op_arr);
	return (0);
}
