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
	static t_op	op_tab[17] = {
		{"live", 1, {T_DIR}, 1},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2},
		{"st", 2, {T_REG, T_IND | T_REG}, 3},
		{"add", 3, {T_REG, T_REG, T_REG}, 4},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8},
		{"zjmp", 1, {T_DIR}, 9},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11},
		{"fork", 1, {T_DIR}, 12},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14},
		{"lfork", 1, {T_DIR}, 15},
		{"aff", 1, {T_REG}, 16},
		{0, 0, {0}}
	};

	return (find_op(op_tab, name));
}

char 	get_ocp(char **op_arr, int o, int label)
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

void save_bytes(header_t *header, char *champion, char *str, int i)
{
	if (header->prog_size + i <= CHAMP_MAX_SIZE)
		ft_strncpy(champion + header->prog_size, str, i);
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

int		parse_op(char **op_arr, header_t *header, char *champion)
{
	int		o;
	t_op	*op;
	char 	ocp;
	int		label;
	o = 0;

	label = (op_arr[0] && op_arr[0][ft_strlen(op_arr[0]) - 1] == LABEL_CHAR);
	if (label)
	{
		op_arr[0][ft_strlen(op_arr[0]) - 1] = 0;
		add_label(op_arr[o++], header->prog_size);
	}
	op = get_op(op_arr[o++]);
	if (ft_arrstrlen(&(op_arr[o])) != op->arg_len)
		print_error(ERR_ARG_LEN);
	op->ocp = get_ocp(op_arr, o, label);
	save_bytes(header, champion, &(op->op_code), 1);
	if (op->op_code != 1 && op->op_code != 9)
		save_bytes(header, champion, &(op->ocp), 1);
	while (op_arr[o])
	{
		if (op_arr[o][0] == 'r')
			parse_register(header, op, op_arr[o], champion);
		/*else if (op_arr[o] == DIRECT_CHAR)
			parse_direct(header, op, op_arr[o], champion);
		else
			parse_value(header, op, op_arr[o], champion);
		*/
		o++;
	}
	pr_free_char_arr(op_arr);
	return (0);
}
