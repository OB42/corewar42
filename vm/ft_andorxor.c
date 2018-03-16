/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_andorxor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:38:10 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/16 19:17:41 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"

void	ft_or(t_ins *ins, t_proc *proc)
{
	unsigned char	*tmp;
	int				val1;
	int				val2;

	val1 = 0;
	val2 = 0;
	tmp = NULL;
	if ((ins->ocp & 0x80) && (ins->ocp & 0x40))
	{
		tmp = ft_oob(proc->init, proc->curseur + ins->param[0]);
		val1 = *tmp;
	}
	else if (ins->ocp & 0x80)
		val1 = ins->param[0];
	else if (ins->ocp & 0x40)
		val1 = proc->reg[ins->param[0]];
	if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
	{
		tmp = ft_oob(proc->init, proc->curseur + ins->param[0]);
		val2 = *tmp;
	}
	else if (ins->ocp & 0x20)
		val2 = ins->param[1];
	else
		val2 = proc->reg[ins->param[1]];
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
	proc->reg[ins->param[2]] = (val1 || val2);
}


void	ft_xor(t_ins *ins, t_proc *proc)
{
	int		val1;
	int		val2;
	unsigned char	*tmp;

	val1 = 0;
	val2 = 0;
	tmp = NULL;
	if ((ins->ocp & 0x80) && (ins->ocp & 0x40))
	{
		tmp = ft_oob(proc->init, proc->curseur + ins->param[1]);	
		val1 = proc->curseur[ins->param[0]];
	}
	else if (ins->ocp & 0x80)
		val1 = ins->param[0];
	else if (ins->ocp & 0x40)
		val1 = proc->reg[ins->param[0]];
	if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
	{
		tmp = ft_oob(proc->init, proc->curseur + ins->param[1]);
		val2 = *tmp;
	}
	else if (ins->ocp & 0x20)
		val2 = ins->param[1];
	else
		val2 = proc->reg[ins->param[1]];
	proc->reg[ins->param[2]] = ((val1 || val2) && !(val1 && val2));
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
