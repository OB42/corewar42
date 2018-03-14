/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oob.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:51:26 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 16:50:02 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned char	*ft_oob(unsigned char *init, unsigned char *dest)
{
	unsigned char *tmp;

	if (dest - init > MEM_SIZE)
	{
		tmp = init + (dest - init) % MEM_SIZE;
		if (tmp < 0)
			return (MEM_SIZE + tmp);
		else
			return (tmp);
	}
	else if (dest - init < 0)
		return (init + (dest - init) + MEM_SIZE);
	return (dest);
}
