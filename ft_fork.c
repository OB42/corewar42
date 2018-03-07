/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:35:25 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/07 21:24:04 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_fork(t_ins *ins, t_proc *proc)
{
	t_proc *new;

	new = malloc(sizeof(t_proc));
	new = ft_memmove(new, proc, sizeof(t_proc));
	new->pc = proc->pc + (ins->param[0] % IDX_MOD);
	new->nxt = proc->nxt;
	proc->nxt = new;
}

void	ft_lfork(t_ins *ins, t_proc *proc)
{
	t_proc *new;
	
	new = malloc(sizeof(t_proc));
	new = ft_memmove(new, proc, sizeof(t_proc));
	new->pc = proc->pc + (ins->param[0] % MEM_SIZE);
	new->nxt = proc->nxt;
	proc->nxt = new;
}
