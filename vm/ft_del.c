/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:53:49 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 17:00:57 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

t_proc	*ft_del(t_proc *lst_proc)
{
	t_proc *curseur;

	curseur = lst_proc;
	while (curseur->nxt->id != lst_proc->id)
		curseur = curseur->nxt;
	if (curseur == lst_proc)
		return (NULL);
	curseur->nxt = lst_proc->nxt;
	return (curseur->nxt);
}
