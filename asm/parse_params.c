/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_register(header_t *header, t_op *op, char *arg, char *champion)
{
	char	r;

	if (ft_strlen(arg) > 3 || !(arg[1]) || !ft_isdigit(arg[1])
	|| (arg[2] && !ft_isdigit(arg[2])))
		print_error(ERR_SYNTAX);
	r = pr_atoi(arg + 1);
	save_bytes(header, champion, &r, 1);
}

void	parse_direct(header_t *header, t_op *op, char *arg, char *champion, int spg)
{
	short	r;
	int		n;

	r = 0;
	n = 0;
	if (!(op->d2))
	{
		if (arg[1] == LABEL_CHAR)
			add_label(champion, arg + 2, header->prog_size, 1, spg, op->d2);
		if (arg[1] != LABEL_CHAR)
			n = endian_swap_32(pr_atoi(arg + 1));
		save_bytes(header, champion, &n, sizeof(int));
	}
	else if (arg[1] == LABEL_CHAR)
	{
		add_label(champion, arg + 2, header->prog_size, 1, spg, op->d2);
		save_bytes(header, champion, &r, sizeof(short));
	}
	else
	{
		r = endian_swap_16(pr_atos(arg + 1));
		save_bytes(header, champion, &r, sizeof(short));
	}

}

void	parse_indirect(header_t *header, t_op *op, char *arg, char *champion, int spg)
{
	short	r;

	r = 0;
	if (arg[0] == LABEL_CHAR)
		add_label(champion, arg + 1, header->prog_size, 1, spg, 1);
	else
		r = endian_swap_16(pr_atos(arg));
	save_bytes(header, champion, &r, sizeof(short));
}
