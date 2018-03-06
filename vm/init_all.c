/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:10:50 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/06 15:05:32 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_all(t_corewar *corewar)
{
	int	i;

	i = 0;
	corewar->nb_champs = 2;
	corewar->last_champ = NULL;
	corewar->last_live_champ = 0;
	corewar->cycle_to_die_current = 0;
	corewar->champ[1].filename = "test";
	corewar->champ[1].name = "Lepif";
	corewar->champ[1].comment = "jsuis nul";
	while (i++ < 16)
		corewar->champ[1].reg[i] = 0;
	corewar->champ[1].size = 0;
	corewar->champ[1].color = 0;
	corewar->champ[1].placed = 0;
	corewar->champ[1].adress = 0;
	corewar->champ[1].start = 0;
	corewar->champ[1].pc = 0;
	corewar->champ[1].carry = 0;
	corewar->champ[1].len = 0;
}
