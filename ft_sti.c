/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:09:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 23:33:46 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_sti(t_proc *proc)
{
	int tmp1;
	int tmp2;
	
	if (ft_val_ocp(proc->ins->ocp, 0) == 1 && proc->success == 1)
	{
		tmp1 = ft_conv(proc->ins->param[1], proc);
		tmp2 = proc->ins->param[2];
		if (proc->ins->ocp & 4)
		{
			tmp2 = proc->reg[proc->ins->param[2]];
			//ft_printf("reg[%d] = %d\n", proc->ins->param[2], tmp2);
		}
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc);
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
				tmp1, tmp2, tmp1 + tmp2, proc->curseur - proc->init + tmp1 + tmp2);
	}
	ft_print_instru(proc);
}

void	ft_sti(t_ins *ins, t_proc *proc)
{
	int				val_1;
	unsigned char	*tmp;

	val_1 = 0;
	proc->success = 1;
	if (ft_val_ocp(ins->ocp, 0) == 1)
	{
		if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
			val_1 = *ft_oob(proc->init, proc->curseur + ins->param[1]);
		else if (ins->ocp & 0x20)
			val_1 = ins->param[1];
		else if (ins->ocp & 0x10)
			val_1 = proc->reg[ins->param[1]];
		if (ins->ocp & 4)
		{
			//if (ins->param[2] < REG_SIZE)
				tmp = ft_oob(proc->init, proc->curseur + val_1
					+ proc->reg[ins->param[2]]);
			//else
			//{
			//	proc->success = 0;
			//	tmp = NULL;
			//}
		}
		else
			tmp = ft_oob(proc->init, proc->curseur + val_1 + ins->param[2]);
		//if (proc->success == 1)
			ft_write_ram(proc->reg[ins->param[0]], 4, tmp);
	}
	ft_print_sti(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
