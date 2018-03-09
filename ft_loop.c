/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:40 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/09 19:25:47 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_val_proc(t_proc *lst_proc, t_corewar *corewar, int i, t_proc *init)
{
	ft_bzero(lst_proc, sizeof(t_proc));
	lst_proc->curseur = corewar->arena + i * (MEM_SIZE / corewar->nb_champ);
	lst_proc->init = corewar->arena;
	lst_proc->pc = 0;
	lst_proc->corewar = corewar;
	lst_proc->carry = 0;
	lst_proc->nxt = init;
	lst_proc->player = i;
	lst_proc->live = 0;
	lst_proc->ins = NULL;
	lst_proc->id = ft_get_procnb(lst_proc);
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

void	ft_loop(t_corewar corewar)
{
	t_proc *lst_proc;

	lst_proc = ft_init_proc(&corewar);
	while (lst_proc)
	{
		if (lst_proc->cycle != 0 && lst_proc->cycle == lst_proc->ins->cycle)
		{
			(lst_proc->ins->fun)(lst_proc->ins, lst_proc);
			lst_proc->cycle = 0;
			ft_print_arena(corewar.arena);
		}
		if (lst_proc->cycle == 0)
			lst_proc->ins = ft_get_instru(lst_proc->curseur);
		lst_proc->cycle++;
		if (lst_proc->ins == NULL)
			exit(1);
		if (lst_proc->player == 0)
			corewar.cycle++;
		lst_proc = lst_proc->nxt;
		if (corewar.cycle == 20000)
			exit(1);
	}
}
