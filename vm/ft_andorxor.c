/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_andorxor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:38:10 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 11:12:46 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"



void	ft_print_andorxor(t_proc *proc)
{
	ft_printf("P%5d | %s", proc->id, proc->ins->name);
	ft_print_ocp(proc, 1, 1, 0);
	ft_printf("\n");
	ft_print_instru(proc);
}

void	ft_or(t_ins *ins, t_proc *proc)
{
	ft_print_andorxor(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
	proc->reg[ins->param[2]] = (ins->tab[0].val_type | ins->tab[1].val_type);
}

void	ft_and(t_ins *ins, t_proc *proc)
{
	ft_print_andorxor(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
	proc->reg[ins->param[2]] = (ins->tab[0].val_type & ins->tab[1].val_type);
}


void	ft_xor(t_ins *ins, t_proc *proc)
{
	ft_print_andorxor(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
	proc->reg[ins->param[2]] = (ins->tab[0].val_type ^ ins->tab[1].val_type);
}
