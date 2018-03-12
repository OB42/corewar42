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

void save_bytes(header_t *header, char *champion, void *temp, int i)
{
	if (header->prog_size + i <= CHAMP_MAX_SIZE)
		ft_memcpy(champion + header->prog_size, temp, i);
	else
		print_error(ERR_CHAMPION_SIZE);
	header->prog_size += i;
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
	pr_free_char_arr(op_arr);
	return (0);
}
