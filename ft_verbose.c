/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:47:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 19:31:33 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

int		ft_valid_instru(char *name)
{
	if (ft_strcmp(name, "sti") == 0)
		return (1);
	if (ft_strcmp(name, "zjmp") == 0)
		return (1);
	if (ft_strcmp(name, "fork") == 0)
		return (1);
	if (ft_strcmp(name, "live") == 0)
		return (1);
	if (ft_strcmp(name, "ldi") == 0)
		return (1);
	return (0);
}

int		ft_conv(int param, t_proc *proc)
{
	int ret;

	if (ft_valid_instru(proc->ins->name))
	{
		ret = param % MEM_SIZE;
		if (ft_strcmp(proc->ins->name, "live") == 0)
			return ((char) ret);
		if(ft_abs(ret) > IDX_MOD && ft_abs(MEM_SIZE - ret) > IDX_MOD)
			ret = param % IDX_MOD;
		if (ft_abs(MEM_SIZE - ret) < IDX_MOD)
				return (ret - MEM_SIZE);
		else
			return (ret);
	}
	return (param);
}

void ft_print_ocp(t_proc *proc)
{
	if (proc->ins->ocp & 0x80)
		ft_printf(" %d", ft_conv(proc->ins->param[0], proc));
	else if (proc->ins->ocp & 0x40)
		ft_printf(" r%d", proc->ins->param[0]);
	if (proc->ins->ocp & 0x20)
		ft_printf(" %d", ft_conv(proc->ins->param[1], proc));
	else if (proc->ins->ocp & 0x10)
		ft_printf(" r%d", proc->ins->param[1]);
	if (proc->ins->ocp & 0x8)
		ft_printf(" %d", ft_conv(proc->ins->param[2], proc));
	else if (proc->ins->ocp & 0x4 && ft_strcmp(proc->ins->name, "sti"))
		ft_printf(" r%d", proc->ins->param[2]);
	else if (ft_strcmp(proc->ins->name, "sti") == 0 && (proc->ins->ocp & 4))
		ft_printf(" %d", proc->reg[proc->ins->param[2]]);
}

void	ft_print_special(t_proc *proc)
{
	if (ft_strcmp(proc->ins->name, "fork") == 0)
		ft_printf(" (%d)", proc->curseur - proc->init + ft_conv(proc->ins->param[0], proc));
	if (ft_strcmp(proc->ins->name, "zjmp") == 0)
	{
		if (proc->carry == 1)
			ft_printf(" OK\n");
		else
		{
			ft_printf(" FAILED\n");
			ft_print_instru(proc);
		}
	}
	if (ft_strcmp(proc->ins->name, "live") == 0)
	{
		ft_printf(" %d", proc->ins->param[0]);	
		if (proc->ins->param[0] == proc->reg[1])
			ft_printf("\nPlayer %d (%s) is said to be alive", proc->player, proc->champ.header.prog_name);
	}
}

int		ft_invalid_print(char *name)
{
	if (ft_strcmp(name, "sti") == 0)
		return (1);
	if (ft_strcmp(name, "st") == 0)
		return (1);
	if (ft_strcmp(name, "ldi") == 0)
		return (1);
	if (ft_strcmp(name, "lldi") == 0)
		return (1);
	if (ft_strcmp(name, "ld") == 0)
		return (1);
	return (0);
}

void	ft_verbose(t_proc *proc)
{
	if (ft_invalid_print(proc->ins->name) == 0)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc);
		if (proc->ins->ocp == 0 && ft_strcmp("live", proc->ins->name) != 0)
			ft_printf(" %d", ft_conv(proc->ins->param[0], proc));
		ft_print_special(proc);
		if (ft_strcmp(proc->ins->name, "zjmp") != 0 && ft_strcmp(proc->ins->name, "sti") != 0)
		{
			ft_printf("\n");
			ft_print_instru(proc);
		}
	}
}
