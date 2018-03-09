/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:46 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/09 19:19:23 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void    ft_print_arena(unsigned char	*arena)
{
	unsigned int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%c", arena[i]);
		i++;
	}
}
