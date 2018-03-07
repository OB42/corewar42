/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:09:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/07 21:34:46 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_sti(t_ins *ins, t_proc *proc)
{
	int	val_1;

	val_1 = 0;
	if ((ins->ocp & 20) && (ins->ocp & 10))
		val_1 = ins->param[1];
	else if (ins->ocp & 20)
		val_1 = ins->param[1];
	else if (ins->ocp & 10)
		val_1 = proc->reg[ins->param[1]];
	proc->curseur[(val_1 + ins->param[2]) % IDX_MOD] = proc->reg[ins->param[0]];
}
