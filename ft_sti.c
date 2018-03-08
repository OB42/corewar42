/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:09:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 15:28:02 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_sti(t_ins *ins, t_proc *proc)
	int	val_1;

	val_1 = 0;
	if ((ins->ocp & 20) && (ins->ocp & 10))
		val_1 = proc->curseur;
	else if (ins->ocp & 20)
		val_1 = ins->param[1];
	else if (ins->ocp & 10)
		val_1 = proc->reg[ins->param[1]];
	if ((proc->curseur + (val_1 + ins->param[2]) % IDX_MOD) -
			proc->init > MEM_SIZE)
	{
		*(proc->init + (proc->curseur - proc->init + (val_1 + ins->param[2]) % IDX_MOD) % MEM_SIZE) = proc->reg[ins->param[0]];
	}
	else
		proc->curseur[((val_1 + ins->param[2]) % IDX_MOD)] =
			proc->reg[ins->param[0]];
}
