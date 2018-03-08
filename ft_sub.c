/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:55:33 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/08 15:00:01 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void    ft_sub(t_ins *ins, t_proc *proc)
{
	proc->reg[ins->param[2]] =
		proc->reg[ins->param[1]] -
		proc->reg[ins->param[0]];
	if (ins->param[2] == 0)
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
