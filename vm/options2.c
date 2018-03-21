/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:42:20 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/21 16:43:59 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		nbr_champs(int argc, char **argv)
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
