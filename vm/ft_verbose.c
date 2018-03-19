/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:47:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/19 19:46:00 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

void ft_print_ocp_suite(t_proc *proc, int mask_1, int mask_2, int param, int type)
{
	if (proc->ins->ocp & mask_2 && proc->ins->ocp & mask_1
			&& type)
		ft_printf(" %d", proc->ins->tab[param].val_type);
	else if (proc->ins->ocp & mask_2 && !type)
		ft_printf(" %d", proc->ins->param[param]);
	else if (proc->ins->ocp & mask_2)
		ft_printf(" %d", proc->ins->tab[param].val_type, proc);
	else if (proc->ins->ocp & mask_1 && type)
		ft_printf(" %d", proc->ins->tab[param].val_type);
	else if (proc->ins->ocp & mask_1)
		ft_printf(" r%d", proc->ins->param[param]);
}

void ft_print_ocp(t_proc *proc, int param1, int param2, int param3)
{
	ft_print_ocp_suite(proc, 0x40, 0x80, 0, param1);
	ft_print_ocp_suite(proc, 0x10, 0x20, 1, param2);
	ft_print_ocp_suite(proc, 0x4, 0x8, 2, param3);
}
