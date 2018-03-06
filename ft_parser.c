/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/06 12:55:56 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_instruc	ft_get_instruc(char *str)
{
	t_ins	instruc;
	char	ocp;

	if (*str > 0 && *str < 17)
		instruc.name = op_tab[*str];
	if (op_tab[*str].ocp == 1)
		ocp = *(str + 1);
	if (ocp & 192)
		
	else if (ocp & 128)

t_instruc	*ft_parser(char *str, int *pc)
{
	if (ft_is_instruc(*str))
		ins = ft_get_instruc(str);
	return (ins);
}
