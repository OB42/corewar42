/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:09:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/13 22:36:33 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_sti(t_ins *ins, t_proc *proc)
{
	int				val_1;
	unsigned char	*tmp;

	val_1 = 0;
	if (ft_val_ocp(ins->ocp, 0) == 1)
	{
		if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
			val_1 = *ft_oob(proc->init, proc->curseur + ins->param[1]);
		else if (ins->ocp & 0x20)
			val_1 = ins->param[1];
		else if (ins->ocp & 0x10)
			val_1 = proc->reg[ins->param[1]];
		//ft_printf("val = %d\n", proc->reg[ins->param[0]]);
		if (ins->ocp & 4)
			tmp = ft_oob(proc->init, proc->curseur + val_1
					+ proc->reg[ins->param[2]]);
		else
			tmp = ft_oob(proc->init, proc->curseur + val_1 + ins->param[2]);
		ft_write_ram(proc->reg[ins->param[0]], 4, tmp);
	}
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
		//ft_printf("%02x %02x %02x %02x\n", proc->curseur[0], proc->curseur[1], proc->curseur[2], proc->curseur[3]);
}
