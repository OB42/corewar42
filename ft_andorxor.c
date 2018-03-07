/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_andorxor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:38:10 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/07 21:40:32 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_and(t_ins *ins, t_proc *proc)
{
	int val1;
	int val2;

	val1 = 0;
	val2 = 0;
	if ((ins->ocp & 80) && (ins->ocp & 40))
		val1 = proc->curseur[ins->param[0]];
	else if (ins->ocp & 80)
		val1 = ins->param[0];
	else if (ins->ocp & 40)
		val1 = proc->reg[ins->param[0]];
	if ((ins->ocp & 20) && (ins->ocp & 10))
		val2 = proc->curseur[ins->param[1]];
	else if (ins->ocp & 20)
		val2 = ins->param[1];
	else
		val2 = proc->reg[ins->param[1]];
	proc->reg[ins->param[0]] = (val1 && val2);
}

void	ft_or(t_ins *ins, t_proc *proc)
{
	int val1;
	int val2;

	val1 = 0;
	val2 = 0;
	if ((ins->ocp & 80) && (ins->ocp & 40))
		val1 = proc->curseur[ins->param[0]];
	else if (ins->ocp & 80)
		val1 = ins->param[0];
	else if (ins->ocp & 40)
		val1 = proc->reg[ins->param[0]];
	if ((ins->ocp & 20) && (ins->ocp & 10))
		val2 = proc->curseur[ins->param[1]];
	else if (ins->ocp & 20)
		val2 = ins->param[1];
	else
		val2 = proc->reg[ins->param[1]];
	proc->reg[ins->param[0]] = (val1 || val2);
}


void	ft_xor(t_ins *ins, t_proc *proc)
{
	int val1;
	int val2;

	val1 = 0;
	val2 = 0;
	if ((ins->ocp & 80) && (ins->ocp & 40))
		val1 = proc->curseur[ins->param[0]];
	else if (ins->ocp & 80)
		val1 = ins->param[0];
	else if (ins->ocp & 40)
		val1 = proc->reg[ins->param[0]];
	if ((ins->ocp & 20) && (ins->ocp & 10))
		val2 = proc->curseur[ins->param[1]];
	else if (ins->ocp & 20)
		val2 = ins->param[1];
	else
		val2 = proc->reg[ins->param[1]];
	proc->reg[ins->param[0]] = ((val1 || val2) && !(val1 && val2));
}
