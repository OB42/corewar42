/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nxt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:45:21 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/19 16:31:32 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void	ft_print_nxt(unsigned char *init, unsigned char *curseur, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%02x ", *ft_oob(init, curseur + i));
		i++;
	}
	ft_printf("\n");
}

