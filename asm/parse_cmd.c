/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*check_cmd(char *cmd, int fd, char **line, size_t max_length)
{
	char *temp;

	*line = 0;
	while (!(*line) || empty_line(*line))
	{
		pr_free(*line);
		if (get_next_line(fd, line) != 1)
			print_error(ERR_GNL);
	}
	if (ft_strncmp(cmd, *line, ft_strlen(cmd))
		|| ft_strncmp(*line + ft_strlen(cmd), " \"", 2))//whitespaces instead of space?
		print_error(ERR_INVALID_COMMAND);
	if (ft_strlen(temp = *line + ft_strlen(cmd) + 2) > max_length)
		print_error(ERR_COMMAND_LENGTH);
	return (temp);
}

void	parse_cmd(char *cmd, char *dest, int fd, size_t max_length)
{
	char	*line;
	char	*temp;
	int		end;

	end = 0;
	temp = check_cmd(cmd, fd, &line, max_length);
	while (!end)
	{
		if ((end = !!ft_strchr(temp, '"')))
		{
			if (ft_strchr(ft_strchr(temp, '"') + 1, '"'))
				print_error(ERR_SYNTAX);
			*ft_strchr(temp, '"') = 0;
		}
		if (ft_strlen(dest) + ft_strlen(temp) + !end > max_length)
			print_error(ERR_COMMAND_LENGTH);
		ft_strcpy(dest + ft_strlen(dest), temp);
		if (!end)
			ft_memcpy(dest + ft_strlen(dest), "\n", 2);
		pr_free(line);
		if (!end && get_next_line(fd, &line) != 1)
			print_error(ERR_GNL);
		temp = line;
	}
}
