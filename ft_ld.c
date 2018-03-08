/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:57:09 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 14:58:09 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_ld(t_ins *ins, t_proc *proc)
{
	if ((ins->ocp & 80) && (ins->ocp & 40))
		proc->reg[ins->param[1]] = proc->curseur[ins->param[0] % IDX_MOD];
	else
		proc->reg[ins->param[1]] = ins->param[0];
	if (ins->param[0] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (proc->curseur + proc->size)
	{
		proc->curseur = ((proc->curseur - proc->infit + proc->size) % MEM_SIZE) +
			proc->init;
	}
	else
		proc->curseur += proc->size;
}

void	ft_lld(t_ins *ins, t_proc *proc)
{
	if ((ins->ocp & 80) && (ins->ocp & 40))
		proc->reg[ins->param[1]] = proc->curseur[ins->param[0] % MEM_SIZE];
	else
		proc->reg[ins->param[1]] = ins->param[0];
	if (ins->param[0] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (proc->curseur + proc->size)
	{	
		proc->curseur = ((proc->curseur - proc->infit + proc->size) % MEM_SIZE) +
			proc->init;
	}
	else
		proc->curseur += proc->size;
}
