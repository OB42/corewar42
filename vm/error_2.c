/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:50:29 by rthys             #+#    #+#             */
/*   Updated: 2018/03/19 12:58:50 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

void			error_end(char *error, int id_error, char *info)
{
	if (id_error == 0)
	{
		ft_putendl("Usage: ./corewar [-dump N] [[-n N] <champion.cor>] ...");
		ft_putendl("	-dump N: Dumps memory after N cycles then exits");
		ft_putendl("	-n N: Number N assigned to the following champion");
	}
	else
	{
		ft_putstr("\x1b[31mError ");
		ft_putnbr(id_error);
		ft_putstr(":\x1b[0m ");
		if (info)
		{
			ft_putstr(info);
			ft_putstr(": ");
		}
		ft_putendl(error);
	}
	exit(id_error);
}
