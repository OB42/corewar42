/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:48:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 14:58:52 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_st(t_proc *proc)
{
	if (proc->ins->ocp == 20 || proc->ins->ocp == 28)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc);
	}
	else
		proc->ins->size = 1;
	ft_print_instru(proc);
}

void	ft_st(t_ins *ins, t_proc *proc)
{
	unsigned char *tmp;

	if (proc->ins->ocp == 20 || proc->ins->ocp == 28)
	{
		if (ins->param[0] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
		{
			tmp = ft_oob(proc->init, proc->curseur + ins->param[1]);
			if (ft_abs(tmp - proc->init) > IDX_MOD)
				tmp = ft_oob(proc->init, proc->curseur + ins->param[1] % IDX_MOD);
			ft_write_ram(proc->reg[ins->param[0]], 4, tmp);
		}
		else
			proc->reg[ins->param[1]] = ins->param[0];
	}
	ft_print_st(proc);
	proc->curseur = proc->curseur + ins->size + 1;
}
