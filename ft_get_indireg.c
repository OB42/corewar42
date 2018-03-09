/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_indireg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:54:24 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/09 16:49:00 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

unsigned char	*ft_get_ind(t_ins *ins, unsigned char *curseur, int n_param)
{
	//ft_printf("INDEX ");
	if (n_param == 1)
		ins->param[n_param] = 16 * *(curseur) + *(curseur + 1);
	ins->size = ins->size + 2;
	return(curseur + 2);
}

unsigned char	*ft_get_dir(t_ins *ins, unsigned char *curseur, int n_param)
{
	//ft_printf("DIRECT ");
	if(ft_strcmp (ins->name, "ldi") == 0 ||
		ft_strcmp (ins->name, "sti") == 0 ||
		ft_strcmp (ins->name, "lldi") == 0 ||
		ft_strcmp (ins->name, " ") == 0 ||
		ft_strcmp (ins->name, " ") == 0)
	{
		ins->size = ins->size + 2;
		ins->param[n_param] = 256 * *(curseur) + *(curseur + 1);
		return (curseur + 2);
	}
	else
	{
		ins->param[n_param] = 256 * 256 * 256 * *(curseur) +
			256 * 256 * *(curseur + 1) + 256 * *(curseur + 2)
			+ *(curseur + 3);
		ins->size = ins->size + 4;
		return (curseur + 4);
	}
}

unsigned char	*ft_get_reg(t_ins *ins, unsigned char *curseur, int n_param)
{
	//ft_printf("REGISTRE ");
	ins->param[n_param] = *curseur;
	ins->size = ins->size + 1;
	return (curseur + 1);
}
