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
	while (*label)
	{
		if (!ft_strchr(LABEL_CHARS, *label))
			print_error(ERR_INVALID_LABEL);
		label++;
	}
	return (1);
}

t_label		*get_label(char *name)
{
	return (add_label(name, -1));
}

t_label		*add_label(char *name, int location)
{
	static t_list	*labels;
	t_list			*temp;
	t_label			label;

	if (!valid_label(name))
		print_error(ERR_INVALID_LABEL);
	if (location < 0)
	{
		temp = labels;
		while (temp)
		{
			if (!ft_strcmp(name, ((t_label *)temp)->name))
				return (temp->content);
			temp = temp->next;
		}
	}
	else if (!add_label(name, -1))
	{
		label = (t_label){name, location};
		if (!(temp = ft_lstnew(&label, sizeof(t_label))))
			print_error(ERR_MALLOC);
		temp->next = labels;
		return ((labels = temp)->content);
	}
	return (0);
}
