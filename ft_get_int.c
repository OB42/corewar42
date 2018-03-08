/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:34:04 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 18:42:51 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

int	ft_pow(int time, int val)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (i < time)
	{
		ret = ret * val;
		i++;
	}
	return (ret);
}

int	ft_get_int(unsigned char *code_champ, int size)
{
	int i;
	int ret;
	
	i = size;
	ret = 0;
	while (i > 0)
	{
		if (*(code_champ + i - 1) < 0)
			ret = ret + (*(code_champ + i - 1) + 256) * ft_pow((size - i) * 2, 16);
		else
			ret = ret + *(code_champ + i - 1) * ft_pow((size - i) * 2, 16);
		i = i - 1;
	}
	return (ret);
}
