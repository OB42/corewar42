/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:40 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 14:46:44 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_val_proc(t_proc *lst_proc, t_corewar corewar, int i, t_proc *init)
{
	lst_proc->curseur = corewar.arena + i * (MEM_SIZE / corewar.nb_champ);
	ft_print_arena(corewar.arena);
	lst_proc->init = corewar.arena;
	lst_proc->pc = 0;
	lst_proc->carry = 0;
	lst_proc->nxt = init;
	lst_proc->player = i;
	lst_proc->live = 0;
}
	

t_proc	*ft_init_proc(t_corewar corewar)
{
	t_proc	*lst_proc;
	t_proc	*init;
	int		i;

	i = 0;
	if (!(lst_proc = malloc(sizeof(t_proc))))
		exit(1);
	init = lst_proc;
	ft_val_proc(lst_proc, corewar, i, init);
	i++;
	while(corewar.tab_champ[i].code)
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
	char	*line;

	lst_proc = ft_init_proc(corewar);
	while (lst_proc)
	{
		if (lst_proc->cycle != 0 && lst_proc->cycle == lst_proc->ins->cycle)
		{
			ft_printf("instruction applique %s\n", lst_proc->ins->name);
			(lst_proc->ins->fun)(lst_proc->ins, lst_proc);
			lst_proc->cycle = 0;
		}
		if (lst_proc->cycle == 0)
			lst_proc->ins = ft_get_instru(lst_proc->curseur);
		//ft_print_arena(corewar.arena);
		lst_proc->cycle++;
		if (lst_proc->ins == NULL)
		{
			ft_printf("ici\n");
			exit(1);
		}
		if (lst_proc->player == 0)
			corewar.cycle++;
		ft_printf("player %d, cycle corewar %d cycle processus %d plafond ins %d, nom ins %s\n", lst_proc->player, corewar.cycle, lst_proc->cycle, lst_proc->ins->cycle, lst_proc->ins->name);
		get_next_line(0, &line);
		lst_proc = lst_proc->nxt;
	}
}
