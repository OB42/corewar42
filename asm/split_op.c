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
	if (str[s] == SEPARATOR_CHAR && (w == 1 || empty_line(str + s)))
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
	char		*t;
	int 		i;
	char 		*s;

	i = 0;
	s = 0;
	t = ft_strrchr(str, SEPARATOR_CHAR);
	if (t && empty_line(t + 1))
		print_error(ERR_SYNTAX);
	while (str[i] && ft_strchr(" \t\n\v\f\r", str[i]))
		i++;
	while (str[i] && ft_strchr(LABEL_CHARS, str[i]))
	{
		if (str[i + 1] == DIRECT_CHAR)
		{
			s = pr_malloc(ft_strlen(str) + 2);
			s[ft_strlen(str) + 1] = 0;
			ft_strncpy(s, str, i++ + 1);
			s[i] = ' ';
			ft_strncpy(s + i + 1, str + i, ft_strlen(str) - i);
			str = s;
			break;
		}
		i++;
	}
	words = 0;
	words = while_blank(str, words, 1, ft_strlen(str));
	pr_free(s);
	return (words);
}
