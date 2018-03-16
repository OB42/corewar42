/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_ocp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:56:37 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/16 18:37:37 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

int ft_mask_ocp(int val_1, int val_2, int ocp)
{
	if((ocp & val_1) && (ocp & val_2))
	{
		//ft_printf("3\n");
		return(3);
	}
	if(ocp & val_2)
	{
		//ft_printf("1\n");
		return(2);
	}
	if(ocp & val_1)
	{
		//ft_printf("2\n");
		return (1);
	}
	else
	{
		//ft_printf("ERREUR\n");
		return (0);
	}
}

int	ft_val_ocp(int ocp, int param)
{
	if (param == 0)
		return(ft_mask_ocp(0x40, 0x80, ocp));
	if (param == 1)
		return(ft_mask_ocp(0x10, 0x20, ocp));
	if (param == 2)
		return(ft_mask_ocp(0x4, 0x8, ocp));
	return(-1);
}
