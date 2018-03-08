/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oob.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:51:26 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 16:52:38 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned char	*ft_oob(unsigned char *init, unsigned char *dest)
{
	if (dest - init > MEM_SIZE)
		return (init + (dest - init) % MEM_SIZE);
	else
		return (dest);
}
