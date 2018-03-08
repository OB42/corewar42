/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:09:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 17:03:33 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_sti(t_ins *ins, t_proc *proc)
{
	int				val_1;
	unsigned char	*tmp;

	val_1 = 0;
	if ((ins->ocp & 20) && (ins->ocp & 10))
		val_1 = *ft_oob(proc->init, proc->curseur + ins->param[1]);
	else if (ins->ocp & 20)
		val_1 = ins->param[1];
	else if (ins->ocp & 10)
		val_1 = proc->reg[ins->param[1]];
	tmp = ft_oob(proc->init, proc->curseur + val_1 + ins->param[2] % IDX_MOD);
	*tmp = proc->reg[ins->param[0]];
}
