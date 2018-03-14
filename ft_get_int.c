/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:34:04 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/14 16:54:51 by vburidar         ###   ########.fr       */
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
		ret = ret + *(code_champ + i - 1) * ft_pow((size - i), 256);
		i = i - 1;
	}
	return (ret);
}

void	ft_write_ram(int value, int size, unsigned char *ram)
{
	int i;
	unsigned long max;

	i = 0;
	max = ft_pow(size * 2, 16);
	//ft_printf("max %d\n", max);
	if (value < 0)
		max = max + value;
	else
		max = value;
	//ft_printf("size = %d\n", size);
	//ft_printf("value = %d\n", max);
	while (i < size)
	{
		//ft_printf("pow = %d\n", ft_pow((size - i - 1) * 2, 16));
		ram[i] = max / ft_pow((size - i - 1) * 2, 16);
		//ft_printf("ram[%d] = %d\n", i, ram[i]);
		i = i + 1;
	}
}
