/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:50:03 by rthys             #+#    #+#             */
/*   Updated: 2018/03/17 19:25:28 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include <limits.h>
#include "op.h"

void			next_arank(t_corewar *corewar)
{
	int i;

	i = 0;
	corewar->a_rank = 1;
	while (i < corewar->nb_champ)
	{
		if (corewar->a_rank == corewar->tab_champ[i].rank || \
		corewar->a_rank == corewar->n_rank)
		{
			corewar->a_rank++;
			i = 0;
		}
		else
			i++;
	}
}

int				available_nrank(t_corewar *corewar)
{
	int i;
	int unavailable;

	i = 0;
	unavailable = 0;
	while (i < corewar->nb_champ)
	{
		if (corewar->n_rank == corewar->tab_champ[i].rank)
		{
			if (unavailable == 1)
				corewar->a_rank++;
			unavailable = 1;
			corewar->n_rank = corewar->a_rank;
			i = -1;
		}
		i++;
	}
	if (unavailable == 1)
		corewar->a_rank = corewar->n_rank;
	else if (unavailable == 0 && corewar->n_rank == corewar->a_rank)
		next_arank(corewar);
	return (1);
}

int				nbr_champs(int argc, char **argv)
{
	int i;
	int champs;

	i = 1;
	champs = 0;
	while (i < argc)
	{
		if (ft_strequ(&argv[i][ft_strlen(argv[i]) - 4], ".cor"))
			champs++;
		i++;
	}
	return (champs);
}

unsigned int	options_value(int i, char **av)
{
	unsigned int	value;

	value = 0;
	if (ft_atoi(av[i + 1]) > 0)
		value = ft_atoi(av[i + 1]);
	return (value);
}

int				valid_options(int i, char **av)
{
	int j;

	j = 0;
	if (!av[i + 1])
		error_end("This option must be followed by a positive number", 5, av[i]);
	while (j < (int)ft_strlen(av[i + 1]))
	{
		if ((av[i + 1][j] >= '0' && av[i + 1][j] <= '9'))
			j++;
		else
			error_end("This option must be followed by a positive number", 5, av[i]);
	}
	return (1);
}

int				get_options(int i, char **av, t_corewar *corewar)
{
	if (ft_strequ(av[i], "-dump") && valid_options(i, av))
	{
		corewar->dump = options_value(i, av);
		if (corewar->dump > 0)
			i += 2;
		return (i);
	}
	else if (ft_strequ(av[i], "-n") && valid_options(i, av))
	{
		corewar->select = 1;
		corewar->n_rank = options_value(i, av);
		if (!available_nrank(corewar))
		{
			if (corewar->a_rank == corewar->n_rank)
				corewar->a_rank++;
			corewar->n_rank = corewar->a_rank;
		}
		i += 2;
		return (i);
	}
	return (0);
}
