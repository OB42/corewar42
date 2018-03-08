/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:48:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 15:34:54 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_st(t_ins *ins, t_proc *proc)
{
	if (ins->param[0] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
	{
		if (proc->curseur - proc->init + proc->size > MEM_SIZE)
		{
			proc->curseur = ((proc->curseur - proc->infit + proc->size) % MEM_SIZE) +
				proc->init;
			*(proc->curseur)  = proc->reg[ins->param[0]];
		}
		else
			proc->curseur += proc->size;
	}
	else
		proc->reg[ins->param[1]] = ins->param[0];
}
