/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/03/22 18:21:24 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		visu_ctd(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 14, 78, "Cycle to Die : %d", \
	corewar->ctd_obj);
	wrefresh(corewar->visu.win);
}

void		visu_champs_nbr(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 12, 78, "Champions : %d", corewar->nb_champ);
	wrefresh(corewar->visu.win);
}

void		visu_acycle(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 10, 78,"Cycle : %d", corewar->cycle);
	wrefresh(corewar->visu.win);
}
