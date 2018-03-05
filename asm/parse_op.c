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
		{"live", 1, {T_DIR}},
		{"ld", 2, {T_DIR | T_I, T_REG}},
		{"st", 2, {T_REG, T_I | T_REG}},
		{"add", 3, {T_REG, T_REG, T_REG}},
		{"sub", 3, {T_REG, T_REG, T_REG}},
		{"and", 3, {T_REG | T_DIR | T_I, T_REG | T_I | T_DIR, T_REG}},
		{"or", 3, {T_REG | T_I | T_DIR, T_REG | T_I | T_DIR, T_REG}},
		{"xor", 3, {T_REG | T_I | T_DIR, T_REG | T_I | T_DIR, T_REG}},
		{"zjmp", 1, {T_DIR}},
		{"ldi", 3, {T_REG | T_DIR | T_I, T_DIR | T_REG, T_REG}},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_I, T_DIR | T_REG}},
		{"fork", 1, {T_DIR}},
		{"lld", 2, {T_DIR | T_I, T_REG}},
		{"lldi", 3, {T_REG | T_DIR | T_I, T_DIR | T_REG, T_REG}},
		{"lfork", 1, {T_DIR}},
		{"aff", 1, {T_REG}},
		{0, 0, {0}}
	};

	return (find_op(op_tab, name));
}

int		parse_op(char **op_arr, header_t header, char *champion)
{
	int		o;
	int		i;
	t_op	*op;

	i = 0;
	o = 0;
	if (op_arr[0] && op_arr[0][ft_strlen(op_arr[0]) - 1] == LABEL_CHAR)
	{
		o++;
		//set_label(op_arr[o++], header, i);//TODO
	}
	op = get_op(op_arr[o++]);
	if (ft_arrstrlen(&(op_arr[o])) != op->arg_len)
		print_error(ERR_ARG_LEN);
	pr_free_char_arr(op_arr);
	return (i);
}
