/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:14:11 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/06 16:21:37 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_arena(t_corewar *corewar, int size, int value)
{
	int	i;

	i = 0;
	while (i < (4*size))
	{
		if ((i + 3) % 4 == 0)
			corewar->arena[i] = 'x';
		else
			corewar->arena[i] = value + 48;
		i++;
	}
}

int		load_arena(t_corewar *corewar)
{
	corewar->cycle_to_die_current = CYCLE_TO_DIE;
//	if ((corewar->arena_id_champs = (char*)malloc(MEM_SIZE)) == NULL)
//		return (-1);
	init_arena(corewar, MEM_SIZE, 0);
	if (load_champs(corewar) == -1)
		return (-1);
	return (0);
}
