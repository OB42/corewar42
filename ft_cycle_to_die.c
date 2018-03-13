/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_to_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:11:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/13 22:10:54 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

t_proc	*ft_cycle_to_die(t_corewar *corewar, t_proc *proc)
{
	t_proc	*init;
	int		id;

	id = ft_get_procnb(proc);
	init = proc;
	while (id > proc->id)
	{
		id = proc->id;
		if (proc->live == 0)
		{
			//ft_printf("deleted %d\n", proc->id);
			proc = ft_del(proc);
		}
		else
			proc->live = 0;
		proc = proc->nxt;
	}
	if (corewar->nb_live > NBR_LIVE)
	{
		corewar->ctd_obj -= CYCLE_DELTA;
		ft_printf("Cycle to die is now %d\n", corewar->ctd_obj);
	}
	corewar->ctd_cur = 0;
	corewar->nb_live = 0;
	while (proc->id < ft_get_procnb(proc) - 1)
		proc = proc->nxt;
	return (proc);
}
