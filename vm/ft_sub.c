/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:55:33 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/21 17:44:44 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_print_sub(t_proc *proc, t_ins *ins)
{
	if (proc->ins->fail == 0 && ins->ocp == 0x54)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc, 0, 0, 0);
		ft_printf("\n");
	}
	ft_print_instru(proc);
}

void	ft_sub(t_ins *ins, t_proc *proc)
{
	if (proc->ins->ocp == 0x54 && proc->ins->fail == 0)
	{
		proc->reg[ins->param[2]] =
			proc->reg[ins->param[0]] -
			proc->reg[ins->param[1]];
		proc->carry = !(proc->reg[ins->param[2]]);
	}
	ft_print_sub(proc, ins);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
