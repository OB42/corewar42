/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int valid_label(char *label)
{
	while (*label && label[1])
	{
		if (!ft_strchr(LABEL_CHARS, *label))
			print_error(ERR_INVALID_LABEL);
		label++;
	}
	return (1);
}

t_label		*get_label(char *champion, char *name, int type)
{
	return (add_label(champion, name, -1, type,-1, -1));
}

t_label		*new_label(char *name, int location, int spg, int d2)
{
	t_label	*temp;

	temp = pr_malloc(sizeof(t_label));
	temp->location = location;
	temp->spg = spg;
	temp->d2 = d2;
	temp->name = pr_malloc(ft_strlen(name) + 1);
	ft_strcpy(temp->name, name);
	return (temp);
}

t_label		*add_label(char *champion, char *name, int location, int type, int spg, int d2)
{
	static t_labels	labels = {0, 0};
	t_list			*temp;
	t_label			*label;
	t_list			*rep;
	t_label		*sav;

	if (name == -1 && location == -1 && type == -1)
	{
		if (!(labels.to_replace))
			return (0);
		rep = labels.to_replace;
		while (rep)
		{
			if (!(sav = add_label(champion, ((t_label *)(rep->content))->name, -1, 0, -1, -1)))
				print_error("label not found\n");
			if (((t_label *)(rep->content))->d2)
			{
				short y;
				y = sav->spg - ((t_label *)(rep->content))->spg;
				y = endian_swap_16(y);
				ft_memcpy(champion + ((t_label *)(rep->content))->location, &y, sizeof(short));
			}
			else
			{
				int z;
				z = sav->spg - ((t_label *)(rep->content))->spg;
				z = endian_swap_32(z);
				ft_memcpy(champion + ((t_label *)(rep->content))->location, &z, sizeof(int));
			}
			rep = rep->next;
		}
		return (0);
	}
	valid_label(name);
	if (location == -1)
	{
		temp = (type ? (labels.to_replace) : (labels.saved));
		while (temp)
		{
			if (!ft_strcmp(name, ((t_label *)(temp->content))->name))
				return (temp->content);
			temp = temp->next;
		}
	}
	else if (type || !add_label(champion, name, -1, type, -1, -1))
	{
		label = new_label(name, location, spg, d2);
		temp = pr_malloc(sizeof(t_list));
		temp->content = label;
		temp->next = (type ? (labels.to_replace) : (labels.saved));
		type ? (labels.to_replace = temp) : (labels.saved = temp);
		return (temp->content);
	}
	return (0);
}
