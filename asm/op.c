/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:44:35 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op    op_tab[17] =
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
	{0, 0, {0}, 0, 0, 0, 0, 0}
};
/*
live	d4
ld		d4	rg
and		d4	d4	rg
or		d4	d4	rg
xor		d4	d4	rg
*/
