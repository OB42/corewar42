/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:38:08 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/07 18:50:20 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void    ft_add(t_ins *ins, t_proc *proc)
{
	proc->champ.reg[ins->param[2]] =
	   	proc->champ.reg[ins->param[0]] +
		proc->champ.reg[ins->param[1]];
	if (ins->param[2] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
