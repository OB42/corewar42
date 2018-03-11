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

char	*skip_whitespaces(char *s)
{
	while (ft_strchr(" \t\n\v\f\r", *s) && *s)
		s++;
	return (s);
}

void	check_line(char *s)
{
	s = skip_whitespaces(s);
	if (*s && *s != COMMENT_CHAR && *s != COMMENT_CHAR_2)
		print_error(ERR_SYNTAX);
}

void	cmd_buffering(char *dest, char *temp, int fd, char *line)
{
	int g;

	while (1)
	{
		if (ft_strchr(temp, '"'))
		{
			ft_strncpy(dest + ft_strlen(dest), temp,
			ft_strchr(temp, '"') - temp);
			check_line(ft_strchr(temp, '"') + 1);
			pr_free(line);
			break ;
		}
		ft_strcpy(dest + ft_strlen(dest), temp);
		ft_memcpy(dest + ft_strlen(dest), "\n", 2);
		pr_free(line);
		if ((g = get_next_line(fd, &line)) != 1)
			print_error(ERR_GNL);
		temp = line;
	}
}

void	parse_cmd(char *cmd, char *dest, int fd, size_t max_length)
{
	char	*line;
	char	*temp;
	int		g;
	char	**line_arr;

	if ((g = get_next_line(fd, &line)) != 1)
		print_error(ERR_GNL);
	skip_empty_lines(&line, fd, &g);
	if (!(temp = ft_strchr(line, '"')))
		print_error(ERR_INVALID_COMMAND);
	*temp = 0;
	if (ft_arrstrlen(line_arr = split(line)) != 1
	|| ft_strncmp(cmd, line_arr[0], ft_strlen(cmd)))
		print_error(ERR_INVALID_COMMAND);
	pr_free_char_arr(line_arr);
	if (*(temp + 1) == '"')
	{
		pr_free(line);
		return ;
	}
	cmd_buffering(dest, temp + 1, fd, line);
}
