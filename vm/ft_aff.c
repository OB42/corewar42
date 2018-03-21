/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:16:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 17:27:39 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	if (ins->fail == 0)
**	{
**		//ft_printf("P%5d | %s", proc->id, ins->name);
**		//ft_print_ocp(proc, 0, 0, 0);
**		//ft_printf("\n");
**	}
** (in ft_print_aff before calling ft_print_instru)
**
**ft_printf("%c", ins->param[0] % 256);
** ( in ft_aff first if)
*/

#include "op.h"

void	ft_print_aff(t_ins *ins, t_proc *proc)
{
	if (ins->fail == 0)
		ins->fail = 0;
	ft_print_instru(proc);
}

void	ft_aff(t_ins *ins, t_proc *proc)
{
	if (proc->ins->fail == 0 && proc->ins->ocp == 64)
		proc->ins->param[1] = 0;
	else
		ins->size = 1;
	ft_print_aff(ins, proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
