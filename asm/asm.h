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
# define ERR_NBR_PARSING "Invalid character after a number\n"
# define ERR_ARG_TYPE "Wrong arg type\n"
# define ERR_LABEL_NOT_FOUND "Label not found\n"
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
# define ERR_UNKNOWN_OPERATION "Unknown operation\n"
# define ERR_ARG_LEN "Wrong number of arguments\n"
# define ERR_INVALID_LABEL "Invalid label\n"
# define ERR_CHAMPION_SIZE "The champion is too large\n"
# define INPUT_EXTENSION ".s"
# define OUTPUT_EXTENSION ".cor"

typedef struct		s_op
{
	char			*name;
	int				arg_len;
	int				args_type[3];
	char			op_code;
	char			ocp;
	int				print_ocp;//carry?
	int				d2;
}					t_op;

typedef struct		s_label
{
	char			*name;
	short			location;
	short			spg;
}					t_label;

typedef struct		s_labels
{
	t_list			*to_replace;
	t_list			*saved;
}					t_labels;

int			endian_swap_u32(int n);
char		**w_char(char *str, char **words, int save, int w);
char		**split(char *str);
t_label		*get_label(char *champion, char *name, int type);
t_label		*add_label(char *champion, char *name, int location, int type, int spg);
int			parse_op(char **op_arr, header_t *header, char *champion);
char		*check_cmd(char *cmd, int fd, char **line, size_t max_length);
void		parse_cmd(char *cmd, char *dest, int fd, size_t max_length);
void		skip_empty_lines(char **line, int input_fd, int *g);
void		pr_free_char_arr(char **to_free);
int			ft_arrstrlen(char **arr);
int			empty_line(char *str);
void		*pr_malloc(size_t n);
void		pr_free(void *p);
void		print_error(char *err);
char		**split_op(char *str);
char		**while_char(char *str, char **words, int save, int w);
#endif
