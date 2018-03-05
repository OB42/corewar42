/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:14:11 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/05 15:27:27 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_arena(t_arena *arena, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arena[i] = value;
		i++;
	}
}

int		load_arena(t_arena *arena)
{
	arena->cycle_to_die_current == CYCLE_TO_DIE;
	if ((arena->arena = (char*)malloc(MEM_SIZE)) = NULL)
		return (-1);
	init_arena(arena, MEM_SIZE, 0);
	load_champs;
	return (0);
}
