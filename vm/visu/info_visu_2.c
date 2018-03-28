/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/03/28 20:56:58 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		visu_delta(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 12, INF + 3, "CYCLE_DELTA : %u", CYCLE_DELTA);
	wrefresh(corewar->visu.win);
}

void	visu_nbr_lives(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 14, INF + 3, "NBR_LIVES : %d", corewar->nb_live);
	wrefresh(corewar->visu.win);
}

void	visu_processes(t_corewar *corewar, int proc)
{
	mvwprintw(corewar->visu.win, 16, INF + 3, "Processes : %d", proc);
	wrefresh(corewar->visu.win);
}

void		visu_champs_arena(t_corewar *corewar, int pos, int prog_size, int color)
{
	int	y;
	int	x;
	int	i;

	x = ((pos % 62) + 3);
	y = ((pos / 62) + 1);
	i = pos;
	while (i < prog_size + pos)
	{
		while (x < 75)
		{
			wattron(corewar->visu.win, COLOR_PAIR(color));
			mvwprintw(corewar->visu.win, y, x, "%02x ", corewar->arena[i % MEM_SIZE]);
			wattroff(corewar->visu.win, COLOR_PAIR(color));
			x += 3;
			if (i + 1 > prog_size + pos)
				break ;
					i++;
		}
		y++;
		if (y > 62)
			y -= 61;
		x = 3;

	}
}
