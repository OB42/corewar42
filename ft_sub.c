/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:55:33 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/07 18:56:04 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void    ft_sub(t_ins *ins, t_proc *proc)
{
	proc->champ.reg[ins->param[2]] =
		proc->champ.reg[ins->param[1]] -
		proc->champ.reg[ins->param[0]];
	if (ins->param[2] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
