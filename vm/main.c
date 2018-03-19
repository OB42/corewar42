/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:06:45 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 16:46:20 by vburidar         ###   ########.fr       */
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

void	ft_init_all(int argc, char **argv, t_corewar *corewar)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		write(2, "Usage: ./corewar blablabla\n", 27);
		exit(1);
	}
	ft_bzero(corewar, sizeof(t_corewar));
	while (i < argc && i <= MAX_PLAYERS)
	{
		corewar->tab_champ[i - 1] = ft_get_champ(argv[i]);
		i++;
	}
	corewar->nb_champ = i - 1;
	corewar->ctd_obj = CYCLE_TO_DIE;
}

int main(int argc, char **argv)
{
	t_corewar	corewar;
	t_ins			*instru;
	int i;

	i = 0;
	instru = NULL;
	ft_init_all(argc, argv, &corewar);
	load_arena(&corewar);
	ft_printf("Introducing contestants...\n");
	while (i < corewar.nb_champ)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", i + 1, corewar.tab_champ[i].header.prog_size, corewar.tab_champ[i].header.prog_name, corewar.tab_champ[i].header.comment);
		i++;
	}
	ft_loop(&corewar);
	ft_printf("Contestant %i, \"%s\", has won !\n", corewar.last_live_id + 1, corewar.tab_champ[corewar.last_live_id].header.prog_name, corewar.tab_champ[corewar.last_live_id].header.comment);
	return (0);
}
