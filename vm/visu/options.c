/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:50:03 by rthys             #+#    #+#             */
/*   Updated: 2018/04/09 16:05:04 by rthys            ###   ########.fr       */
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

unsigned int	options_value(int i, char **av)
{
	unsigned int	value;
	unsigned long	check_value;

	value = 0;
	check_value = ft_ulongatoi(av[i + 1]);
	if (ft_strlen(av[i] + 1) > 10 || check_value > UINT_MAX)
	{
		ft_printf("\x1b[31mWarning : \x1b[0mValue '%s' is too high\n"
				, av[i + 1]);
		if (ft_strequ(av[i], "-n"))
			value = 1;
		else
			value = -1;
	}
	else
		value = ft_uatoi(av[i + 1]);
	return (value);
}

int				valid_options(int i, char **av)
{
	int j;

	j = 0;
	if (!av[i + 1])
		error_end("This option must be followed by a positive number",
			5, av[i]);
	while (j < (int)ft_strlen(av[i + 1]))
	{
		if ((av[i + 1][j] >= '0' && av[i + 1][j] <= '9') ||
				(av[i + 1][j] == '+' && j == 0))
			j++;
		else
			error_end("This option must be followed by a positive number",
					5, av[i]);
	}
	return (1);
}

static void		n_option(t_corewar *corewar, char **av, int i)
{
	corewar->select = 1;
	corewar->n_rank = options_value(i, av);
	if (!available_nrank(corewar))
	{
		if (corewar->a_rank == corewar->n_rank)
			corewar->a_rank++;
		corewar->n_rank = corewar->a_rank;
	}
}

int				get_options(int i, char **av, t_corewar *corewar)
{
	if (ft_strequ(av[i], "-dump") && valid_options(i, av))
	{
		corewar->dump = options_value(i, av);
		i += 2;
	}
	else if (ft_strequ(av[i], "-n") && valid_options(i, av))
	{
		n_option(corewar, av, i);
		i += 2;
	}
	else if (ft_strequ(av[i], "-visu"))
	{
		corewar->visu_on = 1;
		i++;
	}
	else if (ft_strequ(av[i], "-v"))
	{
		corewar->verb = 1;
		i++;
	}
	else
		error_end("Not a valid option", 12, av[i]);
	return (i);
}
