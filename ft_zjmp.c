/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:40:52 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 14:53:37 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_zjmp(t_ins *ins, t_proc *proc)
{
	if (proc->carry == 1)
	{
		if ((proc->curseur - proc->init) + ins->param[0] > MEM_SIZE)
			proc->curseur = ((proc->curseur - proc->init +
				ins->param[0]) % MEM_SIZE) + proc->init;
		else
			proc->curseur += ins->param[0];
	}
}
