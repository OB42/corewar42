/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:49:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 22:09:38 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_ldi(t_proc *proc)
{
	int tmp1;
	int tmp2;
	
	tmp1 = ft_conv(proc->ins->param[0], proc);
	tmp2 = ft_conv(proc->ins->param[1], proc);
	if (proc->ins->param[2] < REG_NUMBER && proc->ins->ocp > 115)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc);
		ft_printf("\n       | -> load from %d + %d = %d (with pc and mod %d)\n", 
				tmp1, tmp2, tmp1 + tmp2, proc->curseur - proc->init + tmp1 + tmp2);
	}
	ft_print_instru(proc);
}

void	ft_ldi(t_ins *ins, t_proc *proc)
{
	int val_1;
	int val_2;
	unsigned char *tmp;
	
	val_1 = ft_addlim(proc->ins->param[0]);
	val_2 = ft_addlim(proc->ins->param[1]);
	tmp = ft_oob(proc->init, proc->curseur + ft_addlim(val_1) + ft_addlim(val_2));
	if (proc->ins->param[2] < REG_NUMBER && proc->ins->ocp > 115)
	{
		proc->reg[ins->param[2]] = ft_get_int(ft_oob(proc->init, proc->curseur + val_1 + val_2), REG_SIZE);
	}
	ft_print_ldi(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}

void	ft_lldi(t_ins *ins, t_proc *proc)
{
	int val_1;
	int val_2;
	
	val_1 = proc->ins->param[0] % MEM_SIZE;
	val_2 = proc->ins->param[1] % MEM_SIZE;
	if ((ins->ocp & 0x40) && (ins->ocp & 0x80))
		val_1 = *(ft_oob(proc->init, proc->curseur + ins->param[0] % MEM_SIZE));
	else if(ins->ocp & 0x40)
		val_1 = proc->reg[ins->param[0]];
	else if (ins->ocp & 0x80)
		val_1 = ins->param[0];
	if ((ins->ocp & 0x10) && (ins->ocp & 0x20))
		val_2 = *(ft_oob(proc->init, proc->curseur + ins->param[1] % MEM_SIZE));
	else if (ins->ocp & 0x20)
		val_2 = ins->param[1];
	if (ins->param[2] < REG_SIZE && ins->ocp > 115)
		proc->reg[ins->param[2]] = val_1 + val_2;
	ft_print_ldi(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + proc->ins->size + 1);
}
