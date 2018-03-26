/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   credits_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:58:51 by rthys             #+#    #+#             */
/*   Updated: 2018/03/26 19:28:52 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	visu_credits(t_corewar *corewar)
{
	int x;

	x = 76;
	mvwprintw(corewar->visu.win, 2, 102, "C O R E W A R");
	mvwprintw(corewar->visu.win, 3, 88, " by : ");
	wattron(corewar->visu.win, COLOR_PAIR(3));
	mvwprintw(corewar->visu.win, 3, 94, "mlegeay");
	wattroff(corewar->visu.win, COLOR_PAIR(3));
	mvwprintw(corewar->visu.win, 3, 101, ", ");
	wattron(corewar->visu.win, COLOR_PAIR(4));
	mvwprintw(corewar->visu.win, 3, 103, "obenazzo");
	wattroff(corewar->visu.win, COLOR_PAIR(4));
	mvwprintw(corewar->visu.win, 3, 111, ", ");
	wattron(corewar->visu.win, COLOR_PAIR(5));
	mvwprintw(corewar->visu.win, 3, 113, "rthys");
	wattroff(corewar->visu.win, COLOR_PAIR(5));
	mvwprintw(corewar->visu.win, 3, 118, ", ");
	wattron(corewar->visu.win, COLOR_PAIR(6));
	mvwprintw(corewar->visu.win, 3, 120, "vburidar");
	wattroff(corewar->visu.win, COLOR_PAIR(6));
	wrefresh(corewar->visu.win);
	wattron(corewar->visu.win, A_STANDOUT);
	while (++x < 138)
		mvwprintw(corewar->visu.win, 5, x, " ", A_STANDOUT);
	wattroff(corewar->visu.win, A_STANDOUT);
}
