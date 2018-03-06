/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instru.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:54:36 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/06 19:16:49 by vburidar         ###   ########.fr       */
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
	{"live", 1, {T_DIR}, 10, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 5, 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 5, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 10, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 10, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0},
	{"zjmp", 1, {T_DIR}, 20, 0, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25, 1, 0},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25, 1, 0},
	{"fork", 1, {T_DIR}, 800, 0, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 10, 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, 1, 0},
	{"lfork", 1, {T_DIR}, 1000, 0, 2},
	{"aff", 1, {T_REG}, 2, 1, 0},
	{0, 0, {0}, 0, 0, 0}};
	return (op_tab);
}

int	ft_is_instruc(char c)
{
	if (c < 17 && c > 0)
		return (1);
	return (0);
}

void	ft_get_var(t_ins *ins, char *code_champ)
{
	if (ins->ocp < 0)
	{
		ft_printf("ocp negative\n");
		ins->ocp = 256 + ins->ocp;
		ft_printf("%d\n", ins->ocp);
	}
	if ((ins->ocp & 0x80) && (ins->ocp & 0x40))
		ft_printf("1er param = IND\n");
	else if (ins->ocp & 0x80)
		ft_printf("1er param = DIR\n");
	else if (ins->ocp & 0x40)
		ft_printf("1er param = REG\n");
	if (ins->ocp & 0x20 && ins->ocp & 0x10)
		ft_printf("2e param = IND\n");
	else if (ins->ocp & 0x20)
		ft_printf("2e param = DIR\n");
	else if (ins->ocp & 0x10)
		ft_printf("2e param = REG\n");
	code_champ++;
}

t_ins	*ft_get_instru(char *code_champ)
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
			ins->ocp = (int) *(code_champ + 1);
		else
			ins->param1 = ft_get_int(code_champ + 2, op_tab[(int)*(code_champ - 1)].size_no_ocp);
		ft_get_var(ins, code_champ + 2);
		ft_printf("\nname = %s,ocp = %d, param %d\n", ins->name, ins->ocp, ins->param1);
	}
	else
		ft_printf("bad instruction\n");
	return (ins);
}
