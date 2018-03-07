/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:38:08 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/07 21:35:08 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void    ft_add(t_ins *ins, t_proc *proc)
{
	proc->reg[ins->param[2]] =
	   	proc->reg[ins->param[0]] +
		proc->reg[ins->param[1]];
	if (ins->param[2] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
