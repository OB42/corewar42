/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_to_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:11:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/13 18:49:06 by vburidar         ###   ########.fr       */
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
			proc = ft_del(proc);
	}
	corewar->ctd_cur = 0;
	if (corewar->nb_live > NBR_LIVE)
	{
		corewar->ctd_obj -= CYCLE_DELTA;
		ft_printf("Cycle to die is now %d\n", corewar->ctd_obj);
	}
	corewar->nb_live = 0;
	id =ft_get_procnb(proc);
	while (proc->id != id - 1)
		proc = proc->nxt;
	return (proc);
}
