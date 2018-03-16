/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:38:08 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/16 17:36:36 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void    ft_add(t_ins *ins, t_proc *proc)
{
	if (ins->param[2] < REG_NUMBER + 1 && ins->ocp == 84)
	{
		proc->reg[ins->param[2]] =
	   		proc->reg[ins->param[0]] +
			proc->reg[ins->param[1]];
		if (ins->param[2] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
