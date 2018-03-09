/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:37:31 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/09 15:04:56 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	ft_addlim (int decal)
{
	if(decal % MEM_SIZE <= IDX_MOD || decal % MEM_SIZE >= MEM_SIZE - IDX_MOD)
		return(decal);
	else if(decal > IDX_MOD)
		return(decal % IDX_MOD);
	else
		return((MEM_SIZE - decal) % IDX_MOD);
}
