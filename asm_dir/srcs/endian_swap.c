/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/04/12 18:58:54 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		endian_swap_32(int n)
{
	n = ((n << 8) & 0xFF00FF00) | ((n >> 8) & 0xFF00FF);
	return (n << 16) | ((n >> 16) & 0xFFFF);
}

short	endian_swap_16(short n)
{
	return (n << 8) | ((n >> 8) & 0xFF);
}