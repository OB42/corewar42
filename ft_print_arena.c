/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:46 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/07 16:19:26 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void    ft_print_arena(unsigned char	*arena)
{
	unsigned int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02x ", arena[i]);
		i++;
		if ((i % 16) == 0)
			ft_printf("\n");
	}
}
