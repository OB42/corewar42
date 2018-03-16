/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:34:39 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/16 19:29:45 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_and(t_proc *proc)
{
	ft_printf("P%5d | %s", proc->id, proc->ins->name);
	ft_print_ocp(proc, 1, 1, 0);
	ft_printf("\n");
	ft_print_instru(proc);
}

void	ft_and(t_ins *ins, t_proc *proc)
{
	unsigned char	*tmp;
	int val1;
	int val2;

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
	else if (ins->ocp & 0x40 && proc->reg[ins->param[0]] < REG_NUMBER + 1)
		val1 = proc->reg[ins->param[0]];
	if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
	{
		tmp = ft_oob(proc->init, proc->curseur + ins->param[1]);
		val2 = *tmp;
	}
	else if (ins->ocp & 0x20)
		val2 = ins->param[1];
	else if(ins->param[1] < REG_NUMBER + 1)
		val2 = proc->reg[ins->param[1]];
	if (ins->param[2] < REG_NUMBER + 1)
		proc->reg[ins->param[2]] = (val1 && val2);
	ft_print_and(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}

