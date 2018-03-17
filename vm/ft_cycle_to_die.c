/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_to_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:11:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 16:56:25 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

t_proc	*ft_cycle_to_die(t_corewar *corewar, t_proc *proc)
{
	t_proc	*init;
	int		id;

	corewar->check += 1;
	id = ft_get_procnb(proc);
	init = proc;
	while (proc && id > proc->id)
	{
		id = proc->id;
		//ft_printf(" %d, live = %d, last_live = %d\n", proc->id, proc->live, proc->last_live);
		if (proc->live == 0)
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", proc->id,
				proc->last_live + 1, corewar->ctd_obj);
			proc = ft_del(proc);
		}
		else
		{
			proc->live = 0;
			proc = proc->nxt;
		}
	}
	if (corewar->nb_live > NBR_LIVE || corewar->check >= MAX_CHECKS)
	{
		corewar->check = 0;
		corewar->ctd_obj -= CYCLE_DELTA;
		ft_printf("Cycle to die is now %d\n", corewar->ctd_obj);
	}
	corewar->ctd_cur = 0;
	corewar->nb_live = 0;
	if (proc == NULL)
		return (proc);
	while (proc->id < ft_get_procnb(proc) - 1)
		proc = proc->nxt;
	//ft_printf("fin ctd courrant = %d ctd obj = %d\n", corewar->ctd_cur, corewar->ctd_obj);
	return (proc);
}
