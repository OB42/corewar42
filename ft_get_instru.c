/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instru.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:54:36 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/07 21:50:37 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

t_op	*ft_get_op_tab(void)
{
	static t_op op_tab[17] =
	{
	{"live", 1, {T_DIR}, 10, 0, 4, ft_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 5, 1, 0, ft_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 5, 1, 0, ft_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 10, 1, 0, ft_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 10, 1, 0, ft_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0, ft_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0, ft_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0, ft_xor},
	{"zjmp", 1, {T_DIR}, 20, 0, 2, ft_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25, 1, 0, ft_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25, 1, 0, ft_sti},
	{"fork", 1, {T_DIR}, 800, 0, 2, ft_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 10, 1, 0, ft_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, 1, 0, ft_lldi},
	{"lfork", 1, {T_DIR}, 1000, 0, 2, ft_lfork},
	{"aff", 1, {T_REG}, 2, 1, 0, NULL},
	{0, 0, {0}, 0, 0, 0, 0}};
	return (op_tab);
}

int	ft_is_instruc(char c)
{
	if (c < 17 && c > 0)
		return (1);
	return (0);
}

void	ft_get_var(t_ins *ins, unsigned char *code_champ)
{
	if (ins->ocp < 0)
		ins->ocp = 256 + ins->ocp;
	if ((ins->ocp & 0x80) && (ins->ocp & 0x40))
		code_champ = ft_get_ind(ins, code_champ, 0);
	else if (ins->ocp & 0x80)
		code_champ = ft_get_dir(ins, code_champ, 0);
	else if (ins->ocp & 0x40)
		code_champ = ft_get_reg(ins, code_champ, 0);
	if (ins->ocp & 0x20 && ins->ocp & 0x10)
		code_champ = ft_get_ind(ins, code_champ, 1);
	else if (ins->ocp & 0x20)
		code_champ = ft_get_dir(ins, code_champ, 1);
	else if (ins->ocp & 0x10)
		code_champ = ft_get_reg(ins, code_champ, 1);
	if (ins->ocp & 8 && ins->ocp & 4)
		code_champ = ft_get_ind(ins, code_champ, 2);
	else if (ins->ocp & 8)
		code_champ = ft_get_dir(ins, code_champ, 2);
	else if (ins->ocp & 4)
		code_champ = ft_get_reg(ins, code_champ, 2);
}

t_ins	*ft_get_instru(unsigned char *code_champ)
{
	t_op		*op_tab;
	t_ins	*ins;

	ins = NULL;
	op_tab = ft_get_op_tab();
	ft_printf("%d\n", (int)*code_champ);
	if (ft_is_instruc(*code_champ))
	{
		ins = malloc(sizeof(t_ins));
		ft_bzero(ins, sizeof(t_ins));
		ins->name = op_tab[(int)*(code_champ) - 1].name;
		if (op_tab[(int)*(code_champ) - 1].ocp == 1)
		{
			ins->ocp = (int) *(code_champ + 1);
			ft_get_var(ins, code_champ + 2);
		}
		else
			ins->param[0] = ft_get_int(code_champ + 1, op_tab[(int)*(code_champ - 1)].size_no_ocp);
		ft_printf("\nname = %s,ocp = %d, param %d %d %d\n", ins->name, ins->ocp, ins->param[0], ins->param[1], ins->param[2]);
	}
	else
		ft_printf("bad instruction\n");
	return (ins);
}
