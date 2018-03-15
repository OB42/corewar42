/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:06:45 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 22:02:05 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_code(t_champ champ)
{
	unsigned int i;

	i = 0;
	while (i < champ.header.prog_size)
	{
		ft_printf("%02x ", champ.code[i]);
		i++;
		if ((i % 16) == 0)
			ft_printf("\n");
	}
}

t_corewar	ft_init_all(int argc, char **argv)
{
	int i;
	t_corewar	corewar;

	i = 1;
	ft_bzero(&corewar, sizeof(t_corewar));
	while (i < argc)
	{
		corewar.tab_champ[i - 1] = ft_get_champ(argv[i]);
		i++;
	}
	corewar.nb_champ = i - 1;
	corewar.ctd_obj = CYCLE_TO_DIE;
	return (corewar);
}

int main(int argc, char **argv)
{
	t_corewar	corewar;
	t_ins			*instru;

	instru = NULL;
	corewar = ft_init_all(argc, argv);
	load_arena(&corewar);
	ft_loop(corewar);
	return (0);
}