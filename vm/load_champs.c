/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:25:55 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/06 16:16:01 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int  get_name(t_champs *champs, int fd)
{
	char	*name;
	char	buf;
	int		s_read;
	int		i;
	int		j;
	int		k;

	if ((name = (char*)malloc(PROG_NAME_LENGTH + 1)) == NULL)
		return (-1);
	i = 0;
	k = 0;
	j = 0;
	while (i < PROG_NAME_LENGTH && (s_read = read(fd, &buf, 1)) > 0)
	{
		if (buf == '"')
			k += 1;
		if (buf != 0 && k == 1 && buf != '"')
		{
			name[j] = buf;
			j += 1;
		}
		i += 1;
	}
	name[j] = 0;
	if (s_read == -1)
		return (-1);
	champs->name = name;
	return (0);
}
static int  get_comment(t_champs *champs, int fd)
{
	char	*comment;
	char	buf;
	int		s_read;
	int		i;
	int		j;
	int		k;

	if ((comment = (char*)malloc(CHAMP_MAX_SIZE + 1)) == NULL)
		return (-1);
	i = 0;
	j = 0;
	k = 0;
	while (i < CHAMP_MAX_SIZE && (s_read = read(fd, &buf, 1)) > 0)
	{
		if (buf == '"')
			k += 1;
		if (buf != 0 && k == 3 && buf != '"')
		{
			comment[j] = buf;
			j += 1;
		}
		i += 1;
	}
	comment[j] = 0;
	if (s_read == -1)
		return (-1);
	champs->comment = comment;
	return (0);
}

int		get_name_comment_champ(t_champs *champ, int *fd)
{
	if ((*fd = open(champ->filename, O_RDONLY)) == -1)
		return (-1);
	get_name(champ, *fd);
	close(*fd);
	if ((*fd = open(champ->filename, O_RDONLY)) == -1)
		return (-1);
	get_comment(champ, *fd);
	return (0);
}

void	place_champs(t_corewar *corewar, int	id)
{
}

int		load_champs(t_corewar *corewar)
{
	int		i;
	int		fd;
	int		buf;
	int		id;

	i = 0;
	id = 1;
	if (get_name_comment_champ(&corewar->champ[id], &fd) == -1)
		return (-1);
	while (id < corewar->nb_champs)
	{
		while (corewar->champ->placed != 1)
		{
			if (corewar->arena_id_champs[i] != 0)
				i += (MEM_SIZE / corewar->nb_champs);
			if (corewar->arena_id_champs[i] == 0)
			{
				place_champs(corewar, id);
				corewar->champ->placed = 1;
			}
		}
		id++;
	}
	return (0);
}
