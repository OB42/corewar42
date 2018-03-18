/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:38:08 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/17 11:33:27 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_print_add(t_proc *proc, t_ins *ins)
{
	if (ins->param[0] < REG_NUMBER + 1 && ins->param[1] < REG_NUMBER
			&& ins->param[2] < REG_NUMBER && ins->ocp == 84)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc, 0, 0 ,0);
		ft_printf("\n");
	}
	ft_print_instru(proc);
}

void    ft_add(t_ins *ins, t_proc *proc)
{
	if (ins->param[2] < REG_NUMBER + 1 && ins->ocp == 84)
	{
		proc->reg[ins->param[2]] =
	   		proc->reg[ins->param[0]] +
			proc->reg[ins->param[1]];
		proc->carry = !(proc->reg[ins->param[2]]);
	}
	ft_print_add(proc, ins);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
