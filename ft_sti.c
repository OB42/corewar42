/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:09:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/09 16:36:03 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_sti(t_ins *ins, t_proc *proc)
{
	int				val_1;
	unsigned char	*tmp;

	val_1 = 0;
	if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
		val_1 = *ft_oob(proc->init, proc->curseur + ins->param[1]);
	else if (ins->ocp & 0x20)
		val_1 = ins->param[1];
	else if (ins->ocp & 0x10)
		val_1 = proc->reg[ins->param[1]];
	tmp = ft_oob(proc->init, proc->curseur + val_1 + ins->param[2] % IDX_MOD);
	ft_printf("P%5d | %s", proc->id, proc->ins->name);
	ft_printf(" r%d %d %d\n", ins->param[0], val_1, ins->param[2]);
	ft_printf("       | -> store to %d + %d = %d\n", val_1, ins->param[2], tmp - proc->curseur);
	*tmp = proc->reg[ins->param[0]];
	ft_print_instru(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
