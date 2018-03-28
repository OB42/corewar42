/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 08:37:18 by rthys            #+#    #+#              */
/*   Updated: 2018/03/28 20:56:46 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	visu_arena(t_corewar *corewar)
{
	unsigned int	i;
	int				x;
	int				y;


	i = 0;
	y = 1;
	while (i < MEM_SIZE)
	{
		x = 3;
		while (x < INF)
		{
			mvwprintw(corewar->visu.win, y, x, "00 ");
			x += 3;
			i++;
		}
		y++;
	}
}

static void	visu_sides(WINDOW *win)
{
	int x;
	int y;

	y = 0;
	while (y <= ORD)
	{
		x = 0;
		while (x <= ABS)
		{
			if ((y > 0 && y < ORD - 1) && (x == 0 || x == INF || \
			x == ABS - 2))
				mvwprintw(win, y, x, "  ");
			x++;
		}
		y++;
	}
}

static void	visu_top_bot(WINDOW *win)
{
	int x;
	int y;

	y = 0;
	while (y <= ORD)
	{
		x = 0;
		while (x <= ABS)
		{
			if (((y == 0 && x > 0) && (y == 0 && x < ABS - 1)) || \
			((y == ORD - 1 && x > 0) && (y == ORD - 1 && x < ABS - 1)))
				mvwprintw(win, y, x, " ");
			x++;
		}
		y++;
	}
}

static void	visu_corner(WINDOW *win)
{
	int x;
	int y;

	y = 0;
	while (y <= ORD)
	{
		x = 0;
		while (x <= ABS)
		{
			if ((y == 0 && x == 0) || (y == ORD - 1 && x == 0) || \
			(y == 0 && x ==  ABS - 1) || (y == ORD - 1 && x == ABS - 1))
				mvwprintw(win, y, x, " ");
			x++;
		}
		y++;
	}
}

void		global_visu(t_corewar *corewar, t_proc *lst_proc)
{
	int 	i;
	t_proc	*u_proc;

	i = 0;
	corewar->visu.win = initscr();
	noecho();
	curs_set(0);
	start_color();
	define_colors();
	wattron(corewar->visu.win, A_STANDOUT);
	visu_corner(corewar->visu.win);
	visu_top_bot(corewar->visu.win);
	visu_sides(corewar->visu.win);
	wattroff(corewar->visu.win, A_STANDOUT);
	visu_arena(corewar);
	visu_credits(corewar);
	visu_ctd(corewar);
	visu_acycle(corewar);
	visu_delta(corewar);
	visu_nbr_lives(corewar);
	visu_contestants(corewar);
	u_proc = lst_proc;
	while (i < corewar->nb_champ)
	{
		visu_champs_arena(corewar, u_proc->pc,\
		corewar->tab_champ[i].header.prog_size,\
		corewar->tab_champ[i].color);
		u_proc = u_proc->nxt;
		i++;
	}
}
