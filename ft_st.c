/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:48:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/13 14:21:13 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_st(t_ins *ins, t_proc *proc)
{
	unsigned char *tmp;

	if (ins->param[0] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if ((ins->ocp & 0x20) && (ins->ocp & 0x10))
	{
		tmp = ft_oob(proc->init, proc->curseur + ins->param[1] % IDX_MOD);
		*tmp = proc->reg[ins->param[0]];
	}
	else
		proc->reg[ins->param[1]] = ins->param[0];
	proc->curseur = proc->curseur + ins->size + 1;
}
