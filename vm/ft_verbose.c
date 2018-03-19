/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:47:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/19 16:13:00 by vburidar         ###   ########.fr       */
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

void	ft_print_special(t_proc *proc)
{
	t_proc	*init;
	int		param;

	param = 0;
	if (ft_strcmp(proc->ins->name, "live") == 0)
	{
		ft_printf(" %d", proc->ins->param[0]);
		init = proc;
		param = proc->ins->param[0];
		while (proc->nxt != init && param != 100)
		{
			if (param == proc->reg[1])
			{
				ft_printf("\nPlayer %d (%s) is said to be alive",
				-proc->ins->param[0], proc->corewar->tab_champ[-proc->ins->param[0] - 1].header.prog_name);
				param = 100;
			}
			else
				proc = proc->nxt;
		}
	}
}

int		ft_invalid_print(char *name)
{
	static char *a[15] = {
		"sti", "st", "ldi", "lldi", "ld", "and", "or", "xor", "add",
	"fork", "lfork", "zjmp", "lld", "live", "sub"
	};
	int i;

	i = 0;
	while (i < 15)
	{
		if (!(ft_strcmp(name, a[i++])))
			return (1);
	}
	return (0);
}

void	ft_verbose(t_proc *proc)
{
	if (ft_invalid_print(proc->ins->name) == 0)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc, 0, 0, 0);
		if (proc->ins->ocp == 0 && ft_strcmp("live", proc->ins->name) != 0)
			ft_printf(" %d", proc->ins->param[0], proc);
		ft_print_special(proc);
		if (ft_strcmp(proc->ins->name, "zjmp") != 0 && ft_strcmp(proc->ins->name, "sti") != 0)
		{
			ft_printf("\n");
			ft_print_instru(proc);
		}
	}
}
