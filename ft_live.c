/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:22:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/11 15:52:17 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "LIBFT/libft.h"

void	ft_live(t_ins *ins, t_proc *proc)
{
	proc->live = 1;
	ins->size = ins->size;
	//ft_printf("joueur %s (%d ou %d) est en vie\n", proc->champ.header.prog_name, ins->param[0], proc->player);
	proc->curseur = ft_oob(proc->init, proc->curseur + 5);
}
