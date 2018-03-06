/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/06 12:16:50 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	while (n--)
		*((char *)d + n) = *((char *)s + n);
	return (d);
}
