/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/06 12:15:46 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft.h"

char	*ft_strchr(const char *d, int c)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(d);
	if (!n && c)
		return (NULL);
	while (i <= n)
	{
		if ((char)c == (char)(d[i]))
			return ((char *)(d + i));
		i++;
	}
	return (NULL);
}
