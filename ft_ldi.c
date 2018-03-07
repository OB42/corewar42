/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:49:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/07 21:34:18 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_ldi(t_ins *ins, t_proc *proc)
{
	int val_1;
	int val_2;
	
	val_1 = 0;
	val_2 = 0;
	if ((ins->ocp & 40) && (ins->ocp & 80))
		val_1 = proc->curseur[ins->param[0] & IDX_MOD];
	else if(ins->ocp & 40)
		val_1 = proc->reg[ins->param[0]];
	else if (ins->ocp & 80)
		val_1 = ins->param[0];
	if ((ins->ocp & 10) && (ins->ocp & 20))
		val_2 = proc->curseur[ins->param[1] & IDX_MOD];
	else if (ins->ocp & 20)
		val_2 = ins->param[1];
	proc->reg[ins->param[2]] = val_1 + val_2;
}

void	ft_lldi(t_ins *ins, t_proc *proc)
{
	int val_1;
	int val_2;
	
	val_1 = 0;
	val_2 = 0;
	if ((ins->ocp & 40) && (ins->ocp & 80))
		val_1 = proc->curseur[ins->param[0] & MEM_SIZE];
	else if(ins->ocp & 40)
		val_1 = proc->reg[ins->param[0]];
	else if (ins->ocp & 80)
		val_1 = ins->param[0];
	if ((ins->ocp & 10) && (ins->ocp & 20))
		val_2 = proc->curseur[ins->param[1] & MEM_SIZE];
	else if (ins->ocp & 20)
		val_2 = ins->param[1];
	proc->reg[ins->param[2]] = val_1 + val_2;
}
