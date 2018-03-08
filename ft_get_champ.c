/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:56:03 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/08 11:54:23 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

uint32_t	swap_int32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

header_t	ft_get_header(int fd)
{
	header_t	header;
	unsigned int test;

	test = 0;
	read(fd, &(header), sizeof(header_t));
	header.magic = swap_int32(header.magic);
	header.prog_size = swap_int32(header.prog_size);
	return (header);
}

void	ft_ncpy(unsigned char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
			if (src[i] < 0)
				dest[i] = src[i] + 256;
			else
				dest[i] = src[i];
		i++;
	}
}

t_champ		ft_get_champ(char *filename)
{
	int		fd;
	t_champ	champ;
	char	code[10000];
	int		val_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("file does not exist\n");
		exit(1);
	}
	champ.header = ft_get_header(fd);
	val_read = read(fd, &code, champ.header.prog_size);
	if (!(champ.code = malloc(champ.header.prog_size * sizeof(char))))
		exit(1);
	ft_ncpy(champ.code, code, champ.header.prog_size);
	return (champ);
}
