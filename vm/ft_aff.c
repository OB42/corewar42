/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:16:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/19 16:37:03 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_aff(t_ins *ins, t_proc *proc)
{
	if (proc->ins->fail == 0)
	{
		proc->ins->param[1] = 0;
		ft_printf("%c", ins->param[0] % 256);
		if (ins->param[0] % 256 == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
	}
}
