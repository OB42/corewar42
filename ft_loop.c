/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:40 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/07 15:15:55 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

t_proc	*ft_init_proc(t_corewar corewar)
{
	t_proc	*lst_proc;
	t_proc	*init;
	int		i;

	i = 1;
	if (!(lst_proc = malloc(sizeof(t_proc))))
		exit(1);
	init = lst_proc;
	lst_proc->pc = 0;
	lst_proc->curseur = corewar.arena;
	lst_proc->carry = 0;
	lst_proc->nxt = init;
	lst_proc->player = i;
	while(corewar.tab_champ[i].code)
	{
		if (!(lst_proc->nxt = malloc(sizeof(t_proc))))
			exit(1);
		lst_proc = lst_proc->nxt;
		lst_proc->pc = 0;
		lst_proc->curseur = corewar.arena + i * (MEM_SIZE / corewar.nb_champ);
		lst_proc->carry = 0;
		lst_proc->nxt = init;
		lst_proc->player = i + 1;
		i++;
	}
	return (lst_proc);
}

void	ft_loop(t_corewar corewar)
{
	t_proc *lst_proc;

	lst_proc = ft_init_proc(corewar);
	while (lst_proc)
		lst_proc = lst_proc->nxt;
}

