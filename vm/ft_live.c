/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:22:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/16 19:00:15 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "LIBFT/libft.h"

void	ft_live(t_ins *ins, t_proc *proc)
{
	proc->corewar->nb_live += 1;
	proc->live = 1;
	proc->last_live = 1;
	ins->size = ins->size;
	ins->param[0] = ft_get_int(proc->curseur + 1, 4);
	proc->curseur = ft_oob(proc->init, proc->curseur + 5);
}
