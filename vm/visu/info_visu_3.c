/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/04/04 21:42:59 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

/*void		visu_hl(t_corewar *corewar, int i, int mode)
{
	int x;
	int y;

	x = ((i % 64) * 3) + 3;
	y = (i / 64) + 1;
	if (mode == 0)
	{
		if (x == 3 && y == 1) 
			visu_hl(corewar, MEM_SIZE - 1, 1);
		else
			visu_hl(corewar, i - 1, 1);
		if (y > 64)
			y -= 63;
		wattron(corewar->visu.win, A_STANDOUT | COLOR_PAIR(corewar->arena_id[i]));
		mvwprintw(corewar->visu.win, y, x, "%02x", corewar->arena[i]);
		wattroff(corewar->visu.win, A_STANDOUT | COLOR_PAIR(corewar->arena_id[i]));
	}
	else
	{
		if (y > 64)
			y -= 63;
		wattron(corewar->visu.win, COLOR_PAIR(corewar->arena_id[i]));
		mvwprintw(corewar->visu.win, y, x, "%02x", corewar->arena[i]);
		wattroff(corewar->visu.win, COLOR_PAIR(corewar->arena_id[i]));
	}
}*/

void		visu_winner(t_corewar *corewar)
{
	char inp;

	inp = 0;
	wattron(corewar->visu.win, COLOR_PAIR(corewar->last_live_id + 1));
	mvwprintw(corewar->visu.win, 45, INF + 3, "Constestant %u, \"%s\", has won !", \
	corewar->tab_champ[corewar->last_live_id].rank, \
	corewar->tab_champ[corewar->last_live_id].header.prog_name);
	wattroff(corewar->visu.win, COLOR_PAIR(corewar->last_live_id + 1));
	mvwprintw(corewar->visu.win, 48, INF + 3, "PRESS ANY KEY TO EXIT");
	wrefresh(corewar->visu.win);
	while (1)
	{
		inp = wgetch(corewar->visu.win);
		if (inp > 0)
			visu_inp(corewar, 27);
	}
}

void		visu_speed(t_corewar *corewar)
{
	if (corewar->cycle <= 1000)
		usleep(825000 / corewar->cbs);
	else if (corewar->cycle > 1000 && corewar->cycle <= 1900)
		usleep(400000 / corewar->cbs);
	else if (corewar->cycle > 1900 && corewar->cycle <= 3000)
		usleep(200000 / corewar->cbs);
}

void		visu_inp(t_corewar *corewar, char inp)
{
	if (inp == 27)
	{
		endwin();
		exit(0);
	}
	else if (inp == '+' && corewar->cbs <= 195)
	{
		corewar->cbs += 5;
		visu_cbs(corewar);
	}
	else if (inp == '-' && corewar->cbs >= 55)
	{
		corewar->cbs -= 5;
		visu_cbs(corewar);
	}
	else if (inp == ' ')
		visu_run(corewar);
	wrefresh(corewar->visu.win);
}

void		visu_run(t_corewar *corewar)
{
	char	*run;
	char	inp;

	run = NULL;
	inp = 0;
	if (corewar->visu.run == 0)
	{
		run = ">> START <<";
		corewar->visu.run = 1;
	}
	else
	{
		run = ">> PAUSE <<";
		corewar->visu.run = 0;
	}
	mvwprintw(corewar->visu.win, 7, INF + 6, " %s", run);
	wrefresh(corewar->visu.win);
	while (corewar->visu.run == 0 && (inp = wgetch(corewar->visu.win)) != ' ')
		visu_inp(corewar, inp);
	if (corewar->visu.run == 0)
		visu_run(corewar);
}
