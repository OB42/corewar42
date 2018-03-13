/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:49:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/13 16:13:23 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_ldi(t_ins *ins, t_proc *proc)
{
	int val_1;
	int val_2;
	unsigned char *tmp;
	
	val_1 = ft_addlim(proc->ins->param[0]);
	val_2 = ft_addlim(proc->ins->param[1]);
	tmp = ft_oob(proc->init, proc->curseur + ft_addlim(val_1) + ft_addlim(val_2));
	//ft_printf("%02x %02x %02x %02x ram[%d]\n", tmp[0], tmp[1], tmp[2], tmp[3], tmp - proc->init);
	proc->reg[ins->param[2]] = ft_get_int(ft_oob(proc->init, proc->curseur + val_1 + val_2), REG_SIZE);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}

void	ft_lldi(t_ins *ins, t_proc *proc)
{
	int val_1;
	int val_2;
	
	val_1 = 0;
	val_2 = 0;
	if ((ins->ocp & 40) && (ins->ocp & 80))
		val_1 = *(ft_oob(proc->init, proc->curseur + ins->param[0] % MEM_SIZE));
	else if(ins->ocp & 40)
		val_1 = proc->reg[ins->param[0]];
	else if (ins->ocp & 80)
		val_1 = ins->param[0];
	if ((ins->ocp & 10) && (ins->ocp & 20))
		val_2 = *(ft_oob(proc->init, proc->curseur + ins->param[1] % MEM_SIZE));
	else if (ins->ocp & 20)
		val_2 = ins->param[1];
	proc->reg[ins->param[2]] = val_1 + val_2;
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
