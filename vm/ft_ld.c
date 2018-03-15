/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:57:09 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 19:08:53 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_ld(t_proc *proc)
{
	if(proc->ins->ocp == 144 || proc->ins->ocp == 128)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc);
		ft_printf("\n");
	}
	ft_print_instru(proc);
}

void	ft_ld(t_ins *ins, t_proc *proc)
{
	unsigned char *curs;

	if (ins->ocp == 144 || ins->ocp == 128)
	{
		curs = ft_oob(proc->init, proc->curseur + ft_addlim(ins->param[0]));
		if ((ins->ocp & 80) && (ins->ocp & 40))
			proc->reg[ins->param[1]] = ft_get_int(curs, REG_SIZE);
		else
			proc->reg[ins->param[1]] = ins->param[0];
		if (ins->param[0] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else
		ins->size = 1;
	//ft_printf("reg[%d] = %d\n", ins->param[1], ins->param[0]);
	ft_print_ld(proc);
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
