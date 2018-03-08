/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:35:25 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 19:27:11 by vburidar         ###   ########.fr       */
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
	new->curseur = ft_oob(proc->init, proc->curseur + ins->param[0]);
	new->nxt = proc->nxt;
	proc->nxt = new;
	new->ins = NULL;
	new->cycle = 0;
	proc->curseur = proc->curseur + 3;
}

void	ft_lfork(t_ins *ins, t_proc *proc)
{
	t_proc *new;
	
	new = malloc(sizeof(t_proc));
	new = ft_memmove(new, proc, sizeof(t_proc));
	new->curseur = ft_oob(proc->init, proc->curseur + ins->param[0] % MEM_SIZE);
	new->nxt = proc->nxt;
	proc->nxt = new;
	proc->curseur = proc->curseur + 3;
}
