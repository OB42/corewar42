/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_who_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:55:26 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/16 17:01:17 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		who_win(t_corewar *corewar)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < corewar->nb_champ)
	{
		ft_printf("* Player %i, weighing %i bytes, %s (%s) !\n", i + 1, corewar->tab_champ[i].header.prog_size, corewar->tab_champ[i].header.prog_name, corewar->tab_champ[i].header.comment);
		i++;
	}
	ft_printf("Contestant %i, %s, has won !\n", corewar->last_live + 1, corewar->tab_champ[corewar->last_live].header.prog_name, corewar->tab_champ[corewar->last_live].header.comment);
}
