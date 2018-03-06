/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:10:45 by rthys             #+#    #+#             */
/*   Updated: 2018/03/06 16:12:31 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int  ac, char **av)
{
	t_corewar	corewar;

	init_all(&corewar);
//	get_champs(ac, av, &arena);
	if (load_arena(&corewar) == -1)
		return (-1);
	ft_print_map(corewar.arena);
	return (0);
}
