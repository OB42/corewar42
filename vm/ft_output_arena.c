/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:37:59 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 21:19:12 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "LIBFT/libft.h"
#include "op.h"

void	ft_output_arena(t_corewar *corewar)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("%s0x%04x : ", i ? "\n" : "", i);
		ft_printf("%02x ", corewar->arena[i]);
		i++;
	}
	ft_printf("\n");
	exit(0);
}
