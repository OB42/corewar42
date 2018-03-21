/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:57:09 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 16:51:01 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_ld(t_proc *proc)
{
	if((proc->ins->ocp == 144 || proc->ins->ocp == 208) &&  proc->ins->fail == 0)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_printf(" %d r%d\n", proc->ins->tab[0].val_type, proc->ins->param[1]);
	}
	ft_print_instru(proc);
}

void	ft_ld(t_ins *ins, t_proc *proc)
{
	if ((ins->ocp == 144 || ins->ocp == 208) && proc->ins->fail == 0)
	{
		proc->reg[ins->param[1]] = ins->tab[0].val_type;
		if (ins->tab[0].val_type == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	//else if (ins->ocp < 16)
	//	ins->size = 1;
	//else if (ins->ocp > 240)
	//	ins->size = 5;
	else if (ins->ocp & 8 && ins->ocp & 4)
		ins->size -= 2;
	else if (ins->ocp & 8)
		ins->size -= 4;
	else if (ins->ocp & 4)
		ins->size -= 1;
	ft_print_ld(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}

void	ft_lld(t_ins *ins, t_proc *proc)
{
	if ((ins->ocp == 144 || ins->ocp == 208) && proc->ins->fail == 0)
	{
		proc->reg[ins->param[1]] = ins->tab[0].val_type;
		if (ins->param[0] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else if (ins->ocp < 16)
		ins->size = 1;
	else if (ins->ocp > 240)
		ins->size = 5;
	ft_print_ld(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
