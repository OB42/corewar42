/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_ins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:15:43 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 17:50:55 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

int		ft_no_ocp(char *name)
{
	if (ft_strcmp(name, "live") == 0)
		return (1);
	else if (ft_strcmp(name, "zjmp") == 0)
		return (1);
	if (ft_strcmp(name, "fork") == 0)
		return (1);
	if (ft_strcmp(name, "lfork") == 0)
		return (1);
	return (0);
}

void	ft_update_ins(unsigned char *code_champ, unsigned char *init,  t_proc *proc)
{
	
	if (ft_no_ocp(proc->ins->name) == 1)
	{
		proc->ins->param[0] = ft_get_int(init,
		code_champ + 1, proc->ins->size);
	}
	else
	{
		proc->ins->ocp = *ft_oob(init, code_champ + 1);
		//ft_printf("Avant proc[%d]->ocp =  %d\n", proc->id, proc->ins->ocp);
		if (*code_champ < 1 || *code_champ > 16)
			proc->ins->fail = 1;
		ft_get_var(proc, ft_oob(init, code_champ + 2), init);
		//ft_printf("Apres proc[%d]->ocp =  %d size = %d\n", proc->id, proc->ins->ocp, proc->ins->size);
	}
}
