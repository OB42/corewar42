/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:06:45 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/19 12:35:37 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

static void		ft_display_contestant(t_corewar *corewar, int mode)
{
	int i;

	if (mode == 0)
	{
		i = 0;
		ft_printf("Introducing contestants...\n");
		while (i < corewar->nb_champ)
		{
			ft_printf("* Player %u, weighing %i bytes, \"%s\" (\"%s\") !\n",\
			corewar->tab_champ[i].rank, corewar->tab_champ[i].header.prog_size, \
			corewar->tab_champ[i].header.prog_name, \
			corewar->tab_champ[i].header.comment);
			i++;
		}
	}
	else if (mode == 1)
	{
		ft_printf("Contestant %u, \"%s\", has won !\n", \
		corewar->tab_champ[corewar->last_live_id].rank,\
		corewar->tab_champ[corewar->last_live_id].header.prog_name, \
		corewar->tab_champ[corewar->last_live_id].header.comment);
	}
}

void			ft_print_code(t_champ champ)
{
	unsigned int i;

	i = 0;
	while (i < champ.header.prog_size)
	{
		ft_printf("%02x ", champ.code[i]);
		i++;
		if ((i % 16) == 0)//TEMPORARY
			ft_printf("\n");
	}
}

static void		ft_init_all(int argc, char **argv, t_corewar *corewar)
{
	int 		i;
	int			champ;

	i = 1;
	champ = -1;
	ft_bzero(corewar, sizeof(t_corewar));
	if ((corewar->nb_champ = nbr_champs(argc, argv)) == 0)
		error_end(NULL, 0, NULL);
	corewar->a_rank = 1;
	corewar->n_rank = 1;
	corewar->select = 0;
	corewar->dump = -1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			i = get_options(i, argv, corewar);
		else
			corewar->tab_champ[++champ] = ft_get_champ(argv[i++], corewar);
	}
	corewar->ctd_obj = CYCLE_TO_DIE;
}

int 			main(int argc, char **argv)
{
	t_corewar	corewar;
	t_ins		*instru;

	instru = NULL;
	if (argc > 1)
	{
		ft_init_all(argc, argv, &corewar);
		load_arena(&corewar);
		ft_display_contestant(&corewar, 0);
		//while (1); RETIRER COMMENT POUR CHECKER RANK
		ft_loop(&corewar);
		ft_display_contestant(&corewar, 1);
	}
	else
		error_end(NULL, 0, NULL);
	return (0);
}
