/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:40 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/16 20:31:20 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_val_proc(t_proc *lst_proc, t_corewar *corewar, int i, t_proc *init)
{
	ft_bzero(lst_proc, sizeof(t_proc));
	lst_proc->curseur = corewar->arena + i * (MEM_SIZE / corewar->nb_champ);
	lst_proc->live = 1;
	lst_proc->init = corewar->arena;
	lst_proc->corewar = corewar;
	lst_proc->nxt = init;
	lst_proc->player = i + 1;
	lst_proc->reg[1] = -lst_proc->player;
	lst_proc->ins = NULL;
	lst_proc->id = ft_get_procnb(lst_proc);
//	ft_printf("id = %d\n", lst_proc->id);
	lst_proc->champ = corewar->tab_champ[0];
}

t_proc	*ft_init_proc(t_corewar *corewar)
{
	t_proc	*lst_proc;
	t_proc	*init;
	int		i;

	i = 0;
	if (!(lst_proc = malloc(sizeof(t_proc))))
		exit(1);
	init = lst_proc;
	lst_proc->id = 0;
	ft_val_proc(lst_proc, corewar, i, init);
	i++;
	while(corewar->tab_champ[i].code)
	{
		if (!(lst_proc->nxt = malloc(sizeof(t_proc))))
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

	if (proc->id > max_id)
		max_id = proc->id;
	if (proc->id == max_id)
	{
		corewar->cycle++;
		corewar->ctd_cur++;
		ft_printf("It is now cycle %d\n", corewar->cycle);
	}
	if (corewar->ctd_cur == corewar->ctd_obj)
	{
		proc = ft_cycle_to_die(corewar, proc);
		if (proc == NULL)
			return (NULL);
		max_id = ft_get_procnb(proc) - 1;
	}
	proc->cycle++;
	proc->last_live++;
	return (proc);
}

int		ft_loop(t_corewar corewar)
{
	t_proc *lst_proc;
	int		test;

	lst_proc = ft_init_proc(&corewar);
	while (lst_proc)
	{
		test = 0;
		lst_proc = ft_cycle(lst_proc, &corewar);
		if (lst_proc == NULL)
			exit(1);
		if (lst_proc->cycle > 1 && lst_proc->cycle == lst_proc->ins->cycle)
		{
			//system("clear");
			//ft_print_arena(corewar.arena);
			ft_update_ins(lst_proc->curseur, lst_proc->init, lst_proc);
			ft_verbose(lst_proc);
			(lst_proc->ins->fun)(lst_proc->ins, lst_proc);
			lst_proc->cycle = 0;
			test = 1;
			//ft_print_nxt(lst_proc->init, lst_proc->curseur, 200);
		}
		if (lst_proc->cycle <= 1)
			lst_proc->ins = ft_get_instru(lst_proc->curseur, lst_proc->init);
		if (lst_proc->ins == NULL && test == 0)
		{
			lst_proc->curseur = ft_oob(lst_proc->init, lst_proc->curseur + 1);
			lst_proc->cycle = 0;
		}
		lst_proc = lst_proc->nxt;
		if (lst_proc == NULL || corewar.ctd_obj < 0 || corewar.cycle > 150)
		{
			ft_output_arena(corewar);
			return (1);
		}
	}
	return (0);
}
