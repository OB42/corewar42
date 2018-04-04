/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/04/04 20:13:45 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	visu_keys(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 36, INF + 3, "'+' : +5 Cycle/s");
	mvwprintw(corewar->visu.win, 38, INF + 3, "'-' : -5 Cycle/s");
	mvwprintw(corewar->visu.win, 40, INF + 3, "'SPACE' : Start/Pause");
	mvwprintw(corewar->visu.win, 42, INF + 3, "'ESC' : Exit");
	wrefresh(corewar->visu.win);
}