/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:46 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/08 12:02:43 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void    ft_print_arena(unsigned char *arena, t_corewar *corewar)
{
	unsigned int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (corewar->arena_id[i] == 1)
			ft_printf("%s%02x ", KRED, arena[i]);
		else if (corewar->arena_id[i] == 2)
			ft_printf("%s%02x ", KGRN, arena[i]);
		else if (corewar->arena_id[i] == 3)
			ft_printf("%s%02x ", KYEL, arena[i]);
		else if (corewar->arena_id[i] == 4)
			ft_printf("%s%02x ", KBLU, arena[i]);
		else if (corewar->arena_id[i] == 5)
			ft_printf("%s%02x ", KMAG, arena[i]);
		else
		{
			ft_printf("%s%02x ", KWHT, arena[i]);
		}
		i++;
		if ((i % 16) == 0)
			ft_printf("\n");
	}
}
