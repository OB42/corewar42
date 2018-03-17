/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:48:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 15:20:25 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_st(t_proc *proc)
{
	int value;

	value = proc->ins->param[1];
	if (value > 32768)
		value -= 65536;
	if (proc->ins->ocp == 80 || proc->ins->ocp == 112)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		if (proc->ins->tab[1].type == 1)
			ft_printf(" r%d %d", proc->ins->param[0], proc->ins->param[1]);
		else
			ft_printf(" r%d %d", proc->ins->param[0], value);	
		ft_printf("\n");
	}
	else
		proc->ins->size = 1;
	ft_print_instru(proc);
}

void	ft_st(t_ins *ins, t_proc *proc)
{
	unsigned char *tmp;

	if (proc->ins->ocp == 80 || proc->ins->ocp == 112)
	{
		if (ins->param[0] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
		{
			tmp = ft_oob(proc->init, proc->curseur + ins->param[1] % IDX_MOD);
			ft_write_ram(proc->reg[ins->param[0]], 4, tmp, proc);
		}
		else
			proc->reg[ins->param[1]] = proc->reg[ins->param[0]];
	}
	ft_print_st(proc);
	proc->curseur = proc->curseur + ins->size + 1;
}
