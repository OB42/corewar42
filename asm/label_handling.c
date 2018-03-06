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

t_label		*get_label(char *name, int type)
{
	return (add_label(name, -1, type));
}

t_label		*new_label(char *name, int location)
{
	t_label	*temp;

	temp = pr_malloc(sizeof(t_label));
	temp->location = location;
	temp->name = pr_malloc(ft_strlen(name) + 1);
	ft_strcpy(temp->name, name);
	return (temp);
}
t_label		*add_label(char *name, int location, int type)
{
	static t_labels	labels = {0, 0};
	t_list			*temp;
	t_label			*label;

	if (!valid_label(name))
		print_error(ERR_INVALID_LABEL);
	if (location < 0)
	{
		temp = (type ? (labels.to_replace) : (labels.saved));
		while (temp)
		{
			if (!ft_strcmp(name, ((t_label *)(temp->content))->name))
				return (temp->content);
			temp = temp->next;
		}
	}
	else if (!add_label(name, -1, type))
	{
		label = new_label(name, location);
		if (!(temp = ft_lstnew(label, sizeof(t_label))))
			print_error(ERR_MALLOC);
		pr_free(label);
		temp->next = (type ? (labels.to_replace) : (labels.saved));
		type ? (labels.to_replace = temp) : (labels.saved = temp);
		return (temp->content);
	}
	return (0);
}
