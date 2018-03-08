/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:22:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 14:53:18 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "LIBFT/libft.h"

void	ft_live(t_ins *ins, t_proc *proc)
{
	proc->live = 1;
	ft_printf("joueur %s (%d ou %d) est en vie\n",
		proc->champ.header.prog_name, ins->param[0], proc->player);
	if (proc->curseur + 5 > MEM_SIZE)
	{
		proc->curseur = ((proc->curseur - proc->infit + 5) % MEM_SIZE) +
			proc->init;
	}
	else
		proc->curseur += 5;
}
