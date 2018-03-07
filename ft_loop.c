/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:40 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/07 18:40:26 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_val_proc(t_proc *lst_proc, t_corewar corewar, int i, t_proc *init)
{
	lst_proc->curseur = corewar.arena + i * (MEM_SIZE / corewar.nb_champ);
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
	while(corewar.tab_champ[i].code)
	{
		i++;
		if (!(lst_proc->nxt = malloc(sizeof(t_proc))))
			exit(1);
		ft_val_proc(lst_proc, corewar, i, init);
		lst_proc = lst_proc->nxt;
	}
	return (lst_proc);
}

void	ft_loop(t_corewar corewar)
{
	t_proc *lst_proc;
	//t_ins *ins;

	lst_proc = ft_init_proc(corewar);
	while (lst_proc)
	{
		lst_proc = lst_proc->nxt;
		//lst_proc->curseur = ft_get_instru(lst_proc->curseur, ins);
		//ft_apply(ins, corewar, lst_proc);
		ft_print_arena(corewar.arena);
	}
}
