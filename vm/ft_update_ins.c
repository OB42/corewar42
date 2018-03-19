/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_ins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:15:43 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/19 19:53:14 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_update_ins(unsigned char *code_champ, unsigned char *init,  t_proc *proc)
{
	if (proc->ins->ocp == 0)
		proc->ins->param[0] = ft_get_int(code_champ + 1, proc->ins->size);
	else
	{
		proc->ins->ocp = *(code_champ + 1);
		ft_get_var(proc, code_champ + 2, init);
	}
	//ft_printf("%d\n", proc->ins->param[1]);
}
