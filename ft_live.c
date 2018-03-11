/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:22:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/11 22:40:10 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "LIBFT/libft.h"

void	ft_live(t_ins *ins, t_proc *proc)
{
	char param;

	proc->live = 1;
	ins->size = ins->size;
	param = (char)(ft_get_int(proc->curseur + 1, 4));
	proc->curseur = ft_oob(proc->init, proc->curseur + 5);
}
