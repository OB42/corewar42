/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:18:27 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/06 12:14:24 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	c;
	int		e;

	e = 0;
	c = 0;
	while (c < n)
	{
		if (!src[c])
			e = 1;
		dest[c] = e ? 0 : src[c];
		c++;
	}
	return (dest);
}
