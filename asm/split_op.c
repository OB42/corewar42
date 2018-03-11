/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 01:53:58 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/08 09:44:25 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	**while_blank(char *str, char **words, int save, int w)
{
	int s;

	s = 0;
	while (str[s] && (str[s] == ' ' || str[s] == '\n' || str[s] == '\t'
	|| str[s] == SEPARATOR_CHAR))
		s++;
	if (save)
		return (while_char(str + s, words, save, w));
	if (str[s])
		return (while_char(str + s, words, save, w));
	words[w] = 0;
	return (words);
}

char	**while_char(char *str, char **words, int save, int w)
{
	int		s;

	s = 0;
	while (str[s] && str[s] != ' ' && str[s] != '\n' && str[s] != '\t'
	&& str[s] != SEPARATOR_CHAR)
		s++;
	if (save)
	{
		if (str[s])
			return (while_blank(str + s, words, save + 1, w));
		words = (char**)pr_malloc(sizeof(char *) * (save + 1) + 1);
		return (while_blank(str + s - w, words, 0, 0));
	}
	if (s)
		words[w++] = (char*)pr_malloc(sizeof(char) * s + 1);
	s = 0;
	while (str[s] && str[s] != ' ' && str[s] != '\n' && str[s] != SEPARATOR_CHAR
			&& str[s] != '\t')
	{
		words[w - 1][s] = str[s];
		s++;
	}
	if (w == 1 && str[s] == SEPARATOR_CHAR)
		print_error(ERR_SYNTAX);
	if (s)
		words[w - 1][s] = '\0';
	if (str[s])
		return (while_blank(str + s, words, save, w));
	words[w] = 0;
	return (words);
}

char	**split_op(char *str)
{
	char		**words;
	char		**t;

	t = ft_strrchr(str, SEPARATOR_CHAR);
	while (t && *t)
	{
		if (!ft_strchr(" \t\n\v\f\r", *t))
			break ;
		t++;
	}
	if (t && !(*t))
		print_error(ERR_SYNTAX);
	words = 0;

	return (while_blank(str, words, 1, ft_strlen(str)));
}
