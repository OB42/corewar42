/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:57:09 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/09 19:17:14 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_ld(t_ins *ins, t_proc *proc)
{
	if ((ins->ocp & 80) && (ins->ocp & 40))
		proc->reg[ins->param[1]] = *(ft_oob(proc->init, proc->curseur
		+ ft_addlim (ins->param[0])));
	else
		proc->reg[ins->param[1]] = ins->param[0];
	if (ins->param[0] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}

void	ft_lld(t_ins *ins, t_proc *proc)
{
	if ((ins->ocp & 80) && (ins->ocp & 40))
		proc->reg[ins->param[1]] = *(ft_oob(proc->init, proc->curseur
		+ ins->param[0] % MEM_SIZE));
	else
		proc->reg[ins->param[1]] = ins->param[0];
	if (ins->param[0] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
