/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:22:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 16:09:17 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "LIBFT/libft.h"

void	ft_print_live(t_proc *proc)
{
	int param;

	param = proc->ins->param[0];
	if (param == 0)
		param = 11000000;
	ft_printf("P%5d | %s %d\n", proc->id, proc->ins->name, proc->ins->param[0]);
	if (proc->ins->param[0] > 2147483647)
		proc->ins->tab[0].val_type -= 4294967295;
	if (ft_abs(param) <= proc->corewar->nb_champ)
		ft_printf("Player %d (%s) is said to be alive\n",
			-param, proc->corewar->tab_champ[-param - 1].header.prog_name);
	ft_print_instru(proc);
}

void	ft_live(t_ins *ins, t_proc *proc)
{
	proc->corewar->nb_live += 1;
	proc->live = 1;
	proc->last_live = 1;
	ins->size = ins->size;
	ins->param[0] = ft_get_int(proc->curseur + 1, 4);
	ft_print_live(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + 5);
}
