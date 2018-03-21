/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:40 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 16:20:59 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_val_proc(t_proc *lst_proc, t_corewar *corewar, int i, t_proc *init)
{
	ft_bzero(lst_proc, sizeof(t_proc));
	lst_proc->curseur = corewar->arena + i * (MEM_SIZE / corewar->nb_champ);
	lst_proc->live = 0;
	lst_proc->init = corewar->arena;
	lst_proc->corewar = corewar;
	lst_proc->nxt = init;
	lst_proc->player = i + 1;
	lst_proc->reg[1] = -lst_proc->player;
	lst_proc->ins = NULL;
	lst_proc->id = ft_get_procnb(lst_proc);
	corewar->id_max++;
//	ft_printf("id = %d\n", lst_proc->id);
	lst_proc->champ = corewar->tab_champ[0];
}

t_proc	*ft_init_proc(t_corewar *corewar)
{
	t_proc	*lst_proc;
	t_proc	*init;
	int		i;

	i = 0;
	corewar->id_max = 1;
	if (!(lst_proc = pr_malloc(sizeof(t_proc))))
		exit(1);
	init = lst_proc;
	lst_proc->id = 0;
	ft_val_proc(lst_proc, corewar, i, init);
	i++;
	while(corewar->tab_champ[i].code)
	{
		if (!(lst_proc->nxt = pr_malloc(sizeof(t_proc))))
			exit(1);
		lst_proc = lst_proc->nxt;
		ft_val_proc(lst_proc, corewar, i, init);
		i++;
	}
	return (lst_proc);
}

t_proc	*ft_cycle(t_proc *proc, t_corewar *corewar)
{
	static int	max_id = 1;

	max_id = ft_get_procnb(proc) - 1;
	if ((corewar->ctd_cur == corewar->ctd_obj || corewar->ctd_obj < 0)
		&& proc->id == max_id)
	{
		proc = ft_cycle_to_die(corewar, proc);
		if (proc == NULL)
			return (NULL);
		max_id = ft_get_procnb(proc) - 1;
	}
	if (proc->id > max_id)
		max_id = proc->id;
	if (proc->id == max_id)
	{
		corewar->cycle++;
		corewar->ctd_cur++;
		ft_printf("It is now cycle %d\n", corewar->cycle);
	}
	proc->cycle++;
	proc->last_live++;
	return (proc);
}

int		ft_loop(t_corewar *corewar)
{
	t_proc *lst_proc;
	int		test;

	lst_proc = ft_init_proc(corewar);
	while (lst_proc)
	{
		test = 0;
		lst_proc = ft_cycle(lst_proc, corewar);
		if (lst_proc == NULL)
			return (1);
		//if (lst_proc->id == 26)
			//ft_printf("proc[%d] -> ram[%d] = %d\n", lst_proc->id, lst_proc->curseur - lst_proc->init, *lst_proc->curseur, lst_proc->carry);
		if (lst_proc->cycle > 1 && lst_proc->cycle == lst_proc->ins->cycle)
		{
			//ft_print_arena(corewar->arena);
			ft_update_ins(lst_proc->curseur, lst_proc->init, lst_proc);
			if (lst_proc->ins != NULL)
				(lst_proc->ins->fun)(lst_proc->ins, lst_proc);
			lst_proc->cycle = 0;
			//ft_printf("proc[%d] -> ram[%d] = %d", lst_proc->id, lst_proc->curseur - lst_proc->init, *lst_proc->curseur, lst_proc->carry);
			test = 1;
		}
		if (lst_proc->cycle <= 1)
			lst_proc->ins = ft_get_instru(lst_proc->curseur, lst_proc->init);
		if (lst_proc->ins == NULL && test == 0)
		{
			lst_proc->curseur = ft_oob(lst_proc->init, lst_proc->curseur + 1);
			lst_proc->cycle = 0;
		}
		lst_proc = lst_proc->nxt;
		if (corewar->cycle == corewar->dump)
		{
			if (corewar->dump > -1)
				ft_output_arena(corewar);
			return (1);
		}
	}
	return (1);
}
