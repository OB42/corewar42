/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:40:52 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 18:00:23 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_zjmp(t_ins *ins, t_proc *proc)
{
	if (proc->carry == 1)
		proc->curseur = ft_oob(proc->init, proc->curseur + ins->param[0] % MEM_SIZE);
}
