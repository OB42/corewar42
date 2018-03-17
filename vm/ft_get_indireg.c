/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_indireg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:54:24 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 13:33:25 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "op.h"

unsigned char	*ft_get_ind(t_ins *ins, unsigned char *curseur, int n_param,
		unsigned char *init)
{
	unsigned char *tmp;

	ins->tab[n_param].type = 3;
	ins->tab[n_param].val_type = 256 * *(curseur) + *(curseur + 1);
	ins->param[n_param] = 256 * *(curseur) + *(curseur + 1);
	tmp = ft_oob(init, curseur + ins->tab[n_param].val_type - ins->size - 2  + 1);
	ins->tab[n_param].val_type = ft_get_int(tmp, 4);
	ins->size = ins->size + 2;
	return(ft_oob(init, curseur + 2));
}

unsigned char	*ft_get_dir(t_ins *ins, unsigned char *curseur, int n_param,
		unsigned char *init)
{
	if(ft_strcmp (ins->name, "ldi") == 0 ||
		ft_strcmp (ins->name, "sti") == 0 ||
		ft_strcmp (ins->name, "lldi") == 0 ||
		ft_strcmp (ins->name, " ") == 0 ||
		ft_strcmp (ins->name, " ") == 0)
	{
		ins->size = ins->size + 2;
		ins->param[n_param] = 256 * *(curseur) + *(curseur + 1);
		ins->tab[n_param].val_type = ins->param[n_param];
		ins->tab[n_param].type = 2;
		if (ins->tab[n_param].val_type	> 32768)
			ins->tab[n_param].val_type -= 65536;
		return (ft_oob(init, curseur + 2));
	}
	else
	{
		ins->param[n_param] = 256 * 256 * 256 * *(curseur) +
			256 * 256 * *(curseur + 1) + 256 * *(curseur + 2)
			+ *(curseur + 3);
		ins->tab[n_param].val_type = ins->param[n_param];
		ins->size = ins->size + 4;
		return (curseur + 4);
	}
}

unsigned char	*ft_get_reg(t_proc *proc, unsigned char *curseur, int n_param,
		unsigned char *init)
{
	proc->ins->param[n_param] = *curseur;
	if (proc->ins->param[n_param] < REG_NUMBER + 1)
		proc->ins->tab[n_param].val_type = proc->reg[proc->ins->param[n_param]];
	proc->ins->tab[n_param].type = 1;
	proc->ins->size = proc->ins->size + 1;
	return (ft_oob(init, curseur + 1));
}
