/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ERR_USAGE "Usage: ./asm <sourcefile.s>\n"
# define ERR_FILE_READING "Can't read source file\n"
# define ERR_FILE_CREATION "Can't create champion\n"
# define ERR_MALLOC "malloc returned 0\n"
# define ERR_PARSING "Parsing error\n"
# define ERR_GNL "GNL returned 0 or -1\n"
# define ERR_SYNTAX "Syntax error\n"
# define ERR_COMMAND_LENGTH "A command is too long\n"
# define ERR_INVALID_COMMAND "A command is invalid\n"
# define ERR_WRONG_EXTENSION "The filename extension must be .s\n"
# define INPUT_EXTENSION ".s"
# define OUTPUT_EXTENSION ".cor"

void	*pr_malloc(size_t n);
void	pr_free(void *p);
void	print_error(char *err);
#endif
